#define _CRT_SECURE_NO_WARNINGS
/*
    백준 14215 세 막대
    세 변의 길이를 자연수 범위 내에서 자유자재로 줄일 수 있음
    -> 늘리는건 안됨
    둘레 길이가 최대가 되도록 해라
    우선 난수로 주어진 변수들을 삼각형이 될 수 있도록 조건에 맞춰줘야 한다
    -> 가장 긴 변 < 나머지 두 변의 합
*/ 
/*
    제한사항
    1 <= a, b, c <= 100
*/
#include <stdio.h>

int main() {
    int a, b, c;
    int max, sum = 0;
    scanf("%d%d%d", &a, &b, &c);
    // 가장 긴 변
    max = a > b ? a : b;
    max = max > c ? max : c;

    // 다른 두 변의 합
    sum = a + b + c - max;  

    if (max >= sum) {
        max = sum - 1;
    }
    printf("%d", max + sum);
    return 0;
}
