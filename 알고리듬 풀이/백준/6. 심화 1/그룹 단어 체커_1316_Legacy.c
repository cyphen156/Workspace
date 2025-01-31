#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    int len, cnt = 0;
    scanf("%d", &len);

    for (int i = 0; i < len; i++) {
        char s[101] = { 0 };
        int alpha[26] = { 0 };
        scanf("%s", s);

        for (int j = 0; s[j] != '\0'; j++) {
            if (alpha[s[j] - 'a'] == 0) {
                alpha[s[j] - 'a'] = 1;
            }
            else if (alpha[s[j] - 'a'] == 1 && s[j] != s[j - 1]) {
                alpha[s[j] - 'a'] = -1;
            }
        }

        cnt++;
        for (int j = 0; j < 26; j++) {
            if (alpha[j] == -1) {
                cnt--;
                break;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}