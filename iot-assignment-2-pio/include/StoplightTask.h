#ifndef __STOPLIGHTTASK__
#define __STOPLIGHTTASK__

#include <Led.h>
#include <Status.h>
#include <Task.h>

class StoplightTask : public Task {
 private:
  int redled_pin;
  int greenled_pin;
  Led* greenLed;
  Led* redLed;
  Status* status;

 public:
  StoplightTask(int red_pin, int green_pin, Status* status);
  void run();
};

#endif