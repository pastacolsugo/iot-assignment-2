//#include "Parameters.h"
#include "ManualTask.h"

ManualTask::ManualTask(int button_pin, int pot_pin, Status* state){
    this->status = state;
    this->button = new Button(button_pin);
    this->potenziometer = new Potenziometer(pot_pin);
}

void ManualTask::run(){

}