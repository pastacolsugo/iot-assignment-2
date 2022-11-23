
#include "StoplightTask.h"

#define PERIOD_TASK 1000

StoplightTask::StoplightTask(int red_pin, int green_pin, Status* status){
    this->redled_pin = red_pin;
    this->greenled_pin = green_pin;
    this->ledOn = false;
    this->status = status;
}

void StoplightTask::init(){
    StoplightTask::init(PERIOD_TASK);
}

void StoplightTask::init(int period){
    Task::init(period);
    this->greenLed = new Led(greenled_pin);
    this->redLed = new Led(this->redled_pin);
}

void StoplightTask::run(){
    
    switch (status->getState()){

    case State::PREALARM:
        greenLed->switchOn();
        if(ledOn){
            redLed->switchOff();
            ledOn = false;
        }else {
            redLed->switchOn();
            ledOn = true;
        }
        break;

    case State::ALARM:
        greenLed->switchOff();
        redLed->switchOn();
        ledOn = true;
        break;

    default:
        greenLed->switchOn();
        redLed->switchOff();
        ledOn = false;
        break;
    }

}