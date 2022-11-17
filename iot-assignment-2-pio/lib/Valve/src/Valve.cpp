#include <Arduino.h>
#include <Valve.h>

Valve::Valve(int pin){
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void Valve::setPosition(int pos){
    valve.attach(pin);
    pos = (pos >= 180) ? 180 : ((pos <= 0) ? 0 : pos);
    valve.write(pos);
    valve.detach();
}