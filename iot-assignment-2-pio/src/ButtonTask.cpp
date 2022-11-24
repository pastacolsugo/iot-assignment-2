#include "ButtonTask.h"
#include <Status.h>

ButtonTask::ButtonTask(int button_pin, Status* state){
    this->status = state;
    this->button = new Button(button_pin);
}

void ButtonTask::run(){
    if(button->isPressed()){
        status->setValveControl( status->getValveControl() == Control::AUTO ? Control::MANUAL : Control::AUTO );
    }
}