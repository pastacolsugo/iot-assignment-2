#include <Arduino.h>

#include "LampTask.h"
#include "LcdTask.h"
#include "Parameters.h"
#include "Pins.h"
#include "PotentiometerTask.h"
#include "Scheduler.h"
#include "SerialTask.h"
#include "SonarTask.h"
#include "Status.h"
#include "StoplightTask.h"
#include "ValveTask.h"

Scheduler scheduler;
Status* status = new Status();
void manualButtonPressed();

void setup() {
  scheduler.init(SCHDULER_PERIOD);

  Task* lamp = new LampTask(LED_LAMP, PIR, PHOTORESISTOR, status);
  lamp->init(LAMP_TASK_PERIOD);
  scheduler.addTask(lamp);

  Task* valve = new ValveTask(SERVO, status);
  valve->init(VALVE_TASK_PERIOD);
  scheduler.addTask(valve);

  Task* pot = new PotentiometerTask(POTENZIOMETER, status);
  pot->init(POTENTIOMETER_TASK_PERIOD);
  scheduler.addTask(pot);

  Task* sonar = new SonarTask(SONAR_TRIG, SONAR_ECHO, status);
  sonar->init(SONAR_TASK_PERIOD_NORMAL);
  scheduler.addTask(sonar);

  Task* stoplight = new StoplightTask(LED_RED, LED_GREEN, status);
  stoplight->init(STOPLIGHT_TASK_PERIOD);
  scheduler.addTask(stoplight);

  Task* lcd = new LcdTask(status);
  lcd->init(LCD_TASK_PERIOD);
  scheduler.addTask(lcd);

  Task* serial = new SerialTask(status);
  serial->init(SERIAL_TASK_PERIOD);
  scheduler.addTask(serial);

  attachInterrupt(digitalPinToInterrupt(BUTTON), manualButtonPressed, RISING);
}

void loop() { scheduler.schedule(); }

/*
 * Serial and potentiometer have same importance. 
 * If serial is managing the valve, the button is disabled, and vice versa.
 */
void manualButtonPressed() {
  if (status->getValveControl() == Control::MANUAL) {
    if (status->getManualControlSource() ==
        ManualControlSource::SERIAL_CONTROL) {
      status->setManualControlSource(ManualControlSource::POT_CONTROL);
      return;
    }
    if (status->getManualControlSource() == ManualControlSource::POT_CONTROL) {
      status->setValveControl(Control::AUTO);
      status->setManualControlSource(ManualControlSource::DISABLED);
      return;
    }
  }
  
  //AUTO control
  if (status->getState() != State::ALARM) {
      return;
  }
  
  status->setValveControl(Control::MANUAL);
  status->setManualControlSource(ManualControlSource::POT_CONTROL);
  return;
}