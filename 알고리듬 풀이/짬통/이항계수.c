/**
* 백준 이항계수 1 11050
* 자연수 N과 정수 K, 이항계수 (N, K)
* 
* 정수 K라 함은 음수도 포함이기 때문에 조건변경해줘야 함
* 
* 
* N * (N-1) * (N-2) .... * (N-K) / 1 * 2 * 3 * ... * K
* 
* 제한사항
*****************************************
* 1 <= N <= 10							*
* 0 <= K <= N							*
*****************************************
* 
* 풀이시간 10분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	// 정수 N, K, 분모, 분자
	unsigned int N, K, numerator = 1, denominator = 1;
	scanf("%u %u", &N, &K);
	if (N == 0 || K > N)
		return -1;
	for (int i = 0; i < K; ++i) {
		numerator *= (N - i);
		denominator *= (i + 1);
	}
	printf("%u", numerator / denominator);
	return 0;
}