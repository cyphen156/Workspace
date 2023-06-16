#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    char sex;
    int age;
    double weight;
    // 아직 문자 배열에 대해 공부하지 않았으므로 한 문자만입력해야 정상적인 연산이 가능합니다.
    printf("Enter sex (M or F), age, and weight.\n"); 
    if (scanf("%c %d %lf", &sex, &age, &weight) != 3)
        printf("Error in input format.");
    else {
        printf("Sex: %c, Age: %d, Weight: %.2lf\n", sex, age, weight);
    }
    return 0;
}