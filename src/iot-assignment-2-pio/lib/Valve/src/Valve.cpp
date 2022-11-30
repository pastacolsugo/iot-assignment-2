#include <Arduino.h>
#include "Valve.h"

Valve::Valve(int pin) {
  this->pin = pin;
  valve.attach(pin);
}

void Valve::setPosition(int pos) {
  float coef = ((float)MAX_PULSE_WIDTH - (float)MIN_PULSE_WIDTH) / 180;
  valve.write(MIN_PULSE_WIDTH + pos*coef);
}