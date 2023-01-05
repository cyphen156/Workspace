#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	char ch1, ch2;
	printf("Enter two characters.\n");
	scanf("%c%c", &ch1, &ch2);
	printf("Character just read are %c and %c", ch1, ch2);
	return 0;
}