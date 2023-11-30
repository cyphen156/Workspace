/**
* 백준 유기농 배추 1012
* 
* 배추흰지렁이 
* 인접 노드 = True
* 제한사항
*****************************************
* T                                     *
* 밭 너비                               *
* 1 <= N,M <= 50                        *
* 배추의 개수 1 <= K <= 2500            *
* 0 <= x, y <= M-1, N-1                 *
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

int T, M, N, K, x, y;
int arr[50][50] = { 0 };

void dfs(int j, int k) {
    // 밭 크기 한정
    if (j < 0 || j >= N || k < 0 || k >= M || arr[j][k] != 1) {
        return;
    }
    arr[j][k] = -1;
    dfs(j-1, k);
    dfs(j + 1, k);
    dfs(j, k-1);
    dfs(j, k+1);
}
int main() {


    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        // 밭 크기 입력
        scanf("%d %d %d", &N, &M, &K);

        // 초기화
        for (int j = 0; j < 50; ++j) {
            for (int k = 0; k < 50; ++k) {
                arr[j][k] = 0;
            }
        }
        int cnt = 0;

        for (int j = 0; j < K; ++j) {
            // 배추심기
            scanf("%d %d", &x, &y);
            arr[x][y] = 1;
        }
        
        // 지렁이 할당하기
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (arr[j][k] == 1) {
                    dfs(j, k);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
