#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int input, result1, result2, case1, case2, case3;
    printf("Enter a natural number.\n");
    scanf("%d", &input);
    getchar();
    result1 = input % 5;
    result2 = input % 6;
    if (result1 == 0 || result2 == 0)
        case1 = 1;
    else
        case1 = 0;
    if (result1 == 0 && result2 == 0)
        case2 = 1;
    else
        case2 = 0;
    if (result1 != 0 && result2 != 0)
        case3 = 1;
    else
        case3 = 0;
    printf("%d\n%d\n%d\n", case1, case2, case3);
    return 0;
}