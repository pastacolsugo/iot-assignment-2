#ifndef __TASK__
#define __TASK__

#include "Status.h"

class Task {
  int myPeriod;
  int timeElapsed;

 public:
  virtual void init(int period) {
    myPeriod = period;
    timeElapsed = 0;
  }

  virtual void setPeriod(int period) { myPeriod = period; }

  virtual void run() = 0;

  bool updateAndCheckTime(int basePeriod) {
    timeElapsed += basePeriod;
    if (timeElapsed >= myPeriod) {
      timeElapsed = 0;
      return true;
    }
    return false;
  }
};

#endif