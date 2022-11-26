#include "Sonar.h"

#include <Arduino.h>

Sonar::Sonar(int trigPin, int echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float Sonar::getDistance() {
  /* invio impulso */
  digitalWrite(this->trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(this->trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(this->trigPin, LOW);

  /* ricevi l’eco */
  float tUS = pulseIn(this->echoPin, HIGH);
  float t = tUS / 1000.0 / 1000.0 / 2;
  float d = t * vs * 1000; // converti in mm se tieni WLMAX a 1000

  return d;
}