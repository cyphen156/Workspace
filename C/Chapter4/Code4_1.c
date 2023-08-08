#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int is_larger(int f, int s) {
	if (f >= s) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int first, second;

	printf("Enter two integers.\n");
	scanf("%d, %d", &first, &second); 
	
	printf("Result is %d\n", is_larger(first, second));
	return 0;
}
	strcm