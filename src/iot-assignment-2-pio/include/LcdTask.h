#include <Task.h>
#include <Status.h>
#include <LiquidCrystal_I2C.h> 
#include "Parameters.h"

class LcdTask: public Task{
    private:
        Status* status;
        LiquidCrystal_I2C* lcd;
        void printWater();
        void printValve();
        void printControl();

    public:
        LcdTask(Status* st);
        void run();

};