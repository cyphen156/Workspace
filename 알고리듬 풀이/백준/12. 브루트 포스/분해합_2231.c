#define _CRT_SECURE_NO_WARNINGS
/*
    백준 2231 분해합
    N의 분해합은 N과 N을 이루는 각 자리수의 합
    => N = 13; 분해합 = 13+1+3 == 17의 생성자
    
    문제의 요구사항은 17(분해합)이 주어졌을 때
    17의 생성자를 구하라
    => 원본 데이터 == 자릿수의 합+k를 찾아내라
*/
/*
    제한사항
    int 0< N <>0>=1,000,000
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i < N; i++) {
        int sum = i;
        int temp = i;

        while (temp) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == N) {
            printf("%d", i);
            return 0;
        }
    }

    printf("0");
    return 0;
}