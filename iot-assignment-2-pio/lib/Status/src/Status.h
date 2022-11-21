#ifndef __STATUS__
#define __STATUS__


class Status {
   
    public:
        Status();
        enum State {IDLE, PREALARM, ALARM};
        enum ValveControl {MANUAL, AUTO};
        enum Light {ON, OFF};

        bool matchStatus(Status::State st);
        bool matchStatus(Status::Light lg);
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