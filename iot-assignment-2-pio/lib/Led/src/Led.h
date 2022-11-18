#ifndef __LED__
#define __LED__

class Led { 
public:
  Led(int pin);
  void switchOn();
  void switchOff();
  void blink();
      
private:
  long t;
  int pin;  
};

#endif