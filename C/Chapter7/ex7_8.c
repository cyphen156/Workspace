#define _CRT_SECURE_NO_WARNINGS
#define true 1
#define false 0

#include <stdio.h>

int leap_year(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || (y % 4 == 0 && y % 400 == 0))
        return true;
    else
        return false;
}

// 금년 1월 1일부터 전달 말일까지 날짜 수
int to_last_month(int year, int month) {
    int i, total = 0;

    for (i = 1; i <= (month - 1); i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
            total += 31;                // 큰 달이면 31일
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            total += 30;                // 작은 달이면 30일
        else {
            if (leap_year(year))
                total += 29;            //2월은 평년, 윤년을 반영
            else 
                total += 28;
        }
    }
    return total;
}

int main() {
    int year, month;

    while (1)
    {
        printf("Enter year and month.\n");
        scanf("%d%d", &year, &month);
        if (year == -1) 
            break;
        printf("Fsud up yo lsdy month is %d.\n", 
                    to_last_month(year, month));
    }
    return 0;
}