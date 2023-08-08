#define _CRT_SECURE_NO_WARNINGS
#define true 1
#define false 0

#include <stdio.h>

// 윤년인지 평년인지 판단하는 함수
int leap_year(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || (y % 4 == 0 && y % 400 == 0))
        // 4로 나누어떨어지는 도잇에 100으로 나누어떨어지지 않거나,
        // 4로 나누어 떨어지는 동시에 400으로 나누어떨어지면 윤년
        return true;
    else
        return false;
}

int main() {
    int year;
    while (1)
    {
        printf("Enter year.\n");
        scanf("%d", &year);
        if (year == -1)
            break;
        if (leap_year(year))
            printf("It is a leap year.\n");
        else
            printf("It is NOT a leap year.\n");
    }
    return 0;
}