#ifndef __POTENZIOMETERTASK__
#define __POTENZIOMETERTASK__

#include <Status.h>
#include <Task.h>
#include <Potenziometer.h>

class PotenziometerTask : public Task {    
public:
    PotenziometerTask(int pot_pin, Status* state);
    void run();

private:
    Status* status;
    Potenziometer* pot;
};

#endif