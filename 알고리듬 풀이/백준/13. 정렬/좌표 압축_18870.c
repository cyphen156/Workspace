#define _CRT_SECURE_NO_WARNINGS
/*
    백준 18870 좌표 압축
    N개의 좌표를 압축
    처음에는 잘 이해가 안된다
    예제들을 보면
    입력 1을 소팅하면
    -10 -9  2   4   4이지만
    출력이
    2   3   0   3   1
    즉 정렬될 때는 중복이 제거된다고 볼 수 있다.
    -> 여러 장의 수선 위에 표시된 점들을
    단 하나의 수선 위에 겹쳐서 표시하는 행위로 볼 수 있다.
    다시 이 위치에 따라 여러 장의 수선들을 순서대로 정렬해서 출력한다.
*/
/*
    제한사항
    ***
    라이브러리는 stdio.h만 사용
    struct 구조 사용불가
    ***
    1 ≤ N ≤ 1,000,000
    -10**9 ≤ Xi ≤ 10**9
*/
/*
    문제 풀이 시간 : 240분
*/
/*
    초기 아이디어
    arr
    2행 [입력 값]열의
    [idx][input]
    cnt
    2행 (input)열의
    [입력 값][정렬된 순서, default -1]

    *******************************************
    * 메모리 예상 사용량 8기가 바이트(4*10**9)*
    * 효율적인 메모리 사용 필요               *
    *******************************************

    #include <stdio.h>

    int arr[2][1000000];
    int cnt[2][20000001] = { 0 };

    int main() {
        int n, len = 0;
        scanf("%d", &n);

        // 입력
        for (int i = 0; i < n; i++) {
            arr[0][i] = i;  //혹시모를 쓰레기값 제거를 위한 초기화
            scanf("%d", &arr[1][i]);
            cnt[0][arr[1][i] + 1000000001]++;
        }

        // 입력값 길이 알아내기
        for (int i = 0; i < 20000001; i++) {
            if (cnt[0][i] != 0) {
                cnt[1][i] = len++;
            }
            else {
                cnt[1][i] = -1;
            }
        }
        //출력
        for (int i = 0; i < n; i++) {

        }
        return 0;
    }
*/
// 해결책
// 더 간단하게 생각하기
// 일차원 배열, 복사배열사용
// 분할 정복
#include <stdio.h>

int arr[1000000];
int arr2[1000000];
int sorted[1000000];
int unique[1000000];
int end_idx = 0;

void merge(int start, int mid, int end);
void mergeSort(int start, int end);
int binarySearch(int target);
void removeDuplicates();

int main(void) {
    int n;
    scanf("%d", &n);

    // 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr2[i] = arr[i];
    }

    // 정렬
    mergeSort(0, n - 1);

    // 중복값 제거
    removeDuplicates();

    // 원래 배열의 요소가 정렬된 배열에서 어느 위치에 있는지 찾아서 출력
    for (int i = 0; i < n; i++) {
        printf("%d ", binarySearch(arr2[i]));
    }

    return 0;
}

void merge(int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) sorted[k++] = arr[i++];
        else sorted[k++] = arr[j++];
    }
    while (i <= mid) sorted[k++] = arr[i++];
    while (j <= end) sorted[k++] = arr[j++];
    for (int t = start; t <= end; t++) arr[t] = sorted[t];
    end_idx = k - 1;
}

void mergeSort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
}

void removeDuplicates() {
    int j = 0;
    for (int i = 0; i <= end_idx; i++) {
        if (i == end_idx || sorted[i] != sorted[i + 1]) {
            sorted[j++] = sorted[i];
        }
    }
    end_idx = j - 1;
}

int binarySearch(int target) {
    int start = 0, end = end_idx;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (sorted[mid] == target) return mid;
        else if (sorted[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return 0;
}
