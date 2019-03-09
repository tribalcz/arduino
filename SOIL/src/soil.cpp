#include <Arduino.h>
#include "soil.h"

SOIL::SOIL(int d, int a, int vcc, int _period) {
    pinDig = d;
    pinAn = a;
    pinVcc = vcc;
    period = _period;

    pinMode(pinDig, INPUT);
    pinMode(pinAn, INPUT);
    pinMode(pinVcc, OUTPUT);

    digitalWrite(pinVcc, state);
}

void SOIL::set(boolean s, int pin) { //set pin 0/1
    stav = s;
    Serial.print("Set ");
    Serial.print(state);
    Serial.print(" to pin ");
    Serial.println(pin);
    digitalWrite(pin, state);
}

void SOIL::on() { //power on the module
    set(HIGH, pinVcc);
}

void SOIL::off() { //power off the module
    set(LOW, pinVcc);
}

int SOIL::returnValue() {
    int v = analogRead(pinAn);
    return(v);
}

void SOIL::check(boolean verbose = true) { //Detecting the water level by reading the analog value. Useful as Oriental level of water level
    if(lastChange + period/2 <= millis()) {
        on();
        stabilise(); //pause for voltage stabilization
        int analog = returnValue();
        if(verbose) {
            Serial.print("Analog value: ");
            Serial.println(analog);
        }
        off();
        lastChange = millis();
    }
}

boolean SOIL::turnOn() { //Determining the water level according to the trimmer setting on the module. For follow-up action
    return(digitalRead(pinDig));
}

void SOIL::stabilise() {
    delay(100);
}