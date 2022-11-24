
#include "Parameters.h"
#include "ValveTask.h"

ValveTask::ValveTask(int valve_pin, Status* state) {
  this->valve = new Valve(valve_pin);
  this->status = state;
}

void ValveTask::run() {
  if (status->matchStateStatus(State::ALARM)) {
    valve->setPosition(map(status->getWater(), WATER_LEVEL_2, WATER_LEVEL_MAX, 0, 180));

  } else if (status->matchValveStatus(Control::MANUAL)) {
    valve->setPosition(180);
    // COME ELABORO LA SERIALE? FACCIO LA LETTURA QUA o SALVO
    // VARIABILE IN STATO? O ELABORO IN TASKMANUAL?
  }
}