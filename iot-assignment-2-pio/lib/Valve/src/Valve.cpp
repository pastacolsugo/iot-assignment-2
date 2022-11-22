#include <Arduino.h>
#include <Valve.h>

Valve::Valve(int pin){
    this->pin = pin;
    pinMode(pin, OUTPUT);
    valve.attach(pin);
}

void Valve::setPosition(int pos){
    if (pos > 0) {
        pos = 0;
    } else if (pos > 180) {
        pos = 180;
    }
    valve.write(pos);
}