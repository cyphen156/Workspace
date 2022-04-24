//LED모듈의 LED 한 개 여러 번 깜빡이기
#include <wiringPi.h>
#define LED_RED_1   4

 int main(void) {
    if(wiringPiSetupGpio() == -1)
        return 1;
    pinMode(LED_RED_1, OUTPUT);
    digitalWrite(LED_RED_1, LOW);

    while (1){
        digitalWrite(LED_RED_1, HIGH);
        delay(500);
        digitalWrite(LED_RED_1, LOW);
        delay(500);
    }
    return 0;
 }