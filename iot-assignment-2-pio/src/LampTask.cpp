
#include "LampTask.h"

#define THL 10
#define T1 1000

LampTask::LampTask(int led, int pir, int photo, Status* state) {
  this->led_pin = led;
  this->pir_pin = pir;
  this->photo_pin = photo;
  this->status = state;
}

void LampTask::init(int period) {
  Task::init(period);
  led = new Led(led_pin);
  pir = new Pir(pir_pin);
  photo = new Photoresistor(photo_pin);
}

void LampTask::run() {
  bool isMotionDetected = pir->detectedMotion();
  auto lightIntensity = photo->getIntensity();
  long long time_now = millis();

  if (isMotionDetected) {
    this->timeOfLastDetectedMovement = time_now;
  }

  if (status->getState() == State::ALARM) {
    turnOff();
    return;
  }

  if (lightIntensity > THL) {
    turnOff();
    return;
  }

  if (time_now - timeOfLastDetectedMovement >= T1) {
    turnOff();
    return;
  }

  turnOn();
  return;
}
