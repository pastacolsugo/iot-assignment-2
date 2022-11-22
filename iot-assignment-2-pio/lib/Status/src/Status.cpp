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

bool Status::matchStatus(State st){
    return (getState() == st);
  }


bool Status::matchStatus(Light lg){
    return (getLamp() == lg);
  }
