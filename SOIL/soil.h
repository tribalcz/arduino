#pragma once

class SOIL{
    private:
        int pinDig;
        int pinAn;   
        int pinVcc;
        int period = 0;
        bool state = LOW;
        unsigned long lastChange = 0;
        void set(bool, int);
    public:
        SOIL(int, int, int, int);
        void check(bool);
        void on();
        void off();
        int returnValue();
        bool turnOn();
        void stabilise();
};