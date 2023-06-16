#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

float float_calculate(float a, float b, char op);

int int_calculate(int a, int b, char op);

int main(void) {
    char ch;
    int mode;
    float a, b;
    printf("Enter 1 for floating point calculation, 2 for integer calculation.\n");
    scanf("%d", &mode);
    if (mode != 1 && mode != 2) {
        printf("계산기 모드는 1 또는 2를 입력해야만 합니다. 프로그램을 종료합니다.\n");
        return -1;
    }
    printf("Enter an expression. For EXAMPLE, 2 + 5.\n");
    scanf("%f %c %f", &a, &ch, &b);
    if (mode == 1)
        printf("%f %c %f = %f", a, ch, b, float_calculate(a, b, ch));
    else
        printf("%d %c %d = %d", (int)a, ch, (int)b, int_calculate(a, b, ch));
    return 0;
}

float float_calculate(float a, float b, char op) {
    switch (op) {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        if (b != 0) return a / b;
        else {
            printf("에러 :: 분모는 0이어선 안됩니다.\n");
            return -1;
        }
    case '%':
        if (b != 0) return (int)a % (int)b;
        else {
            printf("에러 :: 분모는 0이어선 안됩니다.\n");
            return -1;
        }
    default:
        printf("에러 연산자가 비정상적입니다. 프로그램을 종료합니다.\n");
        return -1;
    }
}

int int_calculate(int a, int b, char op) {
    switch (op) {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        if (b != 0) return a / b;
        else {
            printf("에러 :: 분모는 0이어선 안됩니다.\n");
            return -1;
        }
    case '%':
        if (b != 0) return (int)a % (int)b;
        else {
            printf("에러 :: 분모는 0이어선 안됩니다.\n");
            return -1;
        }
    default:
        printf("에러 연산자가 비정상적입니다. 프로그램을 종료합니다.\n");
        return -1;
    }
}