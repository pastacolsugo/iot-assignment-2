
#include "Parameters.h"
#include "LampTask.h"

LampTask::LampTask(int led_pin, int pir_pin, int photo_pin, Status* state) {
  this->status = state;
  this->led = new Led(led_pin);
  this->pir = new Pir(pir_pin);
  this->photo = new Photoresistor(photo_pin);
}

void LampTask::run() {
  bool isMotionDetected = pir->detectedMotion();
  auto lightIntensity = photo->getIntensity();
  unsigned long time_now = millis();

  if (isMotionDetected) {
    this->timeOfLastDetectedMovement = time_now;
  }

  if (status->getState() == State::ALARM) {
    turnOff();
    return;
  }

  if (lightIntensity > LIGHT_THRESHOLD__LEVEL) {
    turnOff();
    return;
  }

  if (time_now - timeOfLastDetectedMovement >= LAMP_TIMEOUT) {
    turnOff();
    return;
  }

  turnOn();
  return;
}
