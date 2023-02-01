//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	unsigned int a = 25;
	unsigned left, right;
	left = a << 3; //25 = 00011001 => 11001000 
	right = a >> 3; //=> 00000011
	printf("a : ");
	bitcalculator(a);
	printf("left : ");
	bitcalculator(left);
	printf("right : ");
	bitcalculator(right);
	printf("\nleft shift : %d, right shift : %d\n", left, right);
	return 0;
}

int bitcalculator(int a) {
	for (int i = 0; i < 8; i++) {
		a = a / 2;
		printf("%d", a % 2);
	}
	printf("\n");
	return 1;
}