//스위치를 누르면 여러 개의 FND에 숫자 출력하기
#include <wiringPi.h>

#define FND_SEL_S0 4
#define FND_SEL_S1 17
#define FND_SEL_S2 18
#define FND_SEL_S3 27
#define FND_SEL_S4 22
#define FND_SEL_S5 23
#define FND_DB_A 6
#define FND_DB_B 12
#define FND_DB_C 13
#define FND_DB_D 16
#define FND_DB_E 19
#define FND_DB_F 20
#define FND_DB_G 26
#define FND_DB_DP 21

#define DIG_ON  LOW
#define DIG_OFF HIGH
#define FND_ON  HIGH
#define FND_OFF LOW

#define KEYPAD_PB1  11
#define KEYPAD_PB2  9
#define KEYPAD_PB3  10
#define KEYPAD_PB4  7
#define KEYPAD_PB5  5

int nums[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, //0
    {0, 1, 1, 0, 0, 0, 0}, //1
    {1, 1, 0, 1, 1, 0, 1}, //2
    {1, 1, 1, 1, 0, 0, 1}, //3
    {0, 1, 1, 0, 0, 1, 1}, //4
    {1, 0, 1, 1, 0, 1, 1}, //5
    {1, 0, 1, 1, 1, 1, 1}, //6
    {1, 1, 1, 0, 0, 1, 0}, //7
    {1, 1, 1, 1, 1, 1, 1}, //8
    {1, 1, 1, 1, 0, 1, 1} //9
};

int digits[] = {
    FND_SEL_S0, FND_SEL_S1, FND_SEL_S2, 
    FND_SEL_S3, FND_SEL_S4, FND_SEL_S5, 
};

int segments[] = {
    FND_DB_A, FND_DB_B, FND_DB_C, FND_DB_D,
    FND_DB_E, FND_DB_F, FND_DB_G, FND_DB_DP
};

const int KeyPadTable[5]  = {
    KEYPAD_PB1, KEYPAD_PB2, KEYPAD_PB3,
    KEYPAD_PB4, KEYPAD_PB5
};
int selectedDigit = -1;

void keyPadISR1 (void) {
    selectedDigit = 0;
}
void keyPadISR2 (void) {
    selectedDigit = 1;
}
void keyPadISR3 (void) {
    selectedDigit = 2;
}
void keyPadISR4 (void) {
    selectedDigit = 3;
}
void keyPadISR5 (void) {
    selectedDigit = 4;
}

void (*keyPadISR[5])(void) = {
    keyPadISR1, keyPadISR2, keyPadISR3,
    keyPadISR4, keyPadISR5
};

int main(void) {
    int i;
    int digNum;
    int segNum;

    if (wiringPiSetupGpio() == -1)
        return 1;

    for (i = 0; i < 6; i++) {
        pinMode(digits[i], OUTPUT);
    }

    for (i = 0; i < 8; i++) {
        pinMode(segments[i], OUTPUT);
    }

    for (i = 0; i < 5; i++) {
        if (wiringPiISR(KeyPadTable[i], INT_EDGE_FALLING, keyPadISR[i]) < 0)
            return 1;
    }

    while (1) {
        for (digNum = 0; digNum < 6; digNum++) {
            digitalWrite(digits[digNum], LOW);
            if (selectedDigit == digNum){
                for (segNum = 0; segNum < 7; segNum++) {            
                    if (nums[digNum][segNum] == 1)
                        digitalWrite(segments[segNum], HIGH);
                    else
                        digitalWrite(segments[segNum], LOW);
                }
            }else {
                for (segNum = 0; segNum < 7; segNum++) {
                    digitalWrite(segments[segNum], LOW);
                }
            }                
            delay(1);
            digitalWrite(digits[digNum], HIGH);
        }
    }
    return 0;
}