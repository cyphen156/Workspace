#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void calc(int x, int y, int z);

int main(void) {
    int a, b, c;
    printf("Enter scores of three judges.\n");
    scanf("%d %d %d", &a, &b, &c);
    if (0 < a && a < 11 && 0 < b && b < 11 && 0 < c && c < 11) {
        if (a == b || a == c) {
            printf("심판은 서로 다른 점수를 줘야 합니다.\n");
            return;
        }
        else
            calc(a, b, c);
    }
    else
        pritnf("심판이 줄 수 있는 점수는 1점부터 10점 사이입니다.");
    return 0;
}

void calc(int x, int y, int z) {
    if (x > y) {
        if (y > z) { // (x > y > z)
            x = 0;
            z = 0;
        }
        else {  // (x > z > y)
            x = 0;
            y = 0;
        }
    }
    else {  
        if (x > z) { // (y > x > z)
            y = 0;
            z = 0;
        }
        else {  // (y > z > x)
            y = 0;
            x = 0;
        }
    }
    printf("The player gets %d.", x + y + z);
}