/**
* 백준 덩치 7568
* 
* 덩치는 몸무게와 키 둘 모두 큰사람을 뜻한다
* 
* 둘중 하나라도 크지 못하면 덩치는 같다.
* 
* 동적 할당을 통한 이차원 배열 생성
* 
* 제한사항
*****************************************
* 2 ≤ N ≤ 50                          *
* 10 ≤ x, y ≤ 200                     *
*****************************************
*
*
*
* 주의
* 
* 풀이시간 60분
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    // 동적 할당을 사용한 배열 생성
    int(*arr)[2] = (int(*)[2])malloc(N * sizeof(int[2]));
    int* rank = (int*)malloc(N * sizeof(int));

    // 입력
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    // 덩치 등수 계산
    for (int i = 0; i < N; ++i) {
        rank[i] = 1;
        for (int j = 0; j < N; ++j) {
            if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
                rank[i]++;
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < N; ++i) {
        printf("%d ", rank[i]);
    }

    // 동적 할당된 메모리 해제
    free(arr);
    free(rank);

    return 0;
}
