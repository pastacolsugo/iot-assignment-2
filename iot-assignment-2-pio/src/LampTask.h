#ifndef __LAMPTASK__
#define __LAMPTASK__

#include <Led.h>
#include <Photoresistor.h>
#include <Pir.h>
#include <Task.h>
#include <Timer.h>

class LampTask : public Task {
 private:
  long long time;
  int led_pin;
  int pir_pin;
  int photo_pin;
  Led* led;
  Pir* pir;
  Photoresistor* photo;
  Status* status;

 public:
  LampTask(int led, int pir, int photo, Status* state);
  void init(int period);
  void run();
};

#endif