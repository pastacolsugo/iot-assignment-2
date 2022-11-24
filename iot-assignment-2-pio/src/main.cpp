#include <Arduino.h>

#include "Scheduler.h"
#include "Status.h"
#include "Pins.h"
#include "Parameters.h"

#include "LampTask.h"
#include "ValveTask.h"
#include "SonarTask.h"
#include "StoplightTask.h"
#include "LcdTask.h"
#include "ButtonTask.h"


Scheduler scheduler;

void setup() {
  scheduler.init(SCHDULER_PERIOD);

  Status* status = new Status();

  Task* lamp = new LampTask(LED_LAMP, PIR, PHOTORESISTOR,  status);
  lamp->init(LAMP_TASK_PERIOD);
  scheduler.addTask(lamp);

  Task* valve = new ValveTask(SERVO, status);
  valve->init(VALVE_TASK_PERIOD);
  scheduler.addTask(valve);

  Task* sonar = new SonarTask(SONAR_TRIG, SONAR_ECHO, status);
  sonar->init(SONAR_TASK_PERIOD_NORMAL);
  scheduler.addTask(sonar);

  Task* stoplight = new StoplightTask(LED_RED, LED_GREEN, status);
  stoplight->init(STOPLIGHT_TASK_PERIOD);
  scheduler.addTask(stoplight);

  Task* lcd = new LcdTask(status);
  lcd->init(LCD_TASK_PERIOD);
  scheduler.addTask(lcd);

  Task* button = new ButtonTask(BUTTON, status);
  button->init(BUTTON_TASK_PERIOD);
  scheduler.addTask(button);
  
}

void loop() { scheduler.schedule(); }
