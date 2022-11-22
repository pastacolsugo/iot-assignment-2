#ifndef __LAMPTASK__
#define __LAMPTASK__

#include <Task.h>
#include <Timer.h>
#include <Led.h>
#include <Pir.h>
#include <Photoresistor.h>

class LampTask: public Task {

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
  void tick();
};

#endif