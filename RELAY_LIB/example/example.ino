#include "relay.h"

RELAY R1(8); //Relay initialization

void setup(void) {
    Serial.begin(9600); //Serial communication settings. The required -> library reports the current status of the relay on the sérial monitor.
    R1.zapni(); //Relay closing
    R1.vypni(); //Releasing the relay

}

void loop(void) {
    R1.prepni();//switching the relay without having to enter a switch or unlock command
    delay(1000);
}