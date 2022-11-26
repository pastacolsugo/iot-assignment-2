#include "Potenziometer.h"
#include <Arduino.h>

Potenziometer::Potenziometer(int pin){
    this->pin = pin;
    pinMode(pin, INPUT);
}

int Potenziometer::read(){
    return map(analogRead(this->pin), 0, 1023, 0, 180);
}