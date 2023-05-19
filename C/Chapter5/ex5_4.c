#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int num;
	printf("Enter an integer.\n");
	scanf("%d", &num);

	if (num > 3)
		printf("num is larger than 3. \n");
	if (num <= 3)
		printf("num is less than or equal to 3. \n");

	if (num > 3)
		printf("num is larger than 3. \n");
	else
		printf("num is less than or equal to 3. \n");
	return 0;
}
