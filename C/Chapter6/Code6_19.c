#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int n = 0;
    char s[1000];

    printf("Enter a sentence.\n");
    fgets(s, sizeof(s), stdin);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
            || s[i] == 'o' || s[i] == 'u')
            n++;
    }
    printf("Vowel appears %d times.", n);
    return 0;
}