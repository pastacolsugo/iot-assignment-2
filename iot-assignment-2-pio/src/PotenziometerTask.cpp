#include "PotenziometerTask.h"
#include <Status.h>

PotenziometerTask::PotenziometerTask(int pot_pin, Status* state){
    this->status = state;
    this->pot = new Potenziometer(pot_pin);
}

void PotenziometerTask::run(){

}