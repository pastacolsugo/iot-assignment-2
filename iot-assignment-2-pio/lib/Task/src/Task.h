#ifndef __TASK__
#define __TASK__

#include "Status.h"

class Task {
  int myPeriod;
  int timeElapsed;

protected:
  Status* STATUS;
  
public:


  virtual void init(int period, Status* state){
    myPeriod = period; 
    timeElapsed = 0;
    STATUS = state;
  }

  virtual void setPeriod(int period){
    myPeriod = period;
  }

  virtual void tick() = 0;

  bool updateAndCheckTime(int basePeriod){
    timeElapsed += basePeriod;
    if (timeElapsed >= myPeriod){
      timeElapsed = 0;
      return true;
    } else {
      return false; 
    }
  }
  
};

#endif