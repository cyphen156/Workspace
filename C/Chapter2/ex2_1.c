#include <stdio.h>

int main() {
	int i;
	float sum = 0.0f;

	for (i = 0; i < 100; i++) {
		sum = sum + 0.1f;
	}

	printf("%f", sum);
	return 0;
}