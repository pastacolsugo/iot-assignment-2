#include "LampTask.h"
#include <Arduino.h>

LampTask::LampTask(int led_pin, int pir_pin, int photo_pin, Status* state) {
  this->status = state;
  this->led = new Led(led_pin);
  this->pir = new Pir(pir_pin);
  this->photo = new Photoresistor(photo_pin);
  //Serial.begin(9600);
}

void LampTask::run() {
  bool isMotionDetected = pir->detectedMotion();
  auto lightIntensity = photo->getIntensity();
  //Serial.println(lightIntensity);
  unsigned long time_now = millis();

  if (isMotionDetected) {
    this->timeOfLastDetectedMovement = time_now;
    //Serial.println("detectedMotion");
  }

  if (status->getState() == State::ALARM      ||
      lightIntensity > LIGHT_THRESHOLD__LEVEL ||
      time_now - timeOfLastDetectedMovement >= LAMP_TIMEOUT
  ) {
    turnOff();
  }else{
    turnOn();
  }
}
