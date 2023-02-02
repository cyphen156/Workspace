#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int input, hours, min, sec;
	printf("Enter seconds.\n");
	scanf("%d", &input);
	getchar();
	sec = input % 60;
	min = input / 60 % 60;
	hours = input / 60 / 60;
	printf("It is %d hours, %d minutes, %d seconds.\n", hours, min, sec);
	return 0;
}