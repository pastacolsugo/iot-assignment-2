#ifndef __LAMPTASK__
#define __LAMPTASK__

#include <Task.h>
#include <Led.h>
#include <Pir.h>
#include <Photoresistor.h>
#include <Timer.h>

class LampTask: public Task {
  long long time;
  int led_pin;
  int pir_pin;
  int photo_pin;
  Led* led;
  Pir* pir;
  Photoresistor* photo;
  enum { ON, OFF} state;

public:
  LampTask(int led, int pir, int photo);
  void init(int period);
  void tick();
};

#endif