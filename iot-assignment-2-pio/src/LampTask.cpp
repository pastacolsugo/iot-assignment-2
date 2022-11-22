
#include "LampTask.h"

#include <Arduino.h>

#define THl 10
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
  Serial.println("detected00");

  bool isMotionDetected = pir->detectedMotion();
  auto lightIntensity = photo->getIntensity();

  if (isMotionDetected) {
    this->time = millis();
  }
  if (isMotionDetected and lightIntensity < THl and
      status == Light::OFF and
      (status->matchStateStatus(State::NORMAL) or
       status->matchStateStatus(State::PREALARM))) {

       }

    if ((pir->detectedMotion() ? this->time = millis() : false) &&
        lightIntensity < THl && status->matchLampStatus(Light::OFF) &&
        (status->matchStateStatus(State::NORMAL) ||
         status->matchStateStatus(State::PREALARM))) {
      // Serial.println("detected");
      led->switchOn();
      status->setLamp(Light::ON);

    } else if (status->matchLampStatus(Light::ON) &&
               (lightIntensity > THl || millis() - time >= T1 ||
                status->matchStateStatus(State::ALARM))) {
      led->switchOff();
      status->setLamp(Light::OFF);
    }
}
