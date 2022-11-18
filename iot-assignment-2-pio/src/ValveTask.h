#ifndef __VALVETASK__
#define __VALVETASK__

#include <Task.h>
#include <Timer.h>
#include <Led.h>
#include <Sonar.h>
#include <Valve.h>

class ValveTask: public Task {

    long long time;
    int ledRed_pin;
    int ledGre_pin;
    int sonar_trigPin;
    int sonar_echoPin;
    int valve_pin;
    Led* redLed;
    Led* greLed;
    Sonar* sonar;
    Valve* valve;

    public:
        ValveTask(int led, int grrenLed, int sonarTrigPin, int sonarEchoPin, int valvePin);
        void init(int period);
        void tick();

};

#endif