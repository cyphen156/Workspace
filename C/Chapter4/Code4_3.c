#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int square(int n) {
	return n * n;
}

int main() {
	int a, b, result;

	printf("Enter a, b.\n");
	scanf("%d %d", &a, &b);
	getchar();

	result = square(a) + square(b);
	printf("%d * %d + %d * %d = %d\n", a, a, b, b, result);
	return 0;
}
