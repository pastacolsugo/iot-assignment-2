#include <Arduino.h>
#include "Potenziometer.h"

Potenziometer::Potenziometer(int pin){
    this->pin = pin;
    pinMode(pin, INPUT);
}