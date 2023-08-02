#define _CRT_SECURE_NO_WARNINGS
/*
    백준 11478 서로 다른 부분 문자열의 개수
    서로 다른 부분 연속된 문자열로 분해
    ex) S = ababc;
    S' = a, b, a, b, c, ab, ba, ab, bc, aba, bab, abc, abab, babc, ababc = 15
    result = a, b, c, ab, ba, bc, aba, bab, abc, abab, babc, ababc = 12

    생성될 수 있는 모든 경우의 수는 1 + 2 + 3 + ... + 1000
    -> 등차 수열의 합 1001 * 500

    1차 알고리즘 브루트포스
 */
/*
    제한사항
    ***
    라이브러리는 stdio.h만 사용
    struct 구조 사용불가
    ***
    0 < len <= 1,000
*/
/*
    문제 풀이 시간 : 20분
*/

// 브루트 포스
#include <stdio.h>

char s[1000];   //원본 문자열
char S2[1000][1000];    //부분 문자열
int S_len = 0;  // 부분 문자열 배열의 길이

int strcmp(char* s1, char* s2);
int strlen(char* s);
void strcpy(char* dest, char* src, int len);

int main() {
    int cnt = 0;

    scanf("%s", s);
    int len = strlen(s);

    // 모든 부분 문자열을 생성
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            strcpy(S2[S_len++], s + i, j - i + 1);
        }
    }

    // 중복되지 않은 부분 문자열의 수를 계산
    for (int i = 0; i < S_len; i++) {
        int unique = 1;
        for (int j = 0; j < i; j++) {
            if (strcmp(S2[i], S2[j]) == 1) {
                unique = 0;
                break;
            }
        }
        cnt += unique;
    }

    printf("%d\n", cnt);
    return 0;
}

int strcmp(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2)
        return 0;
    for (int i = 0; i < len1; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}

int strlen(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void strcpy(char* dest, char* src, int len) {
    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}