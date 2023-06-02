#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

const static int A = 9999;

int main(void) {
	printf("변수 영역에 대해 공부해봅시다.\n");
	int A, B;
	while (scanf("%d %d", &A, &B) != EOF) {
		printf("%d\n", calc(A, B));
	}
	calc(A, B);
	return 0;
}

int calc(int a, int b) {
	int result = a + b;
	return result;
}