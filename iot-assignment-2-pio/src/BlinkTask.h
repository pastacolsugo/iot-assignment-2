#ifndef __BLINKTASK__
#define __BLINKTASK__

#include <Task.h>
#include <Led.h>

#define DEFAULT_PERIOD 1000

class BlinkTask: public Task{

    private:
        int led_pin;
        bool ledOn;
        Led* blinkLed;
        Status* status;

    public:
        BlinkTask(int pin, Status* status);
        void init(int period);
        void init();
        void run();


};


#endif