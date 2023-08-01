#define _CRT_SECURE_NO_WARNINGS
/*
    백준 1620 나는야 포켓몬 마스터 이다솜
    일단 문제가 어지럽다
    핵심은 
    번호 -> 이름 
    또는 
    이름 -> 번호
    키 밸류 쌍
    자료구조
*/
/*
    제한사항
    ***
    라이브러리는 stdio.h만 사용
    struct 구조 사용불가
    ***
    0 <= M, N <= 100,000
    2 <= string <= 20
    String or StrinG 
*/
/*
    문제 풀이 시간 : 20분
*/

#include <stdio.h>

char s[100000][21];
char s2[100000][21];
int idx2[100000];
char input[100000][21];
char temp[100000][21];
int temp_idx[100000];

int strlen(char* s);
int isNumber(char* s);
int strcmp(char* a, char* b);
void strcpy(char* dest, char* src);
int atoi(char* s);
void merge(char arr[][21], int idx[], int left, int mid, int right);
void mergeSort(char arr[][21], int idx[], int left, int right);

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        strcpy(s2[i], s[i]);
        idx2[i] = i + 1;
    }

    mergeSort(s2, idx2, 0, n - 1);

    for (int i = 0; i < m; i++) {
        scanf("%s", input[i]);
    }

    for (int i = 0; i < m; i++) {
        if (isNumber(input[i])) {
            printf("%s\n", s[atoi(input[i]) - 1]);
        }
        else {
            for (int j = 0; j < n; j++) {
                if (strcmp(input[i], s2[j]) == 0) {
                    printf("%d\n", idx2[j]);
                    break;
                }
            }
        }
    }
    return 0;
}

int strlen(char* s) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}

int strcmp(char* a, char* b) {
    int i = 0;
    while (a[i] == b[i]) {
        if (a[i] == '\0') return 0;
        i++;
    }
    return  a[i] - b[i];
}

void strcpy(char* dest, char* src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') i++;
}

int isNumber(char* s) {
    for (int i = 0; i < strlen(s); i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) {
            return 0;
        }
    }
    return 1;
}

int atoi(char* s) {
    int i, num = 0;
    for (i = 0; s[i] != '\0'; i++)
        num = num * 10 + (s[i] - '0');
    return num;
}

void merge(char arr[][21], int idx[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (strcmp(arr[i], arr[j]) <= 0) {
            strcpy(temp[k], arr[i]);
            temp_idx[k] = idx[i];
            i++;
        }
        else {
            strcpy(temp[k], arr[j]);
            temp_idx[k] = idx[j];
            j++;
        }
        k++;
    }

    if (i > mid) {
        for (int t = j; t <= right; t++) {
            strcpy(temp[k], arr[t]);
            temp_idx[k] = idx[t];
            k++;
        }
    }
    else {
        for (int t = i; t <= mid; t++) {
            strcpy(temp[k], arr[t]);
            temp_idx[k] = idx[t];
            k++;
        }
    }

    for (int t = left; t <= right; t++) {
        strcpy(arr[t], temp[t]);
        idx[t] = temp_idx[t];
    }
}

void mergeSort(char arr[][21], int idx[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, idx, left, mid);
        mergeSort(arr, idx, mid + 1, right);
        merge(arr, idx, left, mid, right);
    }
}
