#include "PotentiometerTask.h"

PotentiometerTask::PotentiometerTask(int pot_pin, Status* state){
    this->pot = new Potentiometer(pot_pin);
    this->status = state;
}

void PotentiometerTask::run(){
    status->setPotValvePosition(pot->read());
}