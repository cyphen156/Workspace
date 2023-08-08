#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void fcn() {
    printf("I am inside fcn.\n");
    return;
}

int main() {
    fcn();
    printf("Back to main.\n");
    return 0;
}