
#include "Parameters.h"
#include "StoplightTask.h"

StoplightTask::StoplightTask(int red_pin, int green_pin, Status* status) {
  this->redLed = new Led(red_pin);
  this->greenLed = new Led(green_pin);
  this->status = status;
}

void StoplightTask::run() {
  switch (status->getState()) {
    case State::PREALARM:
      greenLed->switchOn();
      redLed->toggle();
      return;

    case State::ALARM:
      greenLed->switchOff();
      redLed->switchOn();
      return;

    default:
      greenLed->switchOn();
      redLed->switchOff();
      return;
  }
}