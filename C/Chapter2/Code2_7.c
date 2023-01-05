#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	float num;

	printf("Enter a real number\n");
	scanf("%f", &num);
	printf("%d", (int)num);
	return 0;
}