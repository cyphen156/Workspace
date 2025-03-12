#define _CRT_SECURE_NO_WARNINGS
/*
    백준 1018_체스판 다시 칠하기
    M * N개 단위 정사각형 배열
    검정 - 흰색 2지선다
    보드 자르기
    -> M-x, N-y = 8, 8

    체스판의 색배열
    검정-흰색-검정-흰색
    흰색-검정-흰색-검정
    but 보드의 색배열은 랜덤
    -> 다시칠하기(result)

    result의 최소 개수를 구해야 한다 
    -> 자른 위치에 따라 생긴 체스판의 결과를 가지고있어야함. 
    but 최소 이상이 되면 계산할 필요 없음
*/
/*
    제한사항
    8 <= M <= N <= 50
*/
/*
    문제 풀이 시간 : 1:30분
*/
#include <stdio.h>

int main() {
    int M, N, min = 64;
    char board[50][50] = { 0 };
    scanf("%d %d", &M, &N);

    // 입력 받기
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    // 체스판 만들기
    for (int i = 0; i <= M - 8; i++) {
        for (int j = 0; j <= N - 8; j++) {
            int result = 0;
            char firstColor = board[i][j];

            // 생성된 체스판 순회
            for (int k = 0; k < 8; k++) {
                for (int t = 0; t < 8; t++) {
                    // firstColor를 기준으로 색상이 다르면 result 증가
                    if (((k + t) % 2 == 0 && board[i + k][j + t] != firstColor) ||
                        ((k + t) % 2 == 1 && board[i + k][j + t] == firstColor)) {
                        result++;
                    }
                }
            }

            // 최소값 찾기
            if (result > 32)
                result = 64 - result;
            if (result < min) {
                min = result;
            }
        }
    }

    printf("%d\n", min);
    return 0;
}
