#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void calc(int x, int y);

int main(void) {
    int x, y;
    printf("Enter the x, y coordinates of the point.\n");
    scanf("%d %d", &x, &y);
    calc(x, y);
    return 0;
}

void calc(int x, int y) {
    if (x == 0 || y == 0) {
        printf("점은 사분면 위에 있지 않고 수직선 위에 존재합니다.");
    }
    else {
        if (x > 0) {
            if (y > 0)
                printf("It's in the 1st quadrant.");
            else 
                printf("It's in the 4th quadrant.");
        }
        else {
            if (y > 0)
                printf("It's in the 2nd quadrant.");
            else
                printf("It's in the 3rd quadrant.");
        }
    }
}