#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int abs(int num);

int main(void) {
	int num;
	scanf("%d", &num);
	printf("%d", abs(num));
	return 0;
}

int abs(int num) {
	return 	(num >= 0) ? num : -num;
}