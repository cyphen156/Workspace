// 실제 누진세 구간별 적용하기

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

double clac_tax(int usage, int weather, double tax);

int main(void) {
    int usage, weather;
    double charge, tax = 13.7;
    printf("Enter monthly amount in Kwh.\n");
    scanf("%d", &usage);
    printf("Enter 1 if summer or winter, 0 if not.\n");
    scanf("%d", &weather);
    charge = clac_tax(usage, weather, tax);
    printf("Including tax, you pay %d.", (int)charge);
    return 0;
}

double clac_tax(int usage, int weather, double tax) {
    double result = 0;
    int temp;
    //여름, 겨울일때 1000 초과분 계산
    if (usage > 1000 && weather == 1) { 
        temp = usage - 1000;
            result += 709.5 * temp;
        usage -= temp;
    }
    // 사용량 400 초과분 (401 ~ 1000)요금 계산
    if (usage > 400) {  
        temp = usage - 400;
        result += 7300 + 280.6 * temp;
        usage -= temp;
    }
    // 사용량 200 초과분 (201 ~ 400)요금 계산
    if (usage > 200) {
        temp = usage - 200;
        result += 1600 + 187.9 * temp;
        usage -= temp;
    }
    // 나머지 사용량 (200) 이하 요금 계산
    result += 910 + 93.3 * usage;
    return result * (100 + tax)/100;
}