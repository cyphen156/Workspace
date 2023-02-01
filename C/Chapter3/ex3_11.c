//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int a = 105, b = 32;
	printf("105 mod 32 = %d\n", a % b);
	printf("105 bitwise AND 31 is %d\n", a & (b - 1));
	return 0;
}