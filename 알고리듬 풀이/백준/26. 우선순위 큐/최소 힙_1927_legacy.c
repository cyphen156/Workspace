/*
	최소 힙
	배열에 자연수 x를 넣고, 작은 값 출력, 제거
	-> 노드 생성, &제거

	제한사항
	0 < n <= 100,001
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int arrsize = 0;

void push(int* arr, int size, int n) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] >= n) {
            break;
        }
    }
    for (int j = size; j > i; j--) {
        arr[j] = arr[j - 1];
    }
    arr[i] = n;
}

void pop(int* arr, int size) {
    if (size == 0) {
        printf("0\n");
        return;
    }

    printf("%d\n", arr[0]);
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arrsize--;
}

int main() {
    unsigned int t;
    scanf("%d", &t);
    int* result = (int*)calloc(t, sizeof(int));
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);

        if (n == 0) {
            pop(result, arrsize);
        }
        else {
            push(result, arrsize, n);
            arrsize++;
        }
    }
    free(result);
    return 0;
}