/**
* 백준 음계 2920
* 
* 간단한 순차 문제
* 
* 오름차순이면 ascending
* 내림차순이면 descending
* 둘다 아니라면 mixed 
* 
* 
* 제한사항
*****************************************
* 1 <= N <= 8							*
* N(K) is unique						*
*****************************************
* 
* 
* 
* 주의
* 
* 풀이시간 10분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int arr[8];
    for (int i = 0; i < 8; ++i) {
        scanf("%d", &arr[i]);
    }

    int ascending = 1, descending = 1;
    for (int i = 1; i < 8; ++i) {
        if (arr[i - 1] < arr[i]) {
            descending = 0;
        }
        else if (arr[i - 1] > arr[i]) {
            ascending = 0;
        }
    }

    if (ascending) {
        printf("ascending");
    }
    else if (descending) {
        printf("descending");
    }
    else {
        printf("mixed");
    }

    return 0;
}
