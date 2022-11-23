#include <Task.h>
#include <Status.h>
#include <Parameters.h>
#include <LiquidCrystal_I2C.h> 

class LcdTask: public Task{
    private:
        Status* status;
        LiquidCrystal_I2C* lcd;
;

    public:
        LcdTask(Status* st);
        void init();
        void run();

};