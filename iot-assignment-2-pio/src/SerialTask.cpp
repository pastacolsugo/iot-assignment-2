
#include "SerialTask.h"

#include <string.h>

SerialTask::SerialTask(Status *st) {
  Serial.begin(SERIAL_BAUD);
  this->status = st;
}

void SerialTask::sendStateMessage() {
  Serial.println((const char *[]){
      "state:normal",
      "state:prealarm",
      "state:alarm",
  }[status->getState()]);
}

void SerialTask::sendLampMessage() {
  Serial.println((const char *[]){
      "lamp:on",
      "lamp:off",
  }[status->getLamp()]);
}

void SerialTask::sendControlMessage() {
  Serial.println((const char *[]){"control:manual",
                                  "control:auto"}[status->getValveControl()]);
}

void SerialTask::sendManualControlSourceMessage() {
  Serial.println((const char *[]){
      "control_sorurce:none", "control_source:pot",
      "control_source:serial"}[status->getManualControlSource()]);
}

void SerialTask::sendWaterMessage() {
  Serial.println("water_level:" + String(status->getWater()));
}

void SerialTask::sendValvePositionMessage() {
  Serial.println("valve_position:" + String(status->getValvePosition()));
}

void SerialTask::sendTerminateMessage() { Serial.println(); }

void SerialTask::send() {
  sendStateMessage();
  sendLampMessage();
  sendWaterMessage();
  sendValvePositionMessage();
  sendControlMessage();
  sendManualControlSourceMessage();
  sendTerminateMessage();
}

void SerialTask::updateStatusFromMessage(char *mess) {
  char *part[2];

  part[0] = strtok(mess, ":");
  part[1] = strtok(NULL, "\0");

  if (!strcmp(part[0], "set_control") and
      status->getManualControlSource() != ManualControlSource::POT_CONTROL) {
    if (!strcmp(part[1], "auto")) {
      // Se sono in manual da pot posso disabilitare e tornare in auto??
      // ATTENZIONE
      status->setManualControlSource(ManualControlSource::DISABLED);
      status->setValveControl(Control::AUTO);
      return;
    }
    if (!strcmp(part[1], "manual")) {
      status->setManualControlSource(ManualControlSource::SERIAL_CONTROL);
      status->setValveControl(Control::MANUAL);
      return;
    }
  }

  if (!strcmp(part[0], "set_valve")) {
    status->setSerialValvePosition(atoi(part[1]));
    return;
  }
}

void SerialTask::read() {
  // Create a place to hold the incoming message
  static char message[MAX_MESSAGE_LENGTH];
  static unsigned int message_pos = 0;

  while (Serial.available() > 0) {
    if (message_pos >= MAX_MESSAGE_LENGTH) {
      message_pos = 0;
      while (Serial.available() > 0 and Serial.read() != '\0') {
      };
    }
    // Read the next available byte in the serial receive buffer
    char inByte = Serial.read();

    // Full message received...
    if (inByte == '\n') {
      // Add null character to string
      message[message_pos] = '\0';

      // Print the message (or do other things)
      updateStatusFromMessage(message);

      // Reset for the next message
      message_pos = 0;
      continue;
    }

    // Add the incoming byte to our message
    message[message_pos] = inByte;
    message_pos++;
  }
}

void SerialTask::run() {
  read();
  send();
}
