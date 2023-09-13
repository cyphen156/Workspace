#define _CRT_SECURE_NO_WARNINGS
/*
    백준 1764 듣보잡
    듣+보 = 듣보
    듣과 보의 이름에 중복은 없다

    문자열 정렬
    병합 정렬 사용
*/
/*
    제한사항
    ***
    라이브러리는 stdio.h만 사용
    struct 구조 사용불가
    ***
    0 < 듣 = N <= 500,000
    0 < 보 = M <= 500,000
    0 < 이름길이 <= 20
*/
/*
    문제 풀이 시간 : 40분
*/

#include <stdio.h>

char s[500000][21];
char s2[500000][21];
char res[500000][21];
char temp[500000][21];

int strcmp(char* a, char* b);
void strcpy(char* a, char* b);
void merge(int start, int mid, int end, char arr[500000][21]);
void mergesort(int start, int end, char arr[500000][21]);

int main() {
    int n, m, cnt = 0, i = 0, j = 0;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%s", s2[i]);
    }

    mergesort(0, n - 1, s);
    mergesort(0, m - 1, s2);

    while (i < n && j < m) {
        if (strcmp(s[i], s2[j]) == 0) {
            strcpy(res[cnt++], s[i]);
            i++; j++;
        }
        else if (strcmp(s[i], s2[j]) < 0) {
            i++;
        }
        else {
            j++;
        }
    }

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", res[i]);
    }

    return 0;
}

int strcmp(char* s1, char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (s1[i] < s2[i]) ? -1 : 1;
        }
        i++;
    }
    return (s1[i] == s2[i]) ? 0 : ((s1[i] < s2[i]) ? -1 : 1);
}

void strcpy(char* dest, char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void merge(int start, int mid, int end, char arr[500000][21]) {
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end) {
        if (strcmp(arr[i], arr[j]) < 0) {
            strcpy(temp[k++], arr[i++]);
        }
        else {
            strcpy(temp[k++], arr[j++]);
        }
    }
    while (i <= mid)
        strcpy(temp[k++], arr[i++]);
    while (j <= end)
        strcpy(temp[k++], arr[j++]);
    for (i = start; i <= end; i++)
        strcpy(arr[i], temp[i]);
}

void mergesort(int start, int end, char arr[500000][21]) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergesort(start, mid, arr);
        mergesort(mid + 1, end, arr);
        merge(start, mid, end, arr);
    }
}