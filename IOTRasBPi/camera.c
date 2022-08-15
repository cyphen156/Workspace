#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <softPwm.h>

#define Led_1	4
#define Led_2   17 
#define Led_3   18
#define Led_4   27  
#define Led_5   22
#define Led_6   23
#define Led_7   24 
#define Led_8   25

#define KEYPAD_PB1  6
#define KEYPAD_PB2  12
#define KEYPAD_PB3  13
#define KEYPAD_PB4  16
#define KEYPAD_PB5  19
#define KEYPAD_PB6  20
#define KEYPAD_PB7  26
#define KEYPAD_PB8  21

#define LED_ON  1
#define LED_OFF 0
#define MAX_LED_NUM 8
#define MAX_KEY_BT_NUM  8
#define KEYPAD_ON   0

const int LedPinTable[MAX_LED_NUM] = {
    Led_1, Led_2, Led_3, Led_4,
	Led_5, Led_6, Led_7, Led_8
};
const int KeypadTable[MAX_KEY_BT_NUM] = {
   KEYPAD_PB1, KEYPAD_PB2, KEYPAD_PB3, KEYPAD_PB4,
   KEYPAD_PB5, KEYPAD_PB6, KEYPAD_PB7, KEYPAD_PB8 
};

char cmd[100]="sudo raspistill -o image/image_%d.jpg -tl 2000 -t 8000";

int KeypadRead(void) {
    int i, nKeypadstate;
    nKeypadstate = 0;
    for(i = 0; i < MAX_KEY_BT_NUM; i++){
        if (!digitalRead(KeypadTable[i])){
            nKeypadstate |= (1 << i);
        }
    }
    return nKeypadstate;
}

int main (void) {
    if (wiringPiSetupGpio() == -1)
        return 1;
    int nKeypadstate;
        int i;

    for (i = 0; i < MAX_LED_NUM; i++) {
        pinMode(LedPinTable[i], OUTPUT);
        softPwmCreate(LedPinTable[i], 0, 100);
    }

    for(i = 0; i < MAX_KEY_BT_NUM; i++) {
        pinMode(KeypadTable[i], INPUT);
    }

    while (1) {
        nKeypadstate = KeypadRead();//눌린 키패드 번호를 가져옴
        if(nKeypadstate != 0){//키패드가 눌린 상태면
            for (i = 0; i< MAX_KEY_BT_NUM; i++) {
                if(nKeypadstate & (1 << i)) {//키패드 번호만큼의 사진을 찍기위한 반복문
                    printf("치즈~~!! %d\n", i+1);
                    softPwmWrite(LedPinTable[i], i+13); //눌린 번호에 해당하는 LED를 켜주고 *13만큼의 밝기를 밝힙니다.
                    system(cmd);//인덱스 번호만큼 사진을 찍는 명령을 실행
                    delay(10);
                }else{
                    softPwmWrite(LedPinTable[i], 0); //인덱스를 제외한 나머지 LED를 모두꺼줍니다
                }
            }
        }
        //char cmd[100] = "sudo raspivid -t 10000 -o vod/vod.h264";
	} 
    return 0;
}