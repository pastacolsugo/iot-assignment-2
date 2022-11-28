#include <Arduino.h>
#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin){
    this->pin = pin;
    pinMode(pin, INPUT);
}

int Potentiometer::read(){
    return map(analogRead(this->pin), 0, 1023, 0, 180);
}