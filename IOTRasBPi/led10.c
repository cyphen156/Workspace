//LED 모듈의 8개 LED 점점 밝아지기
#include <wiringPi.h>
#include <softPwm.h>
#define LED_PIN_1   4   
#define LED_PIN_2   17
#define LED_PIN_3   18  
#define LED_PIN_4   27
#define LED_PIN_5   22  
#define LED_PIN_6   23
#define LED_PIN_7   24   
#define LED_PIN_8   25
#define MAX_LED_NUM 8
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
        softPwmCreate(LedPinTable[i], 0, 100);
    }

    for (i = 0; i < MAX_LED_NUM; i++){
        softPwmWrite(LedPinTable[i], 1 + (20*i));
        delay(300);
    }
    for (i = 0; i < MAX_LED_NUM; i++){
        softPwmWrite(LedPinTable[i], 0);
    }

    delay(50);

    return 0;
 }
