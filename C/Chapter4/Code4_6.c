#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

double round_up(double n) {
	return floor(n + 0.5);
}

int main() {
	double num;

	printf("Enter a positive real number.\n");
	scanf("%lf", &num);
	getchar();

	printf("The round up value is  %d.\n", (int)round_up(num));
	return 0;
}
