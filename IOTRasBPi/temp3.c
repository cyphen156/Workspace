#include "sensor.h" // 센서 제어 관련 헤더 파일 포함
#include <wiringPi.h>
#include <stdio.h>

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
#define DIG_ON LOW
#define DIG_OFF HIGH
#define FND_ON HIGH
#define FND_OFF LOW
#define BUFSIZE 10
#define P_PIN 1
#define N_PIN 0

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
int * display[6];

int digits[] = {
    FND_SEL_S0, FND_SEL_S1, FND_SEL_S2,
    FND_SEL_S3, FND_SEL_S4, FND_SEL_S5
};
int segments[] = {FND_DB_A, FND_DB_B, FND_DB_C,
    FND_DB_D, FND_DB_E, FND_DB_F,
    FND_DB_G, FND_DB_DP
};

int selectedDigit = -1;
volatile float temp; // 온,습도 값 저장 변수 선언
volatile float humi;

void FanOn(void){
    digitalWrite(P_PIN, HIGH);
    digitalWrite(N_PIN, LOW);
}
void FanOff(void){
    digitalWrite(P_PIN, LOW);
    digitalWrite(N_PIN, LOW);
}
int main(void)
{ 
    int i;
    int segNum;
    int digNum;
    char buf[BUFSIZE];
    if(wiringPiSetupGpio() == -1)
        return 1;
    for(i = 0; i < 6; i++){
        pinMode(digits[i], OUTPUT);
    }
    for(i = 0; i < 8; i++){
        pinMode(segments[i], OUTPUT);
    }
    
    SHT11_Init(); // 온,습도 센서 초기 설정
    pinMode(P_PIN, OUTPUT);
    pinMode(N_PIN, OUTPUT);
    while(1){
        Transmission_start(); // 전송 시작
        temp = get_SHT11_data(TEMP); // 온도 센싱
        delay(100);
        Transmission_start(); // 전송 시작
        humi = get_SHT11_data(HUMI); // 습도 센싱
        delay(100);
        printf("Temp = %2.2f[C], Humi = %2.2f[%]\n", temp, humi);
        
        for(digNum = 0; digNum < 6; digNum++){
            digitalWrite(digits[digNum], LOW);
            display[digNum] = nums[buf[digNum] - '0'];
            for(segNum = 0; segNum < 7; segNum++){
                if(display[digNum][segNum] == 1)
                    digitalWrite(segments[segNum], HIGH);
                else
                    digitalWrite(segments[segNum], LOW);
                }
                delay(1);
                digitalWrite(digits[digNum], HIGH);
        }
        
    }
    return 0;
}