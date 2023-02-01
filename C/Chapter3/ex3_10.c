//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int a = 105, b = 85;

	printf("%d \n", a & b);
	printf("%X \n", a | b);
	printf("%X \n", a ^ b);
	printf("%X \n", ~a);
	return 0;
}