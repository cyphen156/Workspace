/**
 * 백준 양팔저울_2629
 * 몇 종류의 추와 한 개의 구슬이 주어진다.
 * 추와 구슬을 이용하여 양팔 저울이 수평을 이루도록 만들어 
 * 주어진 구슬의 무게를 찾는 프로그램을 작성하라.
 * 만약 무게를 확인 할 수 있다면 Y, 없다면 N을 출력한다.
 * Hint
 * 왼쪽과 오른쪽의 부울형 차 배열을 만들어 놓고, 
 * 인덱스를 활용해 접근한다면
 * 입력에 대해 즉시 결과를 출력할 수 있다.
 * 
 * 
 * 제한사항
 *******************************************
 * 1 <= 추의 개수 < 31                      *
 * 1 <= 추의 무게 < 501                     *
 * 추의 무게는 중복을 허용한다.               *
 * 추의 무게는 오름차순으로 정렬되어 입력한다. *
 * 1 <= 확인할 구슬의 개수 < 8               *
 * 1 <= 구슬의 무게 < 40,001                *
 *******************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 20분
 */


#include <iostream>
#include <vector>

using namespace std;

static const int MAX_SUM = 500*30;

static int sinkerCount, beadCount;

vector<int> sinkers;
vector<int> beads;

vector<bool> diffArray;

bool Solve(int value);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> sinkerCount;
    sinkers.resize(sinkerCount);
    for (int i = 0; i < sinkerCount; ++i)
    {
        cin >> sinkers[i];
    }

    cin >> beadCount;
    beads.resize(beadCount);
    for (int i = 0; i < beadCount; ++i)
    {
        cin >> beads[i];
    }

    diffArray.assign(MAX_SUM + 1, false);
    diffArray[0] = true;

    int currentMax = 0;
    for (int i = 0; i < sinkerCount; i++)
    {
        int w = sinkers[i];
        vector<bool> next = diffArray;

        int limit = currentMax;
        if (limit > MAX_SUM)
        {
            limit = MAX_SUM;
        }

        for (int d = 0; d <= limit; d++)
        {
            if (diffArray[d])
            {
                int plus = d + w;
                if (plus <= MAX_SUM)
                {
                    next[plus] = true;
                }

                int diff = d - w;
                if (diff < 0)
                {
                    diff = -diff;
                }
                next[diff] = true;
            }
        }

        diffArray.swap(next);

        currentMax += w;
        if (currentMax > MAX_SUM)
        {
            currentMax = MAX_SUM;
        }
    }


    for (int i = 0; i < beadCount; ++i)
    {
        int x = beads[i];
        char ch = 'N';
        if (x >= 0 && x <= MAX_SUM && diffArray[x])
        {
            ch = 'Y';
        }
        cout << ch;
        if (i + 1 < beadCount)
        {
            cout << ' ';
        }
    }

    cout << endl;
    return 0;
}