/**
 * 백준 숫자 카드2_10816
 * 숫자 카드 N개를 가지고 있다.
 * M개의 카드를 주었을 때 몇 개가 있는지 구하라.
 * 
 * 제한사항
 *****************************************
 * 0 < N, M <= 500,000                   *
 * -10,000,000 <= Input <= 10,000,000    *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 20분
 */


#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int indexerCount[20000001] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        indexerCount[tmp + 10000000]++;
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        printf("%d ", indexerCount[tmp + 10000000]); 
    }

    printf("\n"); 
    return 0;
}