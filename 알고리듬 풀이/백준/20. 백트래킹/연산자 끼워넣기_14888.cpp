/**
 * 백준 연산자 끼워넣기_14888
 * 수열을 먼저 주고, 그 안에 연산을 도와줄 연산자를 줄 때
 * 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.
 * ex) 입력 예시
 * 5
 * 1 2 3 4 5 
 * 1 1 1 1 
 * 이 입력을 조합하면 다음과 같은 수식이 완성된다.
 * 1 + 2 - 3 × 4 ÷ 5
 * 식의 계산은 연산자 우선순위를 무시하고 앞에서부터 진행한다
 * --> FIFO
 * 나눗셈 연산시 나머지는 버린다.
 * 음수를 양수로 나눌때는 양수로 바꾸어 나눈뒤 다시 음수로 바꾸는 방식을 사용한다.
 * 수의 순서는 바꿀 수 없지만 연산자의 순서는 변경할 수 있다.
 * 
 * 제한사항
 *****************************************
 * 1 < N < 11                            *
 * 0 < Input <= 100                      *
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
#include <queue>

static int N, minValue = 0x7FFFFFFF, maxValue = 0x80000000;
static int numbers[11] = { 0 } ;
static int operationCounts[4] = { 0 };

void BackTrack(int depth, int currentResult);

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> numbers[i];
    }

    for (int i = 0; i < 4; ++i)
    {
        cin >> operationCounts[i];
    }

    BackTrack(0, numbers[0]);

    cout << maxValue << '\n';
    cout << minValue << '\n';

    return 0;
}

void BackTrack(int depth, int currentResult)
{
    // 마지막 연산자임
    // ==> 연산 종료
    if (depth == N-1)
    {
        // 최솟값 갱신
        if (currentResult < minValue)
        {
            minValue = currentResult;
        }

        // 최댓값 갱신
        if (currentResult > maxValue)
        {
            maxValue = currentResult;
        }

        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        // 연산자 남아있음
        if (operationCounts[i] > 0)
        {
            operationCounts[i]--;

             int nextResult = currentResult;
            int nextNumber = numbers[depth + 1];

            switch (i)
            {
            case 0: // +
                nextResult += nextNumber;
                break;
            case 1: // -
                nextResult -= nextNumber;
                break;
            case 2: // *
                nextResult *= nextNumber;
                break;
            case 3: // /
                if (nextNumber != 0)
                {
                    if (nextResult < 0)
                    {
                        nextResult = -(-nextResult / nextNumber);
                    }
                    else
                    {
                        nextResult /= nextNumber;
                    }
                }
                break;
            }

            // 다음 연산자 사용 백트래킹
            BackTrack(depth + 1, nextResult);
            // 브루트 포싱을 위해 복원
            operationCounts[i]++;
        }
    }
}
