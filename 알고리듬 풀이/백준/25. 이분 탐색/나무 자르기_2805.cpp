/**
 * 백준 나무 자르기_2805
 * N개의 나무를 잘라내어 잘라낸 나무를 합쳐 M미터를 만들어낸다.
 * H이상을 모두 잘라내고, 미만은 무시한다.
 * 잘라낸 부분만 가져갈 수 있다.
 * 필요한 만큼만 가져가야 한다.
 * 절단기에 설정할 수 있는 최대 H를 구하라.
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 1,000,001                    *
 * 1 <= M < 2,000,000,001                *
 * 0 <= inputValue < 1,000,000,001       *
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

static const int MAX_TREE_COUNT = 1000001;
static const int MAX_NEED_LENGTH = 2000000001;

using namespace std;

static int N, M;
static int treeHeights[MAX_TREE_COUNT] = { 0 };

static int maxHeight = 0;

void BinarySearch();

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> treeHeights[i];
    }

    sort(treeHeights, treeHeights + N);

    BinarySearch();
    cout << maxHeight << '\n';
    return 0;
}

void BinarySearch()
{
    long long left = 0;
    long long right = treeHeights[N - 1];
    
    while (left <= right)
    {
        long long mid = (left + right) / 2;

        long long sum = 0;

        for (int i = 0; i < N; ++i)
        {
            if (treeHeights[i] > mid)
            {
                sum += treeHeights[i] - mid;
            }
        }
        if (sum >= M)
        {
            maxHeight = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
}