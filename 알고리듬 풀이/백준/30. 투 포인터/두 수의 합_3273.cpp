/**
 * 백준 두 수의 합_3273
 * ai + aj = x인 두 수의 쌍을 모두 구하라.
 * 
 * 제한사항
 *****************************************
 * 1 <= n < 100,001                      *
 * 1 <= x < 2,000,001                    *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 5분
 */


#include <iostream>
#include <algorithm>

using namespace std;

static const int MAX_SIZE = 100001;

static int n, x, result;

static int numbers[MAX_SIZE] = { 0 };

void solve(int x);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    sort(numbers, numbers + n);
    
    cin >> x;
    
    solve(x);

    cout << result << '\n';
    return 0;
}

void solve(int x)
{
    int left = 0;
    int right = n-1;

    while(left < right)
    {
        int sum = numbers[left] + numbers[right];

        if (sum == x)
        {
            ++result;
            ++left;
            --right;
        }
        else if (sum < x)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }
}