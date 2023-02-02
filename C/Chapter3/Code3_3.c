#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int num1, num2, num3;
	double avg;
	printf("Enter three integers\n");
	scanf("%d %d %d", &num1, &num2, &num3);
	getchar();
	avg = (double)(num1 + num2 + num3) / 3;
	printf("The average of %d, %d, %d is %.3f.\n", num1, num2, num3, avg);
	return 0;
}