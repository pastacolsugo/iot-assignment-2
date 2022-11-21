 
#include <Arduino.h>
#include "ValveTask.h"

#define WL1 100
#define WL2 300
#define BH 1000

#define PEN 50
#define PEP 30
#define PEA 10

ValveTask::ValveTask(int led, int greenLed, int sonarTrigPin, int sonarEchoPin, int valvePin){
    this->valve_pin = valvePin;
}

void ValveTask::init(int period, Status* state){
    Task::init(period, state);
    valve = new Valve(this->valve_pin);
}

void ValveTask::tick(){

    if( STATUS->matchStatus(Status::State::ALARM) )
    {
        valve->setPosition(map(STATUS->getWater(), WL2, BH, 0, 180));
    }

}