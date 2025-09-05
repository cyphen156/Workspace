// 제곱근 판정법
#include <math.h>

void sqrtMethod(int input)
{
	for (int i = 2; i <= sqrt(input); ++i) {
		if (input % i == 0) // 나머지가 0이면 약분된다.
		{
			printf("소수가 아닙니다.");
			return;
		}
	}
	printf("소수입니다.");
}