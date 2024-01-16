#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int H, M, input;
	scanf("%d %d %d", &H, &M, &input);

	while (input >= 60) { //입력값 > 60
		input -= 60;
		H += 1;
	}
	M += input;

	if (M > 59) {
		H += 1;
		M -= 60;
	}
	if (H >= 24)
		H -= 24;
	printf("%d %d", H, M);
	return 0;
}