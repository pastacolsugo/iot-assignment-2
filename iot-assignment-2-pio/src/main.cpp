#include <Arduino.h>

#include "LampTask.h"
#include "Scheduler.h"
#include "Status.h"
#include "ValveTask.h"

#define LA 13
#define LS A0
#define P 2

Scheduler scheduler;

void setup() {
  scheduler.init(50);  // Period to be adjusted 

  Status* status = new Status();

  // possono essere aggiunti in un array di task -- opzionale dato che sono solo
  // 2
  Task* lamp = new LampTask(LA, P, LS, status);
  lamp->init(50);
  scheduler.addTask(lamp);

  /*
  Task* valve = new ValveTask(...);
  valve->init(...);
  sched.addTask(valve);
  */
}

void loop() { scheduler.schedule(); }
