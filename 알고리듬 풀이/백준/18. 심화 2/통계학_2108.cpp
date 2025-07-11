/**
 * 백준 통계학_2108
 * 통계학의 기본 연산 4가지 구현하기
 * 산술평균 : N개의 수들의 합을 N으로 나눈 값
 * 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
 * 최빈값 : N개의 수들 중 가장 많이 나타나는 값
 * 범위 : N개의 수들 중 최댓값과 최솟값의 차이
 * 
 * 제한사항
 *****************************************
 * 1 ≤ N ≤ 500,000                       *
 * N % 2 == 1                            *
 * -4000 <= K <= 4000                    *
 *****************************************
 *
 *
 *
 * 주의
 * 첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
 * 둘째 줄에는 중앙값을 출력한다.
 * 셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
 * 넷째 줄에는 범위를 출력한다.
 * 
 * 풀이시간 0분
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <numbers>
#include <algorithm>

using namespace std;

static int arr[8001] = { 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 개수, 중앙값, 범위,		최빈값		
    // 최솟값			최댓값	
    int N, mid = 0, range = 0, maxFreq = 0,
    min = 0x7FFFFFFF, max = 0x80000000;
    
    cin >> N;

    int sum = 0;
    // 산술평균
    double eval = 0.f;

    vector<int> numbers;
    vector<int> modes;

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;

        numbers.push_back(input);
        sum += input;

        if (input < min)
        {
            min = input; 
        }
        if (input > max)
        {
            max = input;
        }

        int index = input + 4000;
        arr[index]++;
    }

    for (int i = 0; i < size(arr); ++i)
    {
        if (maxFreq < arr[i])
        {
            maxFreq = arr[i];
            modes.clear();
            modes.push_back(i - 4000);
        }
        else if (arr[i] == maxFreq)
        {
            modes.push_back(i - 4000);
        }
    }

    sort(numbers.begin(), numbers.end());

    eval = (int)round((double)sum / N);
    mid = numbers[N/2];
    range = max - min;
    maxFreq = (modes.size() >= 2 ? modes[1] : modes[0]);

    cout << eval << '\n' 
        << mid << '\n'
        << maxFreq << '\n'
        << range << '\n';
    return 0;
}