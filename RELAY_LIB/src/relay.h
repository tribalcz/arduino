#pragma once

class RELAY{
    private:
        int pin;
        bool stav = LOW;
        void nastav(bool);

    public:
        RELAY(int);
        void zapni();
        void vypni();
        void prepni();
        bool vratStav();        
};