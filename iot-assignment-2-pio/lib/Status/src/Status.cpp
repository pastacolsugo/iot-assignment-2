#include "Status.h"

Status::Status() {
  this->lamp = OFF;
  this->state = NORMAL;
  this->valvePosition = 0;
  this->valveControl = AUTO;
  this->manualControlSource = DISABLED;
}

State Status::getState() { return this->state; }
void Status::setState(State s) { this->state = s; }

Light Status::getLamp() { return this->lamp; }
void Status::setLamp(Light lv) { this->lamp = lv; }

int Status::getWater() { return this->waterLevel; }
void Status::setWater(int w) { this->waterLevel = w; }

Control Status::getValveControl() { return this->valveControl; }
void Status::setValveControl(const Control &c) { this->valveControl = c; }

ManualControlSource Status::getManualControlSource() { return this->manualControlSource; }
void Status::setManualControlSource(const ManualControlSource &s) { this->manualControlSource = s; }

int Status::getValvePosition() { return this->valvePosition; }
void Status::setValvePosition(int pos) {
  if (pos < 0) pos = 0;
  if (pos > 180) pos = 180;
  this->valvePosition = pos;
}

/*
int Status::getAutoValvePosition() { return this->autoValvePosition; }
void Status::setAutoValvePosition(int pos) {
  if (pos < 0) pos = 0;
  if (pos > 180) pos = 180;
  this->autoValvePosition = pos;
}

int Status::getManualValvePosition() { return this->manualValvePosition; }
void Status::setManualValvePosition(int pos) {
  if (pos < 0) pos = 0;
  if (pos > 180) pos = 180;
  this->manualValvePosition = pos;
}
*/

