#include "Status.h"

Status::Status(){
    this->lamp = OFF;
    this->state = IDLE;
}

State Status::getState(){
    return this->state;
}

Light Status::getLamp(){
    return this->lamp;
}

void Status::setLamp(Light lv){
    this->lamp = lv;
}

int Status::getWater(){
    return this->waterLevel;
}

bool Status::matchStateStatus(State st){
    return (this->state == st);
}

bool Status::matchLampStatus(Light lg){
    return (this->lamp == lg);
}

bool Status::matchValveStatus(Control vl){
    return (this->valve == vl);
}
