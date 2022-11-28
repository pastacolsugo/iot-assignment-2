#ifndef __LAMPTASK__
#define __LAMPTASK__

#include <Led.h>
#include <Photoresistor.h>
#include <Pir.h>
#include <Status.h>
#include <Task.h>
#include "Parameters.h"

class LampTask : public Task {
 public:
  LampTask(int led, int pir, int photo, Status* state);
  void run();

 private:
  unsigned long timeOfLastDetectedMovement = 0;
  Status* status;
  Led* led;
  Pir* pir;
  Photoresistor* photo;

  void turnOff() {
    led->switchOff();
    status->setLamp(Light::OFF);
    return;
  }

  void turnOn() {
    led->switchOn();
    status->setLamp(Light::ON);
    return;
  }
};

#endif