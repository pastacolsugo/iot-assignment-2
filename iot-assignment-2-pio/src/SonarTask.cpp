#include <SonarTask.h>

#define WL1 100
#define WL2 300
#define WLMAX 1000

#define PERIOD_TASK_NORMAL 50
#define PERIOD_TASK_PREALARM 30
#define PERIOD_TASK_ALARM 10

SonarTask::SonarTask(int trig_pin, int echo_pin, Status* state) {
  this->echo_pin = echo_pin;
  this->trig_pin = trig_pin;
  this->status = state;
}

void SonarTask::init() { SonarTask::init(PERIOD_TASK_NORMAL); }

void SonarTask::init(int period) {
  Task::init(period);
  this->sonar = new Sonar(trig_pin, echo_pin);
}

void SonarTask::tick() {
  int sonarReading = sonar->getDistance();
  int waterLevel = (WLMAX < sonarReading) ? WLMAX : WLMAX - sonarReading;
  status->setWater(waterLevel);

  if (waterLevel > WL2) {
    status->setState(State::ALARM);
    setPeriod(PERIOD_TASK_ALARM);
    return;
  }

  if (waterLevel > WL1) {
    status->setState(State::PREALARM);
    setPeriod(PERIOD_TASK_PREALARM);
    return;
  }

  status->setState(State::NORMAL);
  setPeriod(PERIOD_TASK_NORMAL);
}