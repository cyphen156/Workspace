#define _CRT_SECURE_NO_WARNINGS
/*
    백준 1181 단어 정렬
    문자열 관련 함수를 사용할수 없다
    -> 직접 하나하나 비교 && 문자열의 길이 체크
    s1 == s2 이면 s2는 어딘가로 버리기 -> 부울린 형 변수 필요?
    우선 이차원 배열로 단어마다 길이를 집어 넣어줌
*/
/*
    제한사항
    1 ≤ N ≤ 20,000
    0 < s <= 50
*/
/*
    문제 풀이 시간 : 40분
*/
#include <stdio.h>

char s[20000][51];  // 각 단어를 저장
int len[20000] = { 0 };  // 각 단어의 길이를 저장

// 병합 정렬을 위한 임시 배열
char temp_s[20000][51];
int temp_len[20000] = { 0 };

// 문자열 비교 함수
int strcmp(char* a, char* b) {
    int i = 0;
    while (a[i] == b[i]) {
        if (a[i] == '\0') return 0;
        i++;
    }
    return a[i] - b[i];
}

// 문자열 복사 함수
void strcpy(char* dest, char* src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') i++;
}

// 병합 함수
void merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        // 먼저 길이를 비교
        if (len[i] < len[j] || (len[i] == len[j] && strcmp(s[i], s[j]) < 0)) {
            strcpy(temp_s[k], s[i]);
            temp_len[k] = len[i];
            i++;
        }
        else {
            strcpy(temp_s[k], s[j]);
            temp_len[k] = len[j];
            j++;
        }
        k++;
    }

    // 남은 요소들 복사
    while (i <= mid) {
        strcpy(temp_s[k], s[i]);
        temp_len[k] = len[i];
        i++;
        k++;
    }
    while (j <= right) {
        strcpy(temp_s[k], s[j]);
        temp_len[k] = len[j];
        j++;
        k++;
    }

    // 정렬된 배열 복사
    for (i = left; i <= right; i++) {
        strcpy(s[i], temp_s[i]);
        len[i] = temp_len[i];
    }
}

// 병합 정렬 함수
void merge_sort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; s[i][j] != '\0'; j++) {
            len[i]++;
        }
    }

    merge_sort(0, n - 1);

    // 중복된 단어를 제거하면서 출력
    printf("%s\n", s[0]);
    for (int i = 1; i < n; i++) {
        if (strcmp(s[i - 1], s[i]) != 0) {
            printf("%s\n", s[i]);
        }
    }

    return 0;
}
