
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
  Serial.begin(9600);
}

void LampTask::tick(){
  Serial.println("detected00");
  
  if((pir->detectedMotion()) ? this->time = millis() : false && (photo->getIntensity() < THl))
  {
    // accende continuamente il led... che ce ne frega...volendo si aggiunge un controllo sullo stato
    Serial.println("detected");
    led->switchOn();

  } else if(photo->getIntensity() > THl || millis() - time >= T1){
    // Come sopra
    led->switchOff();
  }
}
