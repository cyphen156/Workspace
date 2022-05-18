#include <wiringPi.h>

#define FND_SEL_S0      4
#define FND_SEL_S1      17
#define FND_SEL_S2      18
#define FND_SEL_S3      27
#define FND_SEL_S4      22
#define FND_SEL_S5      23
#define FND_DB_A        6
#define FND_DB_B        12
#define FND_DB_C        13
#define FND_DB_D        16
#define FND_DB_E        19
#define FND_DB_F        20  
#define FND_DB_G        26
#define FND_DB_DP       21
#define A_BIT               0X01
#define B_BIT               0X02
#define C_BIT               0X04
#define D_BIT               0X08
#define E_BIT               0X10
#define F_BIT               0X20
#define G_BIT               0X40
#define DP_BIT               0X80
#define FND_DB_PIN_NUM  8

const int FndSelectTable[6] = {
    FND_SEL_S0, FND_SEL_S1, FND_SEL_S2, 
    FND_SEL_S3, FND_SEL_S4, FND_SEL_S5
};

const int FndNumberTable[10] = {
    A_BIT | B_BIT | C_BIT | D_BIT | E_BIT | F_BIT, //0
    B_BIT | C_BIT, //1
    A_BIT | B_BIT | D_BIT | E_BIT | G_BIT, //2
    A_BIT | B_BIT | C_BIT | D_BIT | G_BIT, //3
    B_BIT | C_BIT | F_BIT | G_BIT, //4
    A_BIT | C_BIT | D_BIT | F_BIT | G_BIT, // 5
    A_BIT | C_BIT | D_BIT | E_BIT | F_BIT | G_BIT, // 6
    A_BIT | B_BIT | C_BIT, // 7
    A_BIT | B_BIT | C_BIT | D_BIT | E_BIT | F_BIT | G_BIT, // 8
    A_BIT | B_BIT | C_BIT | D_BIT | F_BIT | G_BIT // 9
};
const int FndPinTable[8] = {
    FND_DB_A, FND_DB_B, FND_DB_C, FND_DB_D,
    FND_DB_E, FND_DB_F, FND_DB_G, FND_DB_DP
};
int main(void) {
    if(wiringPiSetupGpio() == -1)
        return 1;
    pinMode(FND_SEL_S0, OUTPUT);
    int i;
    for(i = 0; i < FND_DB_PIN_NUM; i++){
        pinMode(FndPinTable[i], OUTPUT);
    }
    while(1) {
        digitalWrite(FND_SEL_S0, LOW);
        for(i = 0; i < FND_DB_PIN_NUM;i++) {
            if(FndNumberTable[5] & (1 << i)){
                digitalWrite(FndPinTable[i], HIGH);
            }else {
                digitalWrite(FndPinTable[i], LOW);
            }
            delay(1);
        }
    }
    return 0;
}