#define _CRT_SECURE_NO_WARNINGS
/*
    백준 10989 수 정렬하기 3
    배열의 크기가 2때보다 더 커졋다 <--함정
    대신 수의 범위가 작아졌고, 중복이 생겻다

    이전 문제는 시간제한이 2초 지금 문제는 5초 -> 배열의 크기가 5배 늘어났으니 같은 방식으로 해결 불가능
    -> 중복이 가능하니 cnt 누적, 10000개의 배열로 처리 가능
*/
/*
    제한사항
    line 1 : N
    line 2 : x1 x2 x3 ...xn

    0 < N <= 10,000,000 -> lld입력
    0 <= K <= 10,000
    */
/*
    문제 풀이 시간 : 5분
*/

#include <stdio.h>

int main() {
    int N;
    long long int arr[10001] = { 0 };  // 입력수 카운팅
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int K;
        scanf("%d", &K);
        // 계수 누적
        arr[K]++;
    }

    for (int i = 0; i < 10001; i++) {
        while (arr[i] > 0) {
            printf("%d\n", i);
            arr[i]--;
        }
    }

    return 0;
}
