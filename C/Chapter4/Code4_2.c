#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

double square(double num1, double num2) {
	double result;
	result = num2 - num1;
	return result * result;
}

double getDistance(double p1, double q1, double p2, double q2) {
	double result;
	result = square(p1, p2) + square(q1, q2);
	return result;
}

int main() {
	double x1, x2, y1, y2, distance;

	printf("Enter the coordinates of point p\n");
	scanf("%lf %lf", &x1, &y1);
	getchar();

	printf("Enter the coordinates of point q\n");
	scanf("%lf %lf", &x2, &y2);

	distance = sqrt(getDistance(x1, y1, x2, y2));
	printf("Distance between the points is %.6lf.\n", distance);
	return 0;
}
