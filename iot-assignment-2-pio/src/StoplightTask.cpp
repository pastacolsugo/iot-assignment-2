#include <Arduino.h>
#include "StoplightTask.h"

StoplightTask::StoplightTask(int red_pin, int green_pin, Status* status) {
  this->redLed = new Led(red_pin);
  this->greenLed = new Led(green_pin);
  this->status = status;
  this->time = millis();
}

void StoplightTask::run() {
  switch (status->getState()) {
    case State::PREALARM:
      greenLed->switchOn(); //non specificato nel testo come settare il greenLed
      if(millis() - time > TOGGLE_PERIOD){    //con un periodo di 2 secondi
        redLed->toggle();
        time = millis();  
      }
      break;

    case State::ALARM:
      greenLed->switchOff();
      redLed->switchOn();
      break;

    default:
      greenLed->switchOn();
      redLed->switchOff();
  }
}