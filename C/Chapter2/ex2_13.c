#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int age, count; double weight, height;

	printf("Enter age.\n");
	scanf("%d", &age);
	printf("Age : %d\n", age);
	printf("Enter weight and height.\n");
	scanf("%lf%lf", &weight, &height);
	printf("weight : %lf, height : %lf.\n", weight, height);
	count = scanf("%lf%lf", &weight, &height);
	printf("Scanf returns %d.\n", count);
	return 0;
}