#ifndef __STATUS__
#define __STATUS__

#include <Enum.h>

class Status {
 private:
  State state;
  Light lamp;
  Control valve;
  int waterLevel;

 public:
  Status();

  State getState();
  void setState(State st);

  Light getLamp();
  void setLamp(Light lv);

  int getWater();
  void setWater(int lv);

  Control getValve();

  bool matchStateStatus(State st);
  bool matchLampStatus(Light lg);
  bool matchValveStatus(Control vl);

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