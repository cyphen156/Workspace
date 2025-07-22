/**
 * 백준 N과 M (2)_15650
 * 자연수 N과 M이 주어졌을 때 길이가 M인 수열을 모두 구하라
 * 1부터 N까지 중복 없이 M개를 고른 수열
 * 오름차순 옵션 추가
 * ==> 앞 수보다 작으면 출력안함
 * 
 * 제한사항
 *****************************************
 * 0 < M <= N <= 8                       *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 10분
 */


#include <iostream>

using namespace std;

static int N, M;

static int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
static bool isUsed[8] = { 0 };
static int currentPath[8];

void BackTrcak(int currentDepth);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    BackTrcak(0);

    return 0;
}

void BackTrcak(int currentDepth) 
{
    if (currentDepth == M) 
    {
        for (int i = 0; i < M; ++i)
        {
            cout << currentPath[i] << ' ';
        }

        cout << '\n';
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (!isUsed[i])
        {
            if (currentDepth != 0 && i < currentPath[currentDepth-1])
            {
                continue;
            }
            isUsed[i] = true;
            currentPath[currentDepth] = arr[i];
            BackTrcak(currentDepth + 1);
            isUsed[i] = false;
        }
    }
}