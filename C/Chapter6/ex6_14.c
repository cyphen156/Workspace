#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch, state;

    state = 0;
    printf("Enter a sentence in lower-case letter.\n");
    for (ch = getchar(); ch != '\n'; ch = getchar()) {
        switch (state) {
            case 0:
                if (isalpha(ch)) {
                    putchar(toupper(ch));
                    state = 1;
                } 
                else 
                    putchar(ch);
                break;
            case 1: 
                putchar(ch);
                if (!iswalpha(ch))
                    state = 0;
                break;
        }
    }
    putchar('\n');
    return 0;
}