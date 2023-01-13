#include <wiringPi.h>
#include <softPwm.h>
#include <stdlib.h>

// GPIO핀 번호 세팅
#define MOTOR_MT_N_PIN   17
#define MOTOR_MT_P_PIN   4
#define LEFT_ROTATE 1
#define RIGHT_ROTATE 2
#define LED_PIN 11


void LedOn(){ //LED를 밝기 100으로 켭니다
    softPwmWrite(LED_PIN, 100); 
}

void LedOff(){ //LED를 끕니다.
    softPwmWrite(LED_PIN, 0);
}

void LedControl(int value) { //LED의 밝기를 제어합니다.

    unsigned int LedValue = value;
    printf("LED밝기 : %d\n", LedValue);
    softPwmWrite(LED_PIN, LedValue);
    
}


void MotorControl(int speed) { //모터의 속도를 제어합니다.

    unsigned int MTSPEED = speed;
    printf("모터회전속도 : %d\n", MTSPEED);
    softPwmWrite(MOTOR_MT_N_PIN, MTSPEED);
    
}

void MotorStop(){   //모터를 끕니다.
    softPwmWrite(MOTOR_MT_N_PIN, 0);
}