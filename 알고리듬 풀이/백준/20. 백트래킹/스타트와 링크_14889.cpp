/**
 * 백준 스타트와 링크_14889
 * 짝수인 수 N명이 주어진다. 
 * 두 팀으로 나누에 팀을 구성한다고 할 때 
 * 각 번호는 다른 번호와 조합되었을 때 가중값을 받게된다.
 * 두 팀이 구성되었을 때 이 가중값의 차이가 최소가 되는 조합을 구하라.
 * 
 * 제한사항
 *****************************************
 * 3 < N <= 20                           *
 * N % 2 == 0                            *
 * S == individual weight values         *
 * If i == j : S(i, j) always 0          *
 * 0 < S(i, j) <= 100                    *
 *****************************************
 *
 *
 *
 * 주의
 * 가중값의 차이의 최소는 | diffrence |로 구성되므로 가능한 최솟값은 0이다.
 * 팀 A와 팀 B를 구성할 때 TeamA = (1, 2, 3, 4) TeamB = (5, 6, 7, 8)과 TeamA = ( 5, 6, 7, 8 ) TeamB = ( 1, 2, 3, 4 )는 사실상 같다.
 * ==> 순회를 절반만 해도 된다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 25분
 */


#include <iostream>

#define MaxNumber 20

static int N, minDifference = 0x7fffffff;

static int S[MaxNumber][MaxNumber] = { 0 };
static bool isFirstTeam[MaxNumber] = { 0 };

void BackTrack(int depth, int index);

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 입력부
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> S[i][j];
        }
    }
    isFirstTeam[0] = true;  
    BackTrack(1, 1);

    cout << minDifference << '\n';

    return 0;
}

void BackTrack(int depth, int index)
{
    if (depth == N / 2)
    {
        int firstTeamScore = 0, secondTeamScore = 0;

        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                // 둘다 첫번째 팀이면 가중치 더하기
                if (isFirstTeam[i] && isFirstTeam[j])
                {
                    firstTeamScore += S[i][j] + S[j][i];
                }

                // 둘다 두번째 팀이면 가중치 더하기
                if (!isFirstTeam[i] && !isFirstTeam[j])
                {
                    secondTeamScore += S[i][j] + S[j][i];
                }
            }
        }

        int currentDifference= abs(firstTeamScore - secondTeamScore);
        if (minDifference > currentDifference)
        {
            minDifference = currentDifference;
        }
        return;
    }

    for (int i = index; i < N; ++i)
    {
        if (!isFirstTeam[i])
        {
            isFirstTeam[i] = true;
            BackTrack(depth + 1, i + 1);
            isFirstTeam[i] = false;
        }
    }
}
