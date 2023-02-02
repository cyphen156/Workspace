#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int C, F;
	printf("Enter degrees in Celcius.\n");
	scanf("%d", &C);
	getchar();
	F = C * 9 / 5 + 32;
	printf("%d degrees in Celcius is %d degrees in Fahrenheit.\n", C, F);
	return 0;
}