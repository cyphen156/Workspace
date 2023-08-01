#define _CRT_SECURE_NO_WARNINGS
/*
    백준 10816 숫자 카드 2
    중복이 허용되는 숫자카드
    숫자 범위는 20,000,001
    입력 갯수는 500,000 * 2개

    사용할 수 있는 방법은 이진트리를 통한 탐색과
    계수 정렬을 통한 인덱싱
    ->
    메모리를 희생해서 검색시간을 줄인다.
    메모리 제한사항은  256MB라 충분하니까
*/
/*
    제한사항
    ***
    라이브러리는 stdio.h만 사용
    struct 구조 사용불가
    ***
    1 ≤ N ≤ 500,000
    -10,000,000 <= x <= 10,000,000
    1 ≤ M ≤ 500,000
    -10,000,000 <= x2 <= 10,000,000
*/
/*
    문제 풀이 시간 : 10분
*/

#include <stdio.h>

int arr[20000001];
int arr2[500000];

int main() {
    int n, m;

    scanf("%d", &n);
    if (n > 500000)
        return -1;

    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr[tmp+10000001]++;
    }

    scanf("%d", &m);
    if (m > 500000)
        return -1;
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < m; i++) {
        printf("%d", arr[arr2[i] + 10000001]);
    }
    return 0;
}