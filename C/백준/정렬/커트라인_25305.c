#define _CRT_SECURE_NO_WARNINGS
/*
    백준 25305 커트라인
    N명의 학생
    점수가 높은 K명 선발
    이 때 커트라인 = N-K의 점수
*/
/*
    제한사항
    line 1 : N K
    line 2 : x1 x2 x3 ...xn

    0 < K <= N <= 1,000
    0 <= x <= 10,000
    */
/*
    문제 풀이 시간 : 5분
*/
#include <stdio.h>

int main() {
    int N, k, arr[1000] = { 0 };

    scanf("%d %d", &N, &k);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < N-1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("%d", arr[N-k]);
    return 0;
}

