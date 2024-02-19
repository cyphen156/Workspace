//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>
//
//// 밀러-라빈 소수판정법
//// 시간복잡도 모듈러 거듭제곱연산 = O(log d * 2**r) + 시행횟수O(k)
//// 총 시간복잡도 = O(k * log d * 2**r)
//
//// 모듈러 거듭제곱 함수
//long long moduloPower(long long base, long long exponent, long long modulus) {
//	long long result = 1;
//	base %= modulus;	// 최종 나머지 구해놓고
//	while (exponent > 0) {
//		if (exponent & 1) {
//			result = (result * base) % modulus;
//		}
//		exponent >>= 1;	// 비트시프트 1/2 연산동작
//		base = (base * base) % modulus;
//	}
//	return result;
//}
//
//
//// 밀러 라빈 input == P, T = Test 횟수
//void miller_RabinPrimarity(int input, int T) {
//	srand(time(NULL));
//	if (input <= 1 || input == 4) {
//		printf("%d는 소수가 아닙니다.\n", input);
//		return;
//	}
//	if (input <= 3) {
//		printf("%d는 소수입니다.\n", input);
//		return;
//	}
//	int r = 0;
//	long long d = input - 1;
//		
//	while (d % 2 == 0) // input-1 => d * 2**r변환
//	{
//		d /= 2;
//		++r;
//	}
//
//	 for (int i = 0; i < T; i++) {
//        int a = 2 + rand() % (input - 4); // 2와 input-4 사이의 랜덤 수 생성
//        long long x = moduloPower(a, d, input);
//        if (x == 1 || x == input - 1)
//            continue;
//
//        for (int r = 1; r < s; r++) {
//            x = moduloPower(x, 2, input);
//            if (x == input - 1)
//                break;
//        }
//        if (x != input - 1) {
//            printf("%d는 소수가 아닙니다.\n", input);
//            return;
//        }
//    }
//	printf("%d는 소수일 수 있습니다.\n");
//}