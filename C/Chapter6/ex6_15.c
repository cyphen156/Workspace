#define _CRT_SECURE_NO_WARNINGS
#define true 1
#define false 0

#include <stdio.h>

int main(void) {
    int max, num, i, is_prime;

    printf("Enter an integer larger than 1.\n");
    scanf("%d", &max);
    for (num = 2; num <= max; num++) {
        is_prime = true;
        for (i = 2; i < num; i++) {
            if (num % i == 0) 
                is_prime = false;
                break;
        }
        is_prime ? printf("%d is a prime number.\n", num) : 
                    printf("%d is NOT a prime number.\n", num);
    }    
    return 0;
}