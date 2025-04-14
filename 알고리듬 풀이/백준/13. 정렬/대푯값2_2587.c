#define _CRT_SECURE_NO_WARNINGS
/*
    백준 2587 대푯값 2
    평균 = 모든 수의 합을 수의 개수
    중앙값 = 순서대로 놓았을때 가운데
    -> 
    1. 정렬 
    2. 길이 / 2 만약 짝수이면 앞의 숫자
*/
/*
    제한사항
    line = 5
    0 < N <= 100
    N % 10 == 0;
*/
/*
    문제 풀이 시간 : 5분
*/
#include <stdio.h>

int main() {
    int arr[5] = { 0 }, avg = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        avg += arr[i];
    }
    for (int i = 0; i < 5-1; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    avg /= 5;
    printf("%d\n", avg);
    printf("%d", arr[2]);
    return 0;
}

