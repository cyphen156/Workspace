/**
 * 백준 전깃줄
 * 다음 그림과 같은 전봇대가 있다.
 * 합선이 일어나지 않도록 다음과 같이 고칠 떄 없애야 하는 최소 전깃줄의 개수를 구하라.
 * 
 * 제한사항
 ****************************************************
 * 0 < N <= 100                                     *
 * 0 < Value <= 500                                 *
 * 한 위치에 하나의 전깃줄만 연결된다. => Unique Value *
 ****************************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 3 + 20분
 */


#include <iostream>
#include <algorithm>

#define MAX_SIZE 500

using namespace std;

static int towerA[MAX_SIZE] = { 0 };
static int memoizationArray[MAX_SIZE] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int index;
        cin >> index;
        cin >> towerA[index];
    }
    
    int maxLength = 0;
    int minRemove = 0x7fffffff;

    for (int i = 0; i < MAX_SIZE; ++i)
    {
        if (towerA[i] == 0)
        {
            continue;
        }

        memoizationArray[i] = 1;

        for (int j = 0; j < i; ++j)
        {
            if (towerA[j] == 0)
            {
                continue;
            }

            if (towerA[j] < towerA[i])
            {
                memoizationArray[i] = max(memoizationArray[i], memoizationArray[j] + 1);
            }
        }
        maxLength = max(maxLength, memoizationArray[i]);
    }

    minRemove = N - maxLength;
    cout << minRemove << '\n';

    return 0;
}