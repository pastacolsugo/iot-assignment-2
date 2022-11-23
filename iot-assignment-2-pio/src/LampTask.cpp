
#include "Parameters.h"
#include "LampTask.h"

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
