#include "ValveTask.h"

ValveTask::ValveTask(int valve_pin, Status* state) {
  this->valve = new Valve(valve_pin);
  this->status = state;
}

void ValveTask::run() {
  if (status->getState() == State::ALARM) {
    if (status->getValveControl() == Control::MANUAL) {
      valve->setPosition(status->getManualValvePosition());
      return;
    }
    
    int position = map(status->getWater(), WL2, BH, 0, 180);
    valve->setPosition(position);
    status->setValvePosition(position);
    return;
  } 

  status->setAutoValvePosition(0);
  valve->setPosition(0);
  return;
}