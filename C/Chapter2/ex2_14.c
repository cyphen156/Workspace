#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	unsigned char ch; int num;

	printf("Enter a character.\n");
	scanf("%c", &ch);
	printf("It is %d in decimal.\n", ch);
	printf("Enter the same Character again.\n");
	scanf("%d", &num);
	printf("It is %d in decimal.\n", num);
	return 0;
}