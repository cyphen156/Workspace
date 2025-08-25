/**
 * 백준 공유기 설치_2110
 * 일차원 수직선 위에 N개의 집 좌표가 있다.
 * 중복되는 좌표가 허용되지 않는다.
 * 한 집에 공유기를 한 개만 설치 할 수 있다.
 * C개의 공유기를 설치할 때,
 * 가장 인접한 두 공유기 사이의 거리가 최대가 되도록 구하라.
 * 
 * 제한사항
 *****************************************
 * 2 <= C <= N < 200,001                 *
 * 0 <= Xi < 1,000,000,001               *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 5 + 15분
 */


#include <iostream>
#include <algorithm>

static const int MAX_POINT_COUNT = 200001;

using namespace std;

static int N, C;
static int housePoints[MAX_POINT_COUNT];
static int maxInterval = 0;

void CalculateIntervals();
void BinarySearch();

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> C;

    for (int i = 0; i < N; ++i)
    {
        cin >> housePoints[i];
    }

    sort(housePoints, housePoints + N);
    BinarySearch();
    
    cout << maxInterval << '\n';
    return 0;
}

void BinarySearch()
{
    int left = 1;
    int right = housePoints[N - 1] - housePoints[0];

    int result = 0;

    while (left <= right)
    {
        int mid = (right + left) / 2;

        int placed = 1;
        int lastPosition = housePoints[0];

        for (int i = 0; i < N; ++i)
        {
            // calc interval
            if (housePoints[i] - lastPosition >= mid)
            {
                placed++;
                lastPosition = housePoints[i];
                if (placed >= C)
                {
                    break;
                }
            }
        }
        if (placed >= C)
        {
            result = mid;
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }
    maxInterval = result;
}