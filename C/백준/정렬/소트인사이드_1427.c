#define _CRT_SECURE_NO_WARNINGS
/*
    백준 1427 소트인사이드
    배열 내림차순으로 정렬하기
    계수 정렬 사용
*/
/*
    제한사항
    0 < N <= 1,000,000,000
*/
/*
    문제 풀이 시간 : 10분
*/
#include <stdio.h>

int main() {
    char n;
    int arr[10] = { 0 };

    for (int i = 0; i < 10; i++) {
        scanf("%c", &n);
        if (n == '\n') {
            break;
        }
        arr[n - '0']++;
    }
    for (int i = 9; i >= 0; i--) {
        while (arr[i] != 0) {
            printf("%d", i);
            arr[i]--;
        }
    }
    return 0;
}
/*
#include <stdio.h>

 2nd 아이디어 전역변수를 통한 소팅 데이터 유지
<- 시스템 에러 배열 크기가 0x7fffffff이상
int arr[1000000000] = { 0 }; 
/*
int main() {
    char n;
    long long len = 0;
    int tmp_arr[10] = { 0 };
    for (int i = 0; n != '\0'; i++) {
        scanf("%c", &n);
        if (n == '\n') {
            break;
        }
        tmp_arr[n - '0']++;
        len++;
    }

    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < tmp_arr[i]; j++) {
            arr[len - 1] = i;
            len--;
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
    }
    return 0;
}*/
