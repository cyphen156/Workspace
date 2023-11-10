/**
* 백준 숫자의 개수 2577
* 
* 세 자연수의 곱 A * B * C, 0~9까지의 숫자가 몇 번 쓰엿는지
* 
* 배열로 해결가능
* 
* 
* 제한사항
*****************************************
* 100 <= A, B, C <= 1,000				*
*****************************************
* 
* 
* 
* 주의
* 
* 풀이시간 5분
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



int main() {
	unsigned int A, B, C;
	unsigned int cnt[10] = { 0 };

	scanf("%u%u%u", &A, &B, &C);

	int result = A * B * C;
	while (result != 0) {
		int temp = result % 10;
		cnt[temp]++;
		result /= 10;
	}
	for (int i = 0; i < 10; ++i) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}