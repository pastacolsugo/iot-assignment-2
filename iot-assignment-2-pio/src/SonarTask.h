#ifndef __SONARTASK__
#define __SONARTASK__

#include <Sonar.h>
#include <Task.h>

class SonarTask : public Task {
 private:
  int trig_pin;
  int echo_pin;
  Sonar* sonar;
  Status* status;

 public:
  SonarTask(int trig, int echo, Status* state);
  void init(int period);
  void tick();
};

#endif