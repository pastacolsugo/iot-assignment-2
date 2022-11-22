#ifndef __STATUS__
#define __STATUS__

#include <Enum.h>


class Status {
   
    public:
        Status();

        bool matchStatus(State st);
        bool matchStatus(Light lg);
        int getWater();
        void setLamp(Light lv);

    private:
        State state;
        Light lamp;
        ValveControl valve;
        int waterLevel;
        State getState();
        Light getLamp();
        void setState(State st);
        void setWater(int lv);

        

};




#endif