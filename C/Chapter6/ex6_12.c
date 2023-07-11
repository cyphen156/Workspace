#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch;
    printf("Enter a character.\n");
    for(ch = getchar(); ch != EOF; getchar()) {
        if (islower(ch))
            ch = toupper(ch);
        putchar(ch);
        putchar('\n');
        getchar();
        printf("Enter a character.\n");
    }    
    return 0;
}