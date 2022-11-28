#ifndef __POTENZIOMETER__
#define __POTENZIOMETER__

class Potentiometer {
 public:
  Potentiometer(int pin);
  int read();

 private:
  int pin;
};

#endif