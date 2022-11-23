#include "Parameters.h"
#include "SonarTask.h"

SonarTask::SonarTask(int trig_pin, int echo_pin, Status* state) {
  this->echo_pin = echo_pin;
  this->trig_pin = trig_pin;
  this->status = state;
}

void SonarTask::init() { SonarTask::init(SONAR_TASK_PERIOD_NORMAL); }

void SonarTask::init(int period) {
  Task::init(period);
  this->sonar = new Sonar(trig_pin, echo_pin);
}

void SonarTask::run() {
  int sonarReading = sonar->getDistance();
  int waterLevel = (WATER_LEVEL_MAX < sonarReading) ? WATER_LEVEL_MAX : WATER_LEVEL_MAX - sonarReading;
  status->setWater(waterLevel);

  if (waterLevel > WATER_LEVEL_2) {
    status->setState(State::ALARM);
    setPeriod(SONAR_TASK_PERIOD_ALARM);
    return;
  }

  if (waterLevel > WATER_LEVEL_1) {
    status->setState(State::PREALARM);
    setPeriod(SONAR_TASK_PERIOD_PREALARM);
    return;
  }

  status->setState(State::NORMAL);
  setPeriod(SONAR_TASK_PERIOD_NORMAL);
}