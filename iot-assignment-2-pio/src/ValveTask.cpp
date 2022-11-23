
#include "ValveTask.h"

#define WL1 100
#define WL2 300
#define BH 1000

ValveTask::ValveTask(int valvePin, Status* state) {
  this->valve_pin = valvePin;
  this->status = state;
}

void ValveTask::init(int period) {
  Task::init(period);
  valve = new Valve(this->valve_pin);
}

void ValveTask::run() {
  if (status->matchStateStatus(State::ALARM)) {
    valve->setPosition(map(status->getWater(), WL2, BH, 0, 180));

  } else if (status->matchValveStatus(Control::MANUAL)) {
    valve->setPosition(180);
    // COME ELABORO LA SERIALE? FACCIO LA LETTURA QUA o SALVO
    // VARIABILE IN STATO? O ELABORO IN TASKMANUAL?
  }
}