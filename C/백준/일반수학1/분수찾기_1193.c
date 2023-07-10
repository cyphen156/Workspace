/*
    n차일때 새로생기는 분수의 수는 n개
    1+2+3+4+5+....
    입력력값에 따른 분수의 크기도 계산
    x/n-x+1
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int x, i;
    
    scanf("%d", &x);

    for (i = 1; x > i; i++) {
        x -= i;
    }
    if (i % 2 == 0) {
        printf("%d/%d\n", x, i - x + 1);
    }
    else {
        printf("%d/%d\n", i - x + 1, x);
    }

    return 0;
}
