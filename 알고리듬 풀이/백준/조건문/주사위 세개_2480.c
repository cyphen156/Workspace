#define	_CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	int first, second, third, max;
	scanf("%d %d %d", &first, &second, &third);
	if (first == second && first == third) {
		printf("%d", first * 1000 + 10000);
	}else {
		if (first == second || first == third)
			printf("%d", first * 100 + 1000);
		else if (second == third)
			printf("%d", second * 100 + 1000);
		else {
			max = first;
			if (max < second)
				if (second < third)
					max = third;
				else
					max = second;
			else if (max < third)
				max = third;
			printf("%d", max * 100);
		}
	}

	return 0;
}