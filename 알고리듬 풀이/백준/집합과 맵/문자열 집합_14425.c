#define _CRT_SECURE_NO_WARNINGS
/*
    백준 14425 문자열 집합
    N개의 문자열 집합체 S
    M개의 문자열 입력
    S에 포함된 것은 총 몇개?

    문자열을 직접 저장하면 문자열 비교가 너무 빡세진다
    -> 첫단어를 기준으로 그룹화 수행
*/
/*
    제한사항
    ***
    라이브러리는 stdio.h만 사용
    struct 구조 사용불가
    ***
    1 ≤ N ≤ 10,000
    1 ≤ M ≤ 10,000
    N ⊂ S
    M ∈ S
    String == lower alpha
    0 < len <= 500
    input1 != input2
    */
/*
    문제 풀이 시간 : 20분
*/
//#include <stdio.h>
//
//char dict[26][10000][501];
//int dict_count[26] = { 0 };
//
//void strcpy(char* dest, char* src);
//
//int main(void) {
//    int N, M;
//    int cnt = 0;
//
//    scanf("%d %d", &N, &M);
//
//    for (int i = 0; i < N; i++) {
//        char temp[501];
//        scanf("%s", temp);
//        int group = temp[0] - 'a';
//        strcpy(dict[group][dict_count[group]], temp);
//        dict_count[group]++;
//    }
//
//    for (int i = 0; i < M; i++) {
//        char s[501];
//        scanf("%s", s);
//        int group = s[0] - 'a';
//        for (int j = 0; j < dict_count[group]; j++) {
//            if (strcmp(s, dict[group][j]) == 0) {
//                cnt++;
//                break;
//            }
//        }
//    }
//    printf("%d", cnt);
//    return 0;
//}
//
//void strcpy(char* dest, char* src) {
//    int i = 0;
//    while (src[i] != '\0') {
//        dest[i] = src[i];
//        i++;
//    }
//    dest[i] = '\0';
//}
//
//int strcmp(char* s1, char* s2) {
//    int i = 0;
//    while (s1[i] != '\0' && s2[i] != '\0') {
//        if (s1[i] != s2[i]) {
//            return -1;
//        }
//        i++;
//    }
//    if (s1[i] == '\0' && s2[i] == '\0') {
//        return 0;
//    }
//    else {
//        return -1;
//    }
//}
#include <stdio.h>

#define MAXN 10000
#define MAXL 501

char dict[26][MAXN][MAXL];
int dict_count[26] = { 0 };
char s[MAXL];
char temp[MAXL];
char merge_temp[MAXN][MAXL]; // 병합 정렬 임시 배열

void strcpy(char* dest, char* src);
int strcmp(char* s1, char* s2);
void merge_sort(int l, int r, int idx);
void merge(int l, int m, int r, int idx);
int binary_search(int l, int r, char* val, int idx);

int main(void) {
    int N, M;
    int cnt = 0;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", temp);
        int group = temp[0] - 'a';
        strcpy(dict[group][dict_count[group]], temp);
        dict_count[group]++;
    }

    for (int i = 0; i < 26; i++) {
        if (dict_count[i] > 1) {
            merge_sort(0, dict_count[i] - 1, i);
        }
    }

    for (int i = 0; i < M; i++) {
        scanf("%s", s);
        int group = s[0] - 'a';
        if (binary_search(0, dict_count[group] - 1, s, group) != -1) {
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}

void strcpy(char* dest, char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
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

void merge_sort(int l, int r, int idx) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(l, m, idx);
        merge_sort(m + 1, r, idx);
        merge(l, m, r, idx);
    }
}

void merge(int l, int m, int r, int idx) {
    int i = l;
    int j = m + 1;
    int k = l;
    while (i <= m && j <= r) {
        if (strcmp(dict[idx][i], dict[idx][j]) <= 0) {
            strcpy(merge_temp[k], dict[idx][i]);
            i++;
        }
        else {
            strcpy(merge_temp[k], dict[idx][j]);
            j++;
        }
        k++;
    }
    while (i <= m) {
        strcpy(merge_temp[k], dict[idx][i]);
        i++;
        k++;
    }
    while (j <= r) {
        strcpy(merge_temp[k], dict[idx][j]);
        j++;
        k++;
    }
    for (i = l; i <= r; i++) {
        strcpy(dict[idx][i], merge_temp[i]);
    }
}

int binary_search(int l, int r, char* val, int idx) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (strcmp(dict[idx][mid], val) == 0) {
            return mid;
        }
        if (strcmp(dict[idx][mid], val) > 0) {
            return binary_search(l, mid - 1, val, idx);
        }
        return binary_search(mid + 1, r, val, idx);
    }
    return -1;
}
