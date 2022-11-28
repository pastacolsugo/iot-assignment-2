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


Scheduler scheduler;
Status* status = new Status();
void isPressed();

void setup() {
  scheduler.init(SCHDULER_PERIOD);

  Task* lamp = new LampTask(LED_LAMP, PIR, PHOTORESISTOR,  status);
  lamp->init(LAMP_TASK_PERIOD);
  scheduler.addTask(lamp);
  
  /*TODO
  Task* valve = new ValveTask(SERVO, POTENZIOMETER, status);
  valve->init(VALVE_TASK_PERIOD);
  scheduler.addTask(valve);
  */

  Task* sonar = new SonarTask(SONAR_TRIG, SONAR_ECHO, status);
  sonar->init(SONAR_TASK_PERIOD_NORMAL);
  scheduler.addTask(sonar);

  Task* stoplight = new StoplightTask(LED_RED, LED_GREEN, status);
  stoplight->init(STOPLIGHT_TASK_PERIOD);
  scheduler.addTask(stoplight);

  Task* lcd = new LcdTask(status);
  lcd->init(LCD_TASK_PERIOD);
  scheduler.addTask(lcd);
  
  attachInterrupt(digitalPinToInterrupt(BUTTON), isPressed, RISING);
}

void loop() { scheduler.schedule(); }

void isPressed(){
  status->setValveControl( 
    status->getValveControl() == Control::AUTO && status->getState() == State::ALARM ? 
      Control::MANUAL : Control::AUTO
  );
  //status->setManualControlSource(ManualControlSource::POT_CONTROL);   //da modificare con aggiunta di seriale
}