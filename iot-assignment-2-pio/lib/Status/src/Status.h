#ifndef __STATUS__
#define __STATUS__

#include <Enum.h>


class Status {
   
    private:
        State state;
        Light lamp;
        Control valve;
        int waterLevel;

    public:
        Status();
        State getState();
        Light getLamp();
        Control getValve();
        void setState(State st);
        void setWater(int lv);
        bool matchStatus(State st);
        bool matchStatus(Light lg);
        bool matchValveStatus(Control vl);
        int getWater();
        void setLamp(Light lv);

};




#endif