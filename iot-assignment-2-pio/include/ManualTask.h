#ifndef __MANUALTASK__
#define __MANUALTASK__

#include <Button.h>
#include <Potenziometer.h>
#include <Status.h>
#include <Task.h>

class ManualTask : public Task {    
public:
    ManualTask(int button_pin, int pot_pin, Status* state);
    void run();

private:
    Status* status;
    Button* button;
    Potenziometer* potenziometer;
};

#endif