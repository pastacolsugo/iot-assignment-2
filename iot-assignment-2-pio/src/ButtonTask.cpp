//#include "Parameters.h"
#include "ButtonTask.h"
#include <Status.h>

ButtonTask::ButtonTask(int button_pin, int pot_pin, Status* state){
    this->status = state;
    this->button = new Button(button_pin);
    //this->potenziometer = new Potenziometer(pot_pin);
}

void ButtonTask::run(){
    if(button->isPressed() && status->getState() == Control::AUTO){
        status->setState(Control::MANUAL);
    }else if(button->isPressed() && status->getState() == Control::MANUAL){

    }
}