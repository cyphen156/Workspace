#include <stdio.h>

int main(void) {
    int a = 0;
    int b = a;

    printf("%p", a);
    printf("%p", b);

    return 0;
}