// 일반적인 소수판정법(Naive Method)
void naiveMethod(int input)
{
	for (int i = 2; i < input; ++i) {
		if (input % i == 0) // 나머지가 0이면 약분된다.
		{
			printf("소수가 아닙니다.");
			return;
		}
	}
	printf("소수입니다.");
}

// 절반까지만 확인하기
void halfNativeMethod(int input)
{
	for (int i = 2; i <= input/2; ++i) { // i check조건이 1/2배
		if (input % i == 0) // 나머지가 0이면 약분된다.
		{
			printf("소수가 아닙니다.");
			return;
		}
	}
	printf("소수입니다.");
}

