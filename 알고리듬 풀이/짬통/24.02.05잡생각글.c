
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 0;
	int b = 1;
	int* pa = (int*)malloc(sizeof(int));
	for (int i = 0; i < 5; ++i)
	{
		printf("%d회 반복\n", i + 1);

		*pa = a;
		printf("%p\t%d\n", pa, *pa);

	}
	free(pa);
	*pa = b;
	printf("%p\t%d\n", pa, *pa);
	return 0;
}