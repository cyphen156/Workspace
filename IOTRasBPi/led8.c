//LED모듈의 LED 8개 번갈아 깜빡이기
#include <wiringPi.h>
#define LED_PIN_1	4
#define LED_PIN_2	17
#define LED_PIN_3	18
#define LED_PIN_4	27
#define LED_PIN_5	22
#define LED_PIN_6	23
#define LED_PIN_7	24
#define LED_PIN_8	25
#define MAX_LED_NUM	8
const int LedPinTable[8] = {
    LED_PIN_1, LED_PIN_2, LED_PIN_3, LED_PIN_4,
    LED_PIN_5, LED_PIN_6, LED_PIN_7, LED_PIN_8
};

 int main(void) {
    if(wiringPiSetupGpio() == -1)
        return 1;
    int i;
    for(i = 0; i < MAX_LED_NUM; i++){
        pinMode(LedPinTable[i], OUTPUT);
        digitalWrite(LedPinTable[i], LOW);
    }
    for (i = 0; i < MAX_LED_NUM; i++){
        digitalWrite(LedPinTable[i], HIGH);
        delay(500);
        digitalWrite(LedPinTable[i], LOW);
        delay(500);
    }
    return 0;
 }
