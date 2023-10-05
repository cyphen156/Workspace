/**
	해시 함수 구현하기
	문자열 혹은 수열을 정수로 변환
	해시 충돌문제 해결하려면?
	=> 각 항마다의 고유 계수를 부여
	H = sig{Aidx*(R**idx)} Mod M
	R과 M은 서로소
	==> R = 31, M = 1234567891
	이것을 해싱함수로 사용

	제한사항
	입력 문자열 L은 모두 소문자
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int M = 1234567891;
const int r = 31;

long long int hash(char* S, int L) {
	long long int result = 0;

	for (int i = 0; i < L-1; ++i) {
		long long int temp = 1;
		//printf("%c %lld\n", S[i], temp);
		for (int j = 0; j < i; j++) {
			temp = (temp * r) % M;
		}
		temp = (temp * (S[i] - 'a' + 1)) % M;
		//printf("%lld\n", temp);
		result = (result + temp) % M;
	}
	return result;
}

int main() {
	int L;

	scanf("%d", &L);
	if (L > 50)
		return -1;

	char* L2 = (char*)malloc((++L) * sizeof(char));
	scanf("%s", L2);

	printf("%lld", hash(L2, L));
	return 0;
}