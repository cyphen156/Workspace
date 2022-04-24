//키패드 누르면 LED 켜지기
#include <wiringPi.h>
#include <stdio.h>
#define LED_PIN 6
#define KEYPAD_PB   9
#define KEYPAD_ON   0
#define KEYPAD_OFF  1

 int main(void) {
    if(wiringPiSetupGpio() == -1)
        return 1;
    pinMode(LED_PIN, OUTPUT);
    pinMode(KEYPAD_PB, INPUT);

    while (1){
        digitalWrite(LED_PIN, LOW);
        if(digitalRead(KEYPAD_PB) == KEYPAD_ON) {
            printf("aa\n");
            digitalWrite(LED_PIN, HIGH);
        }
        delay(500);
    }
    return 0;
 }