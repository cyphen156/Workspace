#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int leap_year(int y);

int main(void) {
    int year;
    printf("Enter year.\n");
    scanf("%d", &year);
    if (leap_year(year) == 1)
        printf("It is a leap year.\n");
    else
        printf("It is not a leap year.\n");
    return 0;
}

int leap_year(int y) {
    if (y % 4 == 0) {
        if (y % 100 != 0 || y % 400 == 0)
            return 1;
    }
    else return 0;
}