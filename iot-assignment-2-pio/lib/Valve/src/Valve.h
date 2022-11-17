#ifndef __VALVE__
#define __VALVE__

#include <Servo.h>

class Valve{
public:
    Valve(int pin);
    void setPosition(int pos);

private:
    int pin;
    Servo valve;
};

#endif