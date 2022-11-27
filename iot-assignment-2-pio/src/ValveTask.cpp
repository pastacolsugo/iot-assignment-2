#include "ValveTask.h"

ValveTask::ValveTask(int valve_pin, int pot_pin, Status* state) {
  this->valve = new Valve(valve_pin);
  this->pot = new Potenziometer(pot_pin);
  this->status = state;
  Serial.begin(9600);
}

void ValveTask::run() {
  if (status->getState() == State::ALARM) {

    if (status->getValveControl() == Control::MANUAL) {
      
      if(status->getManualControlSource() == ManualControlSource::POT_CONTROL){
        status->setValvePosition(pot->read());
      }else{
        //prende i dati dalla seriale
      }
      valve->setPosition(status->getValvePosition());

    }else{
      
      noInterrupts();
      int position = map(status->getWater(), WATER_LEVEL_2, WATER_LEVEL_MAX, 0, 180);
      status->setValvePosition(position);
      interrupts();
      valve->setPosition(status->getValvePosition());

    }

  }else{

    status->setValvePosition(0);
    noInterrupts();
    valve->setPosition(status->getValvePosition());
    interrupts();

  }
}