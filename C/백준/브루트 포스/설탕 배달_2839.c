#define _CRT_SECURE_NO_WARNINGS
/*
    백준 2839 설탕 배달
    Nkg 배달
    3kg or 5kg의 output
    최대한 적은 갯수 cnt
    min개수, N키로 못만들면 -1출력
    3씩 빼가면서 5의 배수가 남을때까지 연산
    -> 3*5 = 15라서 5의 배수이기 때문
*/
/*
    제한사항
    3 <= N <= 5,000
*/
/*
    문제 풀이 시간 : １0분
*/
#include <stdio.h>

int main() {
    int N, count = 0;
    scanf("%d", &N);

    while (N >= 0) {
        if (N % 5 == 0) {
            printf("%d\n", N / 5 + count);
            return 0;
        }
        N -= 3;
        count++;
    }

    printf("-1\n");
    return 0;
}

