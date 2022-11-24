#ifndef __VALVETASK__
#define __VALVETASK__

#include <Arduino.h>
#include <Status.h>
#include <Task.h>
#include <Valve.h>

class ValveTask : public Task {
  Valve* valve;
  Status* status;

 public:
  ValveTask(int valve_pin, Status* state);
  void init(int period);
  void run();
};

#endif