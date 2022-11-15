#include "LampTask.h"

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
}

void LampTask::tick(){
  /*TODO:*/
  switch (state){
    case OFF:
      led->switchOn();
      state = ON;
      break;
    case ON:
      led->switchOff();
      state = OFF;
      break;
  }
}
