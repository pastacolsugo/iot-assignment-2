
#include "LampTask.h"
#include <Arduino.h>


#define THl 10
#define T1 1000

LampTask::LampTask(int led, int pir, int photo){
  this->led_pin = led;
  this->pir_pin = pir;
  this->photo_pin = photo;
}

void LampTask::init(int period, Status* state){
  Task::init(period, state);
  led = new Led(led_pin);
  pir = new Pir(pir_pin);
  photo = new Photoresistor(photo_pin);
  //Serial.begin(9600);
}

void LampTask::tick(){
  Serial.println("detected00");
  
  if( (pir->detectedMotion()) ? this->time = millis() : false &&
      photo->getIntensity() < THl &&
      STATUS->matchStatus(Light::OFF) && 
      (STATUS->matchStatus(State::IDLE) || STATUS->matchStatus(State::PREALARM)))
  {
    //Serial.println("detected");
    led->switchOn();
    STATUS->setLamp(Light::ON);

  } else if(STATUS->matchStatus(Light::ON) && 
            (photo->getIntensity() > THl || millis() - time >= T1 ||
            STATUS->matchStatus(State::ALARM) ))
  {
    led->switchOff();
    STATUS->setLamp(Light::OFF);
  }
}
