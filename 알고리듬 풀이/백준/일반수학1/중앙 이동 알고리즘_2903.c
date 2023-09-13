#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int power(int N);

int main() {
    int N;
    scanf("%d", &N);

    printf("%d", power(N));
    return 0;
}

int power(int N) {

    int result = 1;
    for (int i = N; i > 0; i--) {
        result *= 2;
    }
    result = 1 + result;
    return result * result;
}