#pragma once

class RELAY{
    private:
        int pin;
        bool state = LOW;
        void set(bool);

    public:
        RELAY(int);
        void on();
        void off();
        void switch();
        bool returnState();        
};