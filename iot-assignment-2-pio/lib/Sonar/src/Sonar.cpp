#include <Arduino.h>
#include "Sonar.h"

Sonar::Sonar(int trigPin, int echoPin){
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float Sonar::getDistance(){

    /* invio impulso */
    digitalWrite(this->trigPin,LOW);
    delayMicroseconds(3);
    digitalWrite(this->trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(this->trigPin,LOW);
    
    /* ricevi l’eco */
    long tUS = pulseInLong(this->echoPin, HIGH);
    double t = tUS / 1000.0 / 1000.0 / 2;
    double d = t * vs;

    return d;
}