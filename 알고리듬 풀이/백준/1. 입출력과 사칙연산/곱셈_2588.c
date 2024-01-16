#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void calc(int first, int second){
    printf("%d\n", first * (second % 10));
    printf("%d\n", first * ((second % 100) / 10));
    printf("%d\n", first * (second / 100));
    printf("%d", first * second);
}
int main() {
    int first, second;
    scanf("%d %d", &first, &second);
    calc(first, second);
    return 0;
}