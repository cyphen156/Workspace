#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    int input;
    scanf("%d", &input);
    if (input < 1000 || input > 3001) {
        printf("Error 불기연도 입력 오류");
        return 0;
    }
    printf("%d", input - 543);
    return 0;
}
