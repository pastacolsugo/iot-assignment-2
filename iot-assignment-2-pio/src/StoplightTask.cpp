
#include "Parameters.h"
#include "StoplightTask.h"

StoplightTask::StoplightTask(int red_pin, int green_pin, Status* status) {
  this->redled_pin = red_pin;
  this->greenled_pin = green_pin;
  this->status = status;
}

void StoplightTask::init() { StoplightTask::init(STOPLIGHT_TASK_PERIOD); }

void StoplightTask::init(int period) {
  Task::init(period);
  this->greenLed = new Led(greenled_pin);
  this->redLed = new Led(this->redled_pin);
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