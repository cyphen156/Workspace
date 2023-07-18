#define _CRT_SECURE_NO_WARNINGS
/*
    백준 2750 수 정렬하기
    N개의 수 
    오름차순 정렬
*/
/*
    제한사항
    1 <= N <= 1,000
    1 <= |number| <= 1,000
*/
/*
    문제 풀이 시간 : 5분
*/
#include <stdio.h>

int main() {
    int N, arr[1000] = { 0 };

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

