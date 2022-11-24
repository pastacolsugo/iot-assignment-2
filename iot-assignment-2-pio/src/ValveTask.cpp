#include "ValveTask.h"

#include <Parameters.h>

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

    int position =
        map(status->getWater(), WATER_LEVEL_2, WATER_LEVEL_MAX, 0, 180);
    valve->setPosition(position);
    status->setValvePosition(position);
    return;
  }

  status->setAutoValvePosition(0);
  valve->setPosition(0);
  return;
}