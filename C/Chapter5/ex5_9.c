#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int a = 1, b = 0;

	if (a) {
		if (b)
			printf("a and b are both true.\n");
	}
	else
		printf("a is not true.\n");
	return 0;
}
