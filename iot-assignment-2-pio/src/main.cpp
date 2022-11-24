#include <Arduino.h>

#include "Scheduler.h"
#include "Status.h"
#include "Pins.h"
#include "Parameters.h"

#include "LampTask.h"
#include "ValveTask.h"
#include "SonarTask.h"
#include "StoplightTask.h"


Scheduler scheduler;

void setup() {
  scheduler.init(50);  // Period to be adjusted

  Status* status = new Status();

  Task* lamp = new LampTask(LED_LAMP, PIR, PHOTORESISTOR,  status);
  lamp->init(50);
  scheduler.addTask(lamp);

  Task* valve = new ValveTask(SERVO, status);
  valve->init(50);
  scheduler.addTask(valve);

  Task* sonar = new SonarTask(SONAR_TRIG, SONAR_ECHO, status);
  sonar->init(SONAR_TASK_PERIOD_NORMAL);
  scheduler.addTask(sonar);

  Task* stoplight = new StoplightTask(LED_RED, LED_GREEN, status);
  stoplight->init(STOPLIGHT_TASK_PERIOD);
  scheduler.addTask(stoplight);

  /*
  Task* lcd = new StoplightTask(status);
  lcd->init();
  scheduler.addTask(lcd);
  */
  
}

void loop() { scheduler.schedule(); }
