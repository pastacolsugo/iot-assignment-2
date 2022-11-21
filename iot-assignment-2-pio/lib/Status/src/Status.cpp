#include "Status.h"

Status::Status(){
    this->lamp = OFF;
    this->state = IDLE;
}

Status::State Status::getState(){
    return this->state;
}

Status::Light Status::getLamp(){
    return this->lamp;
}

void Status::setLamp(Light lv){
    this->lamp = lv;
}

int Status::getWater(){
    return this->waterLevel;
}

bool Status::matchStatus(Status::State st){
    return (getState() == st);
  }


bool Status::matchStatus(Status::Light lg){
    return (getLamp() == lg);
  }
