#define _CRT_SECURE_NO_WARNINGS
/*
    백준 10101 삼각형 외우기
    Equilateral = 정삼각형
    Isosceles = 이등변 삼각형
    Scalene 그냥 삼각형
*/ 
/*
    제한사항
    0 < n < 180
*/
#include <stdio.h>

int main() {
    int angle[3], sum = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &angle[i]);
        sum += angle[i];
    }
    if (sum != 180) {
        printf("Error");
    }
    else if (angle[0] == angle[1] && angle[1] == angle[2]) {
        printf("Equilateral");
    }
    else if (angle[0] == angle[1] || angle[0] == angle[2] || angle[1] == angle[2]) {
        printf("Isosceles");
    }
    else {
        printf("Scalene");
    }
    return 0;
}
