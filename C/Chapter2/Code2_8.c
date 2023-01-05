#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	char ch1, ch2, ch3;

	printf("Enter a Your Initial\n");
	scanf("%c%c%c", &ch1, &ch2, &ch3);
	printf("Initials of your name are %c, %c and %c", ch1, ch2, ch3);
	return 0;
}