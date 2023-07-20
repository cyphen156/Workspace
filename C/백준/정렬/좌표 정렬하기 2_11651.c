#define _CRT_SECURE_NO_WARNINGS
/*
    백준 11651 좌표 정렬하기2
    2차원 평면 점 N개
    Y, X순으로 오름차순 정렬
*/
/*
    제한사항
    1 ≤ N ≤ 100,000
    -100,000 ≤ x, y ≤ 100,000
    좌표는 항상 정수이고, 위치가 같은 두 점은 없다.
*/
/*
    문제 풀이 시간 : 5분
*/
#include <stdio.h>

int arr[100000][2], temp[100000][2];

// void insertion_sort(int n);
// void swap(int* a, int* b);
// int partition(int low, int high);
// void quick_sort(int low, int high);
void merge(int left, int mid, int right);
void merge_sort(int left, int right);

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }
    return 0;
}
/*
void insertion_sort(int n) {
    int i, j, key[2];
    for (i = 1; i < n; i++) {
        key[0] = arr[i][0];
        key[1] = arr[i][1];
        j = i - 1;

        while (j >= 0 && (arr[j][0] > key[0] || (arr[j][0] == key[0] && arr[j][1] > key[1]))) {
            arr[j + 1][0] = arr[j][0];
            arr[j + 1][1] = arr[j][1];
            j = j - 1;
        }
        arr[j + 1][0] = key[0];
        arr[j + 1][1] = key[1];
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int low, int high) {
    int pivot[2] = { arr[high][0], arr[high][1] };
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j][0] < pivot[0] || (arr[j][0] == pivot[0] && arr[j][1] < pivot[1])) {
            i++;
            swap(&arr[i][0], &arr[j][0]);
            swap(&arr[i][1], &arr[j][1]);
        }
    }
    swap(&arr[i + 1][0], &arr[high][0]);
    swap(&arr[i + 1][1], &arr[high][1]);
    return (i + 1);
}

void quick_sort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);

        quick_sort(low, pi - 1);
        quick_sort(pi + 1, high);
    }
}
*/

void merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i][1] < arr[j][1] || (arr[i][1] == arr[j][1] && arr[i][0] < arr[j][0])) {
            temp[k][0] = arr[i][0];
            temp[k][1] = arr[i][1];
            i++;
        }
        else {
            temp[k][0] = arr[j][0];
            temp[k][1] = arr[j][1];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k][0] = arr[i][0];
        temp[k][1] = arr[i][1];
        i++;
        k++;
    }
    while (j <= right) {
        temp[k][0] = arr[j][0];
        temp[k][1] = arr[j][1];
        j++;
        k++;
    }
    for (int i = left; i <= right; i++) {
        arr[i][0] = temp[i][0];
        arr[i][1] = temp[i][1];
    }
}

void merge_sort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
}
