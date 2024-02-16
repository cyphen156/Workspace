#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// 에라토스테네스의 체
// 시간복잡도 = O(N*log*logN)

void sieveOfEratosthenes(int N)
{
	// 기본 배열 초기화 할당생성, 0은 소수, 1은 합성수
	bool* bzIsPrime = (bool*)calloc(N+1, sizeof(bool));
	int cnt = 0;

	// 초기값 설정 (0과 1은 소수가 아님)
	bzIsPrime[0] = bzIsPrime[1] = true;

	for (int i = 2; i <= N; ++i)
	{
		if(!bzIsPrime[i])
		{
			for (int j = i * 2; j <= N; j += i)
			{
				bzIsPrime[j] = true;
			}
			++cnt;
		}
	}

	printf("%d이하 소수 갯수 : %d", N, cnt);
	free(bzIsPrime);
}