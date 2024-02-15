//// 일반적인 소수판정법(Naive Method)
//// 시간복잡도 = O(N)
//void naiveMethod(int input)
//{
//	for (int i = 2; i < input; ++i) {
//		if (input % i == 0) // 나머지가 0이면 약분된다.
//		{
//			printf("소수가 아닙니다.");
//			return;
//		}
//	}
//	printf("소수입니다.");
//}
//
//// 절반까지만 확인하기
//// 시간복잡도 = O(N) (1/2)
//void halfNativeMethod(int input)
//{
//	for (int i = 2; i < input/2; ++i) { // 반복횟수가 1/2
//		if (input % i == 0) // 나머지가 0이면 약분된다.
//		{
//			printf("소수가 아닙니다.");
//			return;
//		}
//	}
//	printf("소수입니다.");
//}
//
//// 제곱근 판정법
//void sqrtMethod(int input)
//{
//	for (int i = 2; i < sqrt(input); ++i) {
//		if (input % i == 0) // 나머지가 0이면 약분된다.
//		{
//			printf("소수가 아닙니다.");
//			return;
//		}
//	}
//	printf("소수입니다.");
//}