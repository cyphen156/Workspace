#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	char ch1, ch2;
	printf("Enter the first character.\n", &ch1);
	scanf("%c", &ch1);
	printf("First character is %c.\n", ch1);

	printf("Enter the second character.\n", &ch2);
	scanf("%c", &ch1);
	printf("Second character is %c.\n", ch2);
	return 0;
}