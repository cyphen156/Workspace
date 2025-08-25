/**
 * 백준 랜선 자르기_1654
 * K개의 임의의 길이를 갖고 있는 랜선을 모두 N이라는 크기로 잘라내어 동일한 규격으로 맞춘다.
 * 한번 자른 부분은 다시 이어붙일 수 없다.
 * 더 작은 부분으로는 잘라낼 수 있다.
 * 이 때 만들 수 있는 랜선 길이중 가장 긴 것을 찾아라.
 * 
 * 제한사항
 *****************************************
 * 1 <= K < 10,001                       *
 * 1 <= N < 1,000,001                    *
 * K <= N                                *
 * return value is Intiger               *
 *****************************************
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
#include <algorithm>

static const int MAX_SIZE_K = 10001;
static const int MAX_SIZE_N = 1000000;

using namespace std;

static int K, N;
static int inputs[MAX_SIZE_K] = { 0 };

int BinarySearch();
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> K >> N;

    for (int i = 0; i < K; ++i)
    {
        cin >> inputs[i];
    }

    sort(inputs, inputs + K);

    cout << BinarySearch() << '\n';
    return 0;
}

int BinarySearch()
{
    long long left = 1;
    long long right = inputs[K - 1];
    long long mid;
    
    while (left <= right)
    {
        mid = (right + left) / 2;
        int cnt = 0;

        for (int i = 0; i < K; ++i) 
        {
			cnt += inputs[i] / mid;
		}

        if (cnt >= N)
        {
            left =  mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }

    return static_cast<int>(right);
}