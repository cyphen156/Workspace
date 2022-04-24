#include <wiringPi.h>
#include <stdio.h>
#define LedGreenPin 4
#define LedRedPin 5

 int main(void) {
    if(wiringPiSetupGpio() == -1)
        return 1;
    pinMode(LedGreenPin, OUTPUT);
    pinMode(LedRedPin, OUTPUT);
    int ledState = LOW;
    unsigned int previousMills = 0;
    unsigned int currentMills;
    int interval = 500;
    for(;;){
        currentMills = millis();
        if(currentMills - previousMills >= interval) {
            previousMills = currentMills;
            if(ledState == LOW)
                ledState = HIGH;
            else
                ledState = LOW;
            digitalWrite(LedGreenPin, ledState);
            digitalWrite(LedRedPin, ledState);
        }
    }
    return 0;
 }