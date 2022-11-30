#ifndef __POTENZIOMETERTASK__
#define __POTENZIOMETERTASK__

#include <Status.h>
#include <Task.h>
#include <Potentiometer.h>

class PotentiometerTask : public Task{
private:
    Potentiometer* pot;
    Status* status;

public:
    PotentiometerTask(int pot_pin, Status* state);
    void run();
};

#endif