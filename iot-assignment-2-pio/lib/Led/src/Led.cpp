#include <Arduino.h>
#include <Led.h>

#define BlinkTime 1000

Led::Led(int pin) {
  this->pin = pin;
  pinMode(pin, OUTPUT);
}

void Led::switchOn() { digitalWrite(pin, HIGH); }

void Led::switchOff() { digitalWrite(pin, LOW); }

void Led::toggle() { digitalWrite(pin, !digitalRead(pin)); }