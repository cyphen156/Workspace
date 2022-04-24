//도레미파솔라시도 사운드 출력하기
#include <wiringPi.h>
#include <softTone.h>

#define BUZZER_PIN      4

#define DO_L        523
#define RE          587
#define MI          659
#define FA          698
#define SOL         784
#define RA          880
#define SI          987 
#define DO_H    1046

int sevenScale(int scale){
    int _ret = 0;
    switch(scale){
        case 0: 
            _ret = DO_L;
            break;
        case 1:
            _ret = RE;
            break;
        case 2:
            _ret = MI;
            break;
        case 3:
            _ret = FA;
            break;
        case 4:
            _ret = SOL;
            break;
        case 5:
            _ret = RA;
            break;
        case 6:
            _ret = SI;
            break;
        case 7:
            _ret = DO_H;
            break;
    }
    return _ret;
}

int main(void) {
    if(wiringPiSetupGpio() == -1)
        return -1;

    softToneCreate(BUZZER_PIN);

    int i;
    for (i = 0; i < 8; i++) {
        softToneWrite(BUZZER_PIN, sevenScale(i));
        delay(300);
        softToneWrite(BUZZER_PIN, 0);
    }
    return 0;
}