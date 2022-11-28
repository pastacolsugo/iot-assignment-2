#ifndef __VALVETASK__
#define __VALVETASK__

#include <Arduino.h>
#include <Status.h>
#include <Task.h>
#include <Valve.h>
#include <Potentiometer.h>
#include "Parameters.h"

class ValveTask : public Task {
  Valve* valve;
  Potentiometer* pot;
  Status* status;

 public:
  ValveTask(int valve_pin, int pot_pin, Status* state);
  void run();
};

#endif