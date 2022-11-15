#include <Arduino.h>
#include "Scheduler.h"
#include "LampTask.h"
#include "ValveTask.h"

#define LA 13
#define LS A0
#define P 2

Scheduler sched;

void setup() {
    sched.init(50); //modified as best
    
    //possono essere aggiunti in un array di task -- opzionale dato che sono solo 2
    Task* lamp = new LampTask(LA, P, LS);
    lamp->init(50);
    sched.addTask(lamp);

    /*
    Task* valve = new ValveTask(...);
    valve->init(...);
    sched.addTask(valve);
    */
}

void loop() {
    sched.schedule();
}
