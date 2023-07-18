#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 미세 오차가 확인되지 않는 코드
// int main(void) {
//    int n;
//    float sum = 0.0;
//    printf("Enter the number of iteration.\n");
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++) {
//        sum += 1.0 / n;
//    }
//    printf("1/%d summed up %d times is %f.\n", n, n, sum);
//    return 0;
//}

// 오차 확인 가능한 코드
int main(void) {
    int n;
    double sum = 0.0;
    double unit;
    printf("Enter the number of iteration.\n");
    scanf("%d", &n);
    unit = 1.0 / n;
    for (int i = 1; i <= n; i++) {
        sum += unit;
    }
    printf("1/%d summed up %d times is %.16f.\n", n, n, sum);
    return 0;
}
