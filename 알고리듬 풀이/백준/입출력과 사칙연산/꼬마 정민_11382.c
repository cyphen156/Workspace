#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    long long first, second, third;
    scanf("%lld %lld %lld", &first, &second, &third);
    printf("%lld", first + second + third);
    return 0;
}