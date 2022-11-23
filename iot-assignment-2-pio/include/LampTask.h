#ifndef __LAMPTASK__
#define __LAMPTASK__

#include <Arduino.h>
#include <Task.h>
#include <Status.h>
#include <Led.h>
#include <Pir.h>
#include <Photoresistor.h>

class LampTask : public Task {
 private:
  long long time;
  int led_pin;
  int pir_pin;
  int photo_pin;
  Status* status;
  Led* led;
  Pir* pir;
  Photoresistor* photo;

 public:
  LampTask(int led, int pir, int photo, Status* state);
  void init(int period);
  void run();
};

#endif