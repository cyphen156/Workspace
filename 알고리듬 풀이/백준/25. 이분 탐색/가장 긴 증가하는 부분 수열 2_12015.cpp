/**
 * 백준 가장 긴 증가하는 부분 수열 2_12015
 * 수열 A가 주어졌을 때 가장 긴 증가하는 부분 수열을 구하라.
 * 증가하는 부분 수열이란 오름차순으로 중복을 허용하지 않는 수열을 의미한다. 
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 1,000,001                    *
 * 1 <= Ai < 1,000,001                   *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 0분
 */


#include <iostream>

static const int MAX_SIZE = 1000001;

using namespace std;

static int N;
static int inputs[MAX_SIZE] = { 0 };

static int length = 0;

void calculatePartitial();

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> inputs[i];
    }

    length++;

    calculatePartitial();

    cout << length << '\n';
    return 0;
}

void calculatePartitial()
{
    for (int i = 1; i < N; ++i)
    {
        int current = inputs[i];

        int left = 0;
        int right = length;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (inputs[mid] >= current)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        // left가 들어갈 자리
        if (left == length)
        {
            // 맨 뒤에 추가 → 길이 증가
            inputs[length++] = current;
        }
        else
        {
            // 같은 길이의 꼬리를 더 작은 값으로 교체
            inputs[left] = current;
        }
    }
}