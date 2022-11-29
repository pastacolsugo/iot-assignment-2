#ifndef __STATUS__
#define __STATUS__

#include <Enum.h>

class Status {
 private:
  State state;
  Light lamp;
  Control valveControl;
  ManualControlSource manualControlSource;

  int waterLevel;
  int valvePosition;

  int SerialValvePosition;
  int PotValvePosition;
  /*
  */

 public:
  Status();

  State getState();
  void setState(State st);

  Light getLamp();
  void setLamp(Light lv);

  int getWater();
  void setWater(int lv);

  Control getValveControl();
  void setValveControl(const Control &c);
  
  ManualControlSource getManualControlSource();
  void setManualControlSource(const ManualControlSource &s);
  
  int getValvePosition();
  void setValvePosition(int pos);

  /*
  int getAutoValvePosition();
  void setAutoValvePosition(int pos);
  */

  int getSerialValvePosition();
  void setSerialValvePosition(int pos);
  void setValvePositionFromSerialValvePosition();

  int getPotValvePosition();
  void setPotValvePosition(int pos);
  void setValvePositionFromPotValvePosition();
  
  // friend bool operator==(const Status &s, const Light &l) {
  //   return (s.lamp == l);
  // }

  // friend bool operator==(const Status &s, const State &ss) {
  //   return (s.state == ss);
  // }

  // friend bool operator==(const Status &s, const Control &v) {
  //   return (s.valve == v);
  // }
};

#endif