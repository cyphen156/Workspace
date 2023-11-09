/**
* 백준 1654 랜선 자르기 
* 
* N개의 랜선 만들기
* 이미 존재하는 K개의 랜선 but 길이가 다름
* -> 모두 같은 길이의 N개로 조정
* 랜선은 한번 잘라내면 다시 사용할 수 없음
* 길이 L보다 작은 랜선은 버려야함
* 
* sigma(K(L)) >= N(L)
* 
* 출력 
* N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수
* 
* 제한사항
*****************************************
* K <= N								*
* 1<= K < 10,000, 1 <= N <= 1,000,000	*
* 0 < L <= 2**31-1						*
*****************************************
* 
* 풀이시간 3시간
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
	int K, N;
	long long max = 0, min = 1, result = 0;

	// K, N입력
	scanf("%d%d", &K, &N);
	if (K == 0 || N == 0) {
		return -1;
	}


	int* KLen = (int*)malloc(K * sizeof(int));
	if (KLen == NULL) {
		return -1;
	}

	// 랜선 길이 입력받기
	for (int i = 0; i < K; ++i) {
		scanf("%d", &KLen[i]);
		if (KLen[i] <= 0) {
			free(KLen);
			return -1;
		}
		if (KLen[i] > max) {
			max = KLen[i];
		}
	}

	while (min <= max) {
		long long mid = (min + max) / 2;
		int cnt = 0;

		// 중간값계산하기
		for (int i = 0; i < K; ++i) {
			cnt += KLen[i] / mid;
		}

		if (cnt >= N) { 
			result = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}

	printf("%lld", result);
	free(KLen);
	return 0;
}