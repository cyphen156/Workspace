#include <stdio.h>

int main(void) {
    int a = 0;
    int b = a;

    printf("%p\n", &a);
    printf("%p\n", &b);

    return 0;
}