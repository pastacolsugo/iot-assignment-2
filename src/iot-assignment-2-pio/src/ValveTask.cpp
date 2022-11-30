#include "ValveTask.h"

ValveTask::ValveTask(int valve_pin, Status* state) {
  this->valve = new Valve(valve_pin);
  this->status = state;
  this->valve->setPosition(0);
}

void ValveTask::run() {
  if (status->getValveControl() == Control::MANUAL) {
    if (status->getManualControlSource() == ManualControlSource::POT_CONTROL) {
      status->setValvePositionFromPotValvePosition();
    }
    if (status->getManualControlSource() == ManualControlSource::SERIAL_CONTROL) {
      status->setValvePositionFromSerialValvePosition();
    }

  } else if (status->getState() == State::ALARM) {
    int position =
        map(status->getWater(), WATER_LEVEL_2, WATER_LEVEL_MAX, 0, 180);
    status->setValvePosition(position);

  } else {
    status->setValvePosition(0);
  }
    valve->setPosition(status->getValvePosition());
}