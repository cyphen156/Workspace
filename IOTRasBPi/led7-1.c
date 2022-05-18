#include <wiringPi.h>
#include <softPwm.h>
#define LED_RED_1   4

 int main(void) {
    if(wiringPiSetupGpio() == -1)
        return 1;
    pinMode(LED_RED_1, OUTPUT);
    digitalWrite(LED_RED_1, LOW);
    softPwmCreate(LED_RED_1, 0, 100);

    while (1){
        for (int i = 0; i < 100; i++){
            if (i == 100)
                i = 0;
            else {
                softPwmWrite(LED_RED_1, i);   
            }   
            delay(50); 
        }
    }
    return 0;
 }
