#ifndef __POTENZIOMETER__
#define __POTENZIOMETER__

class Potenziometer {
 public:
  Potenziometer(int pin);
  int read();

 private:
  int pin;
};

#endif