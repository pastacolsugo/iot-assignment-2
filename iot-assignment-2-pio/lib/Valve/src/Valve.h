#ifndef __VALVE__
#define __VALVE__

#include <ServoTimer2.h>

class Valve{
public:
    Valve(int pin);
    void setPosition(int pos);

private:
    int pin;
    ServoTimer2 valve;
};

#endif