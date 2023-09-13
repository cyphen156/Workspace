#define _CRT_SECURE_NO_WARNINGS
/*
    백준 2798 블랙잭
    양의 정수 N, 솟자가 모두 보임
    M을 외치면 
    제한된 시간 내에 3장을 골라 M과 근사값을 만들어야함
    -> a+b+c+.... <= M
*/
/*
    제한사항
    3 ≤ N ≤ 100
    10 ≤ M ≤ 300,000
    0 < a, b, c ..... <= 100,000
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int* card = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &card[i]);
    }

    int max = 0, temp;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int temp = card[i] + card[j] + card[k];
                if (temp <= M && temp > max) {
                    max = temp;
                }
            }
        }
    }

    printf("%d\n", max);

    free(card);
    return 0;
}

