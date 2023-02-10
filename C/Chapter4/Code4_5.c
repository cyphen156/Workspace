#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

double square(double a, double b) {
	double result = a - b;
	result *= result;
	return result;
}

double average(double a, double b, double c) {
	return (a + b + c) / 3;
}

double std_deviation(double a, double b, double c) {
	double 	avg = average(a, b, c), result;
	result = sqrt(average(square(avg, a), square(avg, b), square(avg, c)));
	return result;
}

int main() {
	double a, b, c;

	printf("Enter a three real numbers.\n");
	scanf("%lf%lf%lf", &a, &b, &c);
	getchar();

	printf("Standared deviation is %lf.\n", std_deviation(a, b, c));
	return 0;
}
