#ifndef __SERIALTASK__
#define __SERIALTASK__

#include <Task.h>
#include <Parameters.h>
#include <Status.h>
#include <Arduino.h>

class SerialTask: public Task{
    private:
        Status* status;

        void sendStateMessage();
        void sendLampMessage();
        void sendWaterMessage();
        void sendControlMessage();
        void sendValvePositionMessage();
        void sendManualControlSourceMessage();
        void sendTerminateMessage();

        void updateStatusFromMessage(char * mess);

        void send();
        void read();

    public:
        SerialTask(Status* st);
        void run();


};

#endif