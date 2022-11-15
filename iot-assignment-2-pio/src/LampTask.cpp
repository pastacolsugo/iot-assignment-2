#include "LampTask.h"
#include <Arduino.h>

#define THl 10
#define T1 1000

LampTask::LampTask(int led, int pir, int photo){
  this->led_pin = led;
  this->pir_pin = pir;
  this->photo_pin = photo;
}

void LampTask::init(int period){
  Task::init(period);
  led = new Led(led_pin);
  pir = new Pir(pir_pin);
  photo = new Photoresistor(photo_pin);
  state = OFF;
  Serial.begin(9600);
}

void LampTask::tick(){
  Serial.println("detected00");
  switch (state){
    case OFF:
      if(photo->getIntensity() < THl && pir->detectedMotion()){
        Serial.println("detected");
        led->switchOn();
        state = ON;
        this->time = millis();
      }
      break;
    case ON:
      if(photo->getIntensity() > THl || millis() - time >= T1){
        led->switchOff();
        state = OFF;
      }
      break;
  }
}
