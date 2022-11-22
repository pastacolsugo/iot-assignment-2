#ifndef __SONAR__
#define __SONAR__

/* supponendo di eseguire il test 
   in un ambiente a 20 °C 
   https://it.wikipedia.org/wiki/Velocità_del_suono
*/ 

class Sonar{
    public:
        Sonar(int trigPin, int echoPin);
        float getDistance();

    private:
        int trigPin;
        int echoPin;
        const double vs = 331.45 + 0.62*20;
};

#endif