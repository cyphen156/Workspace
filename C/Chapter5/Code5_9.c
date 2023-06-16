#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void is_even_or_odd(int num);

int main(void) {
    int num;
    printf("Enter an integer.\n");
    scanf("%d", &num);
    is_even_or_odd(num);
    return 0;
}

void is_even_or_odd(int num){
    if (num & 1)
        printf("It is an odd number.\n");
    else
        printf("It is an even number.\n");
}