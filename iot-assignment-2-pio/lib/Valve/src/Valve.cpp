#include <Arduino.h>
#include <Valve.h>

Valve::Valve(int pin){
    this->pin = pin;
    pinMode(pin, OUTPUT);
    valve.attach(pin);
}

void Valve::setPosition(int pos){
    pos = (pos >= 180) ? 180 : ((pos <= 0) ? 0 : pos);
    valve.write(pos);
}