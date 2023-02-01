//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	unsigned int a = 25;
	unsigned left, right;
	left = a << 3; //25 = 00011001 => 11001000 
	right = a >> 3; //=> 00000011
	printf("left shift : %d, right shift : %d\n", left, right);
	return 0;
}