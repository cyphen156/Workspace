#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int try(int a, int b) {
    printf("Inside try, a at %p, b at %p.\n", &a, &b);
    printf("Inside try, a = %d, b = %d.\n", a, b);
    a++; b++;
    printf("Upon increasing, a = %d, b = %d.\n\n", a, b);
    return;
}
int main() {
    int first, second, sum;
    printf("Enter two integers.\n");
    scanf("%d%d", &first, &second);
    sum = sq_add(first, second);
    printf("The result is %d.\n", sum);
    return 0;
}