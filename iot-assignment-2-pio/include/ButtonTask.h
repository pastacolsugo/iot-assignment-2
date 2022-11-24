#ifndef __BUTTONTASK__
#define __BUTTONTASK__

#include <Button.h>
//#include <Potenziometer.h>
#include <Status.h>
#include <Task.h>

class ButtonTask : public Task {    
public:
    ButtonTask(int button_pin, Status* state);
    void run();

private:
    Status* status;
    Button* button;
};

#endif