#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void Odd_Even(int n) {
	if (n % 2 == 1) {
		printf("Odd number.\n");
	}
	else {
		printf("Even number.\n");
	}
	return;
}

int main() {
	int num;
	printf("Enter an integer.\n");
	scanf("%d", &num);
	Odd_Even(num);
	return 0;
}