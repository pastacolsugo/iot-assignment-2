#ifndef __PIR__
#define __PIR__

class Pir {
public:
  Pir(int pin);
  int detectedMotion();
  
private:
  int pin;
};

#endif