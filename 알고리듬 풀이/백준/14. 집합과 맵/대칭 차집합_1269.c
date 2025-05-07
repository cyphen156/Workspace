#define _CRT_SECURE_NO_WARNINGS
/*
    백준 1269 대칭 차집합
    두 집합 A, B가 있을때
    A-B + B-A의 합집합을 A와 B의 대칭 차집합
    -> A + B - (A && B)
    -> 중복을 제거하는 과정이 필요하다

    첫 번째 알고리즘
    집합은 중복이 존재하지 않는다. 
    -> 계수정렬 사용가능
    0/1로 활성화
    A + B과정중 cnt, len변수를 통해 A && B, A + B의 갯수 카운팅 가능

    **********************************************
    * 메모리 사용량 800mb로 너무 거대함 축소 필요*
    * ********************************************
    
    두 번째 알고리즘
    두 개의 [2000000] 배열 생성
    A와 B 정렬, 순차 탐색
    */
/*
    제한사항
    ***
    라이브러리는 stdio.h만 사용
    struct 구조 사용불가
    ***
    0 < 집합의 원소 갯수 <= 200,000
    0 < x <= 100,000,000
*/
/*
    문제 풀이 시간 : 30분
*/
/*
* 
1차 코드
#include <stdio.h>

int arr[100000000] = { 0 }, arr2[100000000] = { 0 };

int main() {
    int n, m, tmp;  //집합 A 원소갯수 n, B의 원소갯수 m, 입력변수 tmp,
    int max = 0;    //인덱싱 범위 축소용 합집합 카운트 변수 max
    int cnt = 0, len = 0;   // A && B, A + B

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        if (tmp > max)
            max = tmp;
        arr[tmp] = 1;
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &tmp);
        if (tmp > max)
            max = tmp;
        arr2[tmp] = 1;
    }

    //A + B와 A && B 연산
    for (int i = 0; i <= max; i++) {
        if (arr[i] != 0 || arr2[i] != 0) {
            len++;
            if (arr[i] == arr2[i])
                cnt++;
        }
    }
    printf("%d", len - cnt);
    return 0;
}
*/

#include <stdio.h>

int arr[200000] = { 0 }, arr2[200000] = { 0 };
int tmp[200000];

void merge(int arr[], int start, int mid, int end);
void mergeSort(int arr[], int left, int right);

int main() {
    int n, m;  //집합 A 원소갯수 n, B의 원소갯수 m
    int max = 0;    //인덱싱 범위 축소용 합집합 카운트 변수 max
    int cnt = 0, len = 0;   // A && B, A + B

    scanf("%d %d", &n, &m);
    for (int i = 0;i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    mergeSort(arr, 0, n - 1);
    mergeSort(arr2, 0, m - 1);

    //A + B와 A && B 연산
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr[i] < arr2[j]) {
            i++;
        }
        else if (arr[i] > arr2[j]) {
            j++;
        }
        else {
            i++;
            j++;
            cnt++;
        }
    }

    printf("%d", (n + m - 2 * cnt));
    return 0;
}

void merge(int arr[], int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        }
        else {
            tmp[k++] = arr[j++];
        }
    }

    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= end)
        tmp[k++] = arr[j++];

    for (int t = start; t <= end; t++)
        arr[t] = tmp[t];
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}