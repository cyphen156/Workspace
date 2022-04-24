//zlvoem(8개)를 누르면 LED(8개) 켜지기
#include <wiringPi.h>

#define LED_PIN_1	4
#define LED_PIN_2   17
#define LED_PIN_3   18
#define LED_PIN_4   27
#define LED_PIN_5   22
#define LED_PIN_6   23
#define LED_PIN_7   24
#define LED_PIN_8   25

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

const int LedPinTable[MAX_LED_NUM] = {
    LED_PIN_1, LED_PIN_2, LED_PIN_3, LED_PIN_4,
    LED_PIN_5, LED_PIN_6, LED_PIN_7, LED_PIN_8
};
const int KeypadTable[MAX_KEY_BT_NUM] = {
   KEYPAD_PB1, KEYPAD_PB2, KEYPAD_PB3, KEYPAD_PB4,
   KEYPAD_PB5, KEYPAD_PB6, KEYPAD_PB7, KEYPAD_PB8
};

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
void LedControl(int LedNum, int Cmd){
    int i;
    for(i = 0; i < MAX_LED_NUM;i++){
        if(i==LedNum) {
            if (Cmd == LED_ON) {
                digitalWrite(LedPinTable[i], HIGH);
            }else {
                digitalWrite(LedPinTable[i], LOW);
            }
        }
    }
}

int main(void) {
    if(wiringPiSetupGpio() == -1)
        return 1;
    int i;
    int nKeypadstate;
    for(i = 0; i < MAX_LED_NUM; i++) {
        pinMode(LedPinTable[i], OUTPUT);
    }

    for(i = 0; i < MAX_KEY_BT_NUM; i++) {
        pinMode(KeypadTable[i], INPUT);
    }
    while (1) {
        nKeypadstate = KeypadRead();
        for(i = 0; i < MAX_KEY_BT_NUM; i++){
            if(nKeypadstate & (1 <<i))
                LedControl(i, LED_ON);
            else
                LedControl(i, LED_OFF);
        }
    }
    return 0;
}
