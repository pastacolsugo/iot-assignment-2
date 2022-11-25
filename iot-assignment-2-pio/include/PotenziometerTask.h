#ifndef __POTENZIOMETERTASK__
#define __POTENZIOMETERTASK__

#include <Status.h>
#include <Task.h>

class ButtonTask : public Task {    
public:
    ButtonTask(int pot_pin, Status* state);
    void run();

private:
    Status* status;
    //Potenziometer* pot;
};

#endif