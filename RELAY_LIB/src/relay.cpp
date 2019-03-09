#include <Arduino.h>
#include "relay.h"

RELAY::RELAY(int p) {
    pin = p;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, stav);
}

void RELAY::zapni() {
    nastav(HIGH);
}

void RELAY::vypni() {
    nastav(LOW);
}

void RELAY::prepni(){
    nastav(!stav); //nastavý relé na obrácenou hodnotu 0->1/1->0
}

void RELAY::nastav(bool s) {
    stav = s;
    Serial.print("Nastavuji ");
    Serial.print(stav);
    Serial.print(" na pinu ");
    Serial.println(pin);
    digitalWrite(pin, stav);
}

bool RELAY::vratStav() {
    return stav;
}