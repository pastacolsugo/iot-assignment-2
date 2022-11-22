 
#include <Arduino.h>
#include "ValveTask.h"

#define WL1 100
#define WL2 300
#define BH 1000

#define PEN 50
#define PEP 30
#define PEA 10

ValveTask::ValveTask(int valvePin, Status* state){
    this->valve_pin = valvePin;
    this->status = state;
}

void ValveTask::init(int period){
    Task::init(period);
    valve = new Valve(this->valve_pin);
}

void ValveTask::tick(){

    if( status->matchStatus(State::ALARM) )
    {
        valve->setPosition(map(status->getWater(), WL2, BH, 0, 180));
    }

}