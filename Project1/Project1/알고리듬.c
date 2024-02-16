#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 밀러-라빈 소수판정법
// 시간복잡도 모듈러 거듭제곱연산 = O(log d * 2**r) + 시행횟수O(k)
// 총 시간복잡도 = O(k * log d * 2**r)

// 모듈러 거듭제곱 함수
long long moduloPoer() {
	long long result;
	return result;
}

// 밀러 라빈 input == P, T = Test 횟수
void miller_RabinPrimarity(int input, int T) {
	srand(time(NULL));
	if (input < 2)
	{
		printf("소수가 아닙니다.");
		return;
	}
	int r = 0;
	long long d = input - 1;
		
	while (d % 2 == 0) // input-1 => d * 2**r변환
	{
		d /= 2;
		++r;
	}

	for (int i = 0; i < T; ++i)
	{
		int a = 2 + rand() % (input - 4);
	}
	printf("%d는 소수일 수 있습니다.\n");
}