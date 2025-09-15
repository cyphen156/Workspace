/**
 * 백준 두 용액_2470
 * 양수의 경우 산성, 음수의 경우 알칼리성으로 용액의 특성을 정의한다.
 * 하나의 용액은 특성 값에 따라 그 가중값이 결정된다. 
 * 두 용액을 혼합하여 용액의 특성값을 혼합했을 때 합성한 용액의 특성은 특성값 합의 부호를 따라간다.
 * 용액이 여러가지 주어졌을 때
 * 이 특성값의 합이 최대한 0에 가깝도록 만드는 두 용액을 찾아라.
 * 뭔가 거창하게 써놨는데 그냥 자료를 더해서 절댓값의 크기가 가장 작은 조합을 찾는 문제이다.
 * 
 * 제한사항
 *****************************************
 * 2 <= N < 100,001                      *
 * -1,000,000,000 <= Value < 0           *
 * 1 <= Value < 1,000,000,001            *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 10분
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

static const int MAX_N_SIZE = 100001;

static int N;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin  >> N;

    vector<int> solutions;

    for (int i = 0; i < N; ++i)
    {
        int input;

        cin  >> input;
        solutions.push_back(input);
    }

    sort(solutions.begin(), solutions.end());

    int left = 0;
    int right = solutions.size() - 1;
    int currentLeft = left;
    int currentRight = right;

    int minValue = 0x7fffffff;
    
    while (currentLeft < currentRight)
    {
        int temp = solutions[currentLeft] + solutions[currentRight];
        if (temp == 0)
        {
            left = currentLeft;
            right = currentRight;
            break;
        }

        if (abs(temp) < minValue)
        {
            minValue = abs(temp);
            left = currentLeft;
            right = currentRight;
        }
        
        if (temp > 0)
        {
            currentRight--;
        }
        else
        {
            currentLeft++;
        }
    }

    cout << solutions[left] << ' ' << solutions[right] << endl;
    return 0;
}