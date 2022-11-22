
#include "BlinkTask.h"

BlinkTask::BlinkTask(int pin, Status* status){
    this->led_pin = pin;
    this->ledOn = false;
    this->status = status;
}

void BlinkTask::init(){
    Task::init(DEFAULT_PERIOD);
    this->blinkLed;
}

void BlinkTask::init(int period){
    Task::init(period);
    this->blinkLed;
}

void BlinkTask::run(){
    
    switch (status->getState()){

    case State::PREALARM:
        if(ledOn){
            blinkLed->switchOff();
        }else {
            blinkLed->switchOn();
        }
        
        break;
    case State::ALARM:
        blinkLed->switchOn();
        ledOn = Light::ON;
        break;
    default:
        blinkLed->switchOff();
        ledOn = Light::OFF;
        break;
    }

}