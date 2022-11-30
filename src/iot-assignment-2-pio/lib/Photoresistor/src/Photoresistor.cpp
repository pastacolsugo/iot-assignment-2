#include <Arduino.h>
#include "Photoresistor.h"

Photoresistor::Photoresistor(int pin) {
  this->pin = pin;
  pinMode(pin, INPUT);
}

int Photoresistor::getIntensity() { return analogRead(pin); }