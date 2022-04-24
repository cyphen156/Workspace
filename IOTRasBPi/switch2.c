//키패드를 누르면 LED를 켜졌다 꺼졌다
#include <wiringPi.h>
#include <stdio.h>
#define LED_PIN 6
#define KEYPAD_PB   9
#define KEYPAD_ON   0
#define KEYPAD_OFF  1
#define LED_ON  1
#define LED_OFF 0

 int main(void) {
    if(wiringPiSetupGpio() == -1)
        return 1;
    pinMode(LED_PIN, OUTPUT);
    pinMode(KEYPAD_PB, INPUT);

    int led_status = LED_OFF;
    while (1){
        if(digitalRead(KEYPAD_PB) == KEYPAD_ON) {
            printf("aa\n");
            led_status = led_status^1;
        }
        if (led_status == LED_ON) {
            digitalWrite(LED_PIN, HIGH);
        }
        else
            digitalWrite(LED_PIN, LOW);
            
        delay(500);
    }
    return 0;
 }