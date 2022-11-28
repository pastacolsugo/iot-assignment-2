#include <Arduino.h>
#include "Valve.h"

Valve::Valve(int pin) {
  this->pin = pin;
  valve.attach(pin);
}

void Valve::setPosition(int pos) {
  //controllo di pos gia fatto nella setValvePosition
  valve.write(pos);
  delay(15);
}