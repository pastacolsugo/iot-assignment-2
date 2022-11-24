#include <Arduino.h>

#include "LampTask.h"
#include "Scheduler.h"
#include "Status.h"
#include "ValveTask.h"
#include <Pins.h>

Scheduler scheduler;

void setup() {
  scheduler.init(50);  // Period to be adjusted

  Status* status = new Status();

  Task* lamp = new LampTask(LED_LAMP, PIR, PHOTORESISTOR,  status);
  lamp->init(50);
  scheduler.addTask(lamp);

  /*
  Task* valve = new ValveTask(...);
  valve->init(...);
  sched.addTask(valve);
  */
}

void loop() { scheduler.schedule(); }
