#include <Arduino.h>
#include <Led.h>

#define BlinkTime 1000

Led::Led(int pin) {
  this->pin = pin;
  pinMode(pin, OUTPUT);
}

void Led::switchOn() { digitalWrite(pin, HIGH); }

void Led::switchOff() { digitalWrite(pin, LOW); };

void Led::blink() {
  if (millis() - this->t >= BlinkTime) {
    this->t = millis();
    digitalWrite(this->pin, !digitalRead(this->pin));
  }
}