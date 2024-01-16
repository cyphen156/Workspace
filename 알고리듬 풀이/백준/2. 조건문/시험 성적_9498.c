#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int A;
	scanf("%d", &A);
	if (A < 0 || A > 100) {
		printf("Score Err \n");
		return 0;
	}
	if (A >= 90)
	{
		printf("A");
	}
	else if (A >= 80) {
		printf("B");
	}
	else if (A >= 70) {
		printf("C");
	}
	else if (A >= 60)
		printf("D");
	else
		printf("F");
	return 0;
}