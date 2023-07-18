#define _CRT_SECURE_NO_WARNINGS
// 서로소 판별 -> 우선 공약수 1은 제외
#include <stdio.h>

char mutually_prime(int a, int b);

int main(void) {
    int a, b;
    char c;

    printf("Enter two numbers.\n");
    scanf("%d %d", &a, &b);

    c = mutually_prime(a, b);
    if (c == 'y')
        printf("They are mutually prime.");
    return 0;
}

char mutually_prime(int a, int b) {
    int min = a < b ? a : b;
    for (int i = 2; i <= min; i++) {
        if (a % i == 0 && b % i == 0)
            return 'n';
    }
    return 'y';
}
