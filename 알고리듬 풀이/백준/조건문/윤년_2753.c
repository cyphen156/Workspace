#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int inputNumber;
	scanf("%d", &inputNumber);
	if (((inputNumber % 4 == 0) && (inputNumber % 100 != 0)) || inputNumber % 400 == 0) {
		printf("1");
	}
	else
		printf("0");
	return 0;
}
