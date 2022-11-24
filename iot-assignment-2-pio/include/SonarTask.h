#ifndef __SONARTASK__
#define __SONARTASK__

#include <Sonar.h>
#include <Status.h>
#include <Task.h>

class SonarTask : public Task {
 private:
  Sonar* sonar;
  Status* status;

 public:
  SonarTask(int trig_pin, int echo_pin, Status* state);
  void run();
};

#endif