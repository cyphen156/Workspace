#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int num1, num2;
	printf("Enter dividend.\n");
	scanf("%d %d", &num1, &num2);
	getchar();
	printf("Quotient is %d. Remainder is %d\n", num1 / num2, num1 % num2);
	return 0;
}