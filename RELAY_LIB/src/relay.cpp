#include <Arduino.h>
#include "relay.h"

RELAY::RELAY(int p) {
    pin = p;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, state);
}

void RELAY::on() {
    set(HIGH);
}

void RELAY::of() {
    set(LOW);
}

void RELAY::switch(){
    set(!state); //nastavý relé na obrácenou hodnotu 0->1/1->0
}

void RELAY::set(bool s) {
    state = s;
    Serial.print("set ");
    Serial.print(state);
    Serial.print(" to pin ");
    Serial.println(pin);
    digitalWrite(pin, state);
}

bool RELAY::returnState() {
    return state;
}