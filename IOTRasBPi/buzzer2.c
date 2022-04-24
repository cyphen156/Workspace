//학교 종이 땡땡땡 사운드 출력하기
#include <wiringPi.h>
#include <softTone.h>

#define SPKR    4
#define TOTAL   32

int scales[] = {
    523, 587, 659, 698, 784, 880, 987, 1046
};//DO_L(1), RE(1), MI(2), FA(3), SOL(4), RA(5), SI(6), DO_H(7)

int notes[] = {
    4, 4, 5, 5, 4, 4, 2, 4, 4, 2, 2, 1, 
    4, 4, 5, 5, 4, 4, 2, 4, 2, 1, 2, 0
};

int duration[] = {
    1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4, 
    1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 4
};

int musicPlay(){
    int i;
    softToneCreate(SPKR);

    for (i = 0; i < TOTAL; i++) {

        softToneWrite(SPKR, scales[notes[i]]);
        delay(duration[i]*500);
    }
    return 0;
}

int main(void) {
    if(wiringPiSetupGpio() == -1)
        return -1;
    musicPlay();
    return 0;
}