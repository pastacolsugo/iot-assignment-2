#ifndef __LAMPTASK__
#define __LAMPTASK__

#include "Task.h"
#include "Led.h"
#include "Pir.h"
#include "Photoresistor.h"

class LampTask: public Task {
  int led_pin;
  int pir_pin;
  int photo_pin;
  Light* led;
  Pir* pir;
  Photoresistor* photo;
  enum { ON, OFF} state;

public:
  LampTask(int led, int pir, int photo);
  void init(int period);
  void tick();
};

#endif