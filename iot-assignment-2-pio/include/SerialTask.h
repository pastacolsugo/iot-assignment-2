#ifndef __VALVETASK__
#define __VALVETASK__

#include <Task.h>
#include <Status.h>
#include <Arduino.h>

class SerialTask: public Task{
    private:
        Status* status;

        const char * generateStateMessage();
        String generateConrolMessage();
        String generateWaterMessage();
        String generateValvePositionMessage();

        void toSerial();
        void fromSerial();

    public:
        SerialTask(Status st);
        void run();


};

#endif