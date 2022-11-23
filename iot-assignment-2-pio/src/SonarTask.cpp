
#include <SonarTask.h>

#define WL1 100
#define WL2 300
#define WLMAX 1000

#define PERIOD_TASK_NORMAL 50
#define PERIOD_TASK_PREALARM 30
#define PERIOD_TASK_ALARM 10

SonarTask::SonarTask(int trig, int echo, Status* state) {
  this->echo_pin = echo;
  this->trig_pin = trig;
  this->status = state;
}

void SonarTask::init(){
  SonarTask::init(PERIOD_TASK_NORMAL);
}

void SonarTask::init(int period) {
  Task::init(period);
  this->sonar = new Sonar(trig_pin, echo_pin);
}

void SonarTask::tick() {
  int tmp = sonar->getDistance();
  tmp = (WLMAX < tmp) ? WLMAX : WLMAX - tmp;
  status->setWater(tmp);

  if (tmp > WL2) {
    status->setState(State::ALARM);
    setPeriod(PERIOD_TASK_ALARM);
  } else if (tmp > WL1) {
    status->setState(State::PREALARM);
    setPeriod(PERIOD_TASK_PREALARM);
  } else {
    status->setState(State::NORMAL);
    setPeriod(PERIOD_TASK_NORMAL);
  }
}