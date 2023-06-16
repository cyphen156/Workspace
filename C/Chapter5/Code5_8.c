#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void is_alpha(char c);

int main(void) {
    char c;
    printf("Enter a character.\n"); 
    scanf("%c", &c);
    is_alpha(c);
    return 0;
}

void is_alpha(char c) {
    if (c >= '0' && c <= '9')
        printf("It is a digit.\n");
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        printf("It is an alphabet\n");
    else
        printf("It is neither an alphaber nor a digit.\n");
}