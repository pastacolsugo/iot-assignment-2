#ifndef __VALVETASK__
#define __VALVETASK__

#include <Led.h>
#include <Sonar.h>
#include <Task.h>
#include <Timer.h>
#include <Valve.h>

class ValveTask : public Task {
  int valve_pin;
  Valve* valve;
  Status* status;

 public:
  ValveTask(int valvePin, Status* state);
  void init(int period);
  void tick();
};

#endif