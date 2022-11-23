#ifndef __STOPLIGHTTASK__
#define __STOPLIGHTTASK__

#include <Task.h>
#include <Status.h>
#include <Led.h>

class StoplightTask: public Task{

    private:
        int redled_pin;
        int greenled_pin;
        bool ledOn;
        Led* greenLed;
        Led* redLed;
        Status* status;

    public:
        StoplightTask(int red_pin, int green_pin, Status* status);
        void init(int period);
        void init();
        void run();


};


#endif