
#include <SonarTask.h>

#define WL1 100
#define WL2 300
#define WLMAX 1000

SonarTask::SonarTask(int trig, int echo, Status* state) {
  this->echo_pin = echo;
  this->trig_pin = trig;
  this->status = state;
}

void SonarTask::init(int period) {
  Task::init(period);
  this->sonar = new Sonar(trig_pin, echo_pin);
}

void SonarTask::tick() {
  int tmp = sonar->getDistance();
  tmp = (WLMAX < tmp) ? WLMAX : WLMAX - tmp;
  status->setWater(tmp);

  // Controllo forse errato...lo stato dovrebeb cambiare anche se sono in
  // manuale. if(status->matchValveStatus(Control::AUTO)){}

  if (tmp > WL2) {
    status->setState(State::ALARM);
  } else if (tmp > WL1) {
    status->setState(State::PREALARM);
  } else {
    status->setState(State::IDLE);
  }
}