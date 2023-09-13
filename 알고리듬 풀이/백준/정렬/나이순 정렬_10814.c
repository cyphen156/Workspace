#define _CRT_SECURE_NO_WARNINGS
/*
    백준 10814 나이순 정렬
    정렬기준
    -> 나이, 가입 순서
    2가지 인덱싱
    해결 아이디어
    나이 - 인덱스, 인덱스 - 이름 구조의 이차원 배열
    -> 계수정렬 사용
    효율적인 인덱싱을 위한 계수배열 cnt생성
*/
/*
    제한사항
    ***
    라이브러리는 stdio.h만 사용
    struct 구조 사용불가
    ***
    1 ≤ N ≤ 100,000
    나이 이름
    0 < age <= 200
    name = ALPHA
    0 < name_len <= 100
*/
/*
    문제 풀이 시간 : 30분
*/
#include <stdio.h>

int age[201][100000];
char name[100000][101];
int age_cnt[201] = { 0 };

int main() {
    int n, age_input;
    scanf("%d", &n);

    // 입력
    for (int i = 1; i <= n; i++) {
        scanf("%d %s", &age_input, name[i]);
        age_cnt[age_input]++;
        age[age_input][age_cnt[age_input] - 1] = i;
    }

    for (int i = 1; i < 201; i++) {
        for (int j = 1; j <= age_cnt[i]; j++) {
            printf("%d %s\n", i, name[age[i][j - 1]]);
        }
    }
    return 0;
}
