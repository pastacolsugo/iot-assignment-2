#ifndef __LAMPTASK__
#define __LAMPTASK__

#include <Arduino.h>
#include <Led.h>
#include <Photoresistor.h>
#include <Pir.h>
#include <Status.h>
#include <Task.h>

class LampTask : public Task {
 public:
  LampTask(int led, int pir, int photo, Status* state);
  void init(int period);
  void run();

 private:
  long long timeOfLastDetectedMovement;
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