#include "SonarTask.h"
//#include <Arduino.h>

SonarTask::SonarTask(int trig_pin, int echo_pin, Status* state) {
  this->sonar = new Sonar(trig_pin, echo_pin);
  this->status = state;

  //Serial.begin(9600);
}

void SonarTask::run() {
  float sonarReading = sonar->getDistance();
  int waterLevel = (WATER_LEVEL_MAX < sonarReading) ? 0 : WATER_LEVEL_MAX - sonarReading;   //cast implicito ad int
  status->setWater(waterLevel);

  //Serial.print("sonarReading: " + String(sonarReading) + "\twaterLevel: " + waterLevel + "  ");

  if (waterLevel > WATER_LEVEL_2) {
    status->setState(State::ALARM);
    //Serial.println("alarm");
    setPeriod(SONAR_TASK_PERIOD_ALARM);
    return;
  }

  if (waterLevel > WATER_LEVEL_1) {
    status->setState(State::PREALARM);
    //Serial.println("prealarm");
    setPeriod(SONAR_TASK_PERIOD_PREALARM);
    return;
  }
  status->setState(State::NORMAL);
  //Serial.println("normal");
  setPeriod(SONAR_TASK_PERIOD_NORMAL);
}