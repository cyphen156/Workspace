#define _CRT_SECURE_NO_WARNINGS
/*
    백준 10815 숫자 카드
    정수 한개가 적혀있는 카드 N개, 
    정수 M개를 주어 있는지 탐색
    사용하는 배열은 2개
    순차 탐색은 너무 오래걸림
    효율적인 탐색
*/
/*
    제한사항
    ***
    라이브러리는 stdio.h만 사용
    struct 구조 사용불가
    ***
    0 < N <= 500,000
    0 ≤ M ≤ 500,000
    -10,000,000 <= input <= 10,000,000
    input1 != input2
    return 1 || 0
    */
/*
    문제 풀이 시간 : 20분
*/

#include <stdio.h>

int Narr[500000];
int Marr[500000];
int temp[500000];

void merge(int s, int m, int e);
void merge_sort(int s, int e);
int b_search(int s, int e, int find);

int main(void) {
    int N, M;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Narr[i]);
    }
    merge_sort(0, N - 1);

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &Marr[i]);
    }

    for (int i = 0; i < M; i++) {
        if (b_search(0, N - 1, Marr[i])) {
            printf("1 ");
        }
        else {
            printf("0 ");
        }
    }
    return 0;
}

void merge(int s, int m, int e) {
    int part1 = s;
    int part2 = m + 1;
    int index = s;

    while (part1 <= m && part2 <= e) {
        if (Narr[part1] <= Narr[part2]) {
            temp[index] = Narr[part1];
            part1++;
        }
        else {
            temp[index] = Narr[part2];
            part2++;
        }
        index++;
    }

    for (int i = part1; i <= m; i++) {
        temp[index] = Narr[i];
        index++;
    }

    for (int i = part2; i <= e; i++) {
        temp[index] = Narr[i];
        index++;
    }

    for (int i = s; i <= e; i++) {
        Narr[i] = temp[i];
    }
}


void merge_sort(int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        merge_sort(s, m);
        merge_sort(m + 1, e);
        merge(s, m, e);
    }
}

int b_search(int s, int e, int find) {
    while (s <= e) {
        int m = (s + e) / 2;
        if (Narr[m] == find) {
            return 1;
        }
        else if (Narr[m] > find) {
            e = m - 1;
        }
        else {
            s = m + 1;
        }
    }
    return 0;
}