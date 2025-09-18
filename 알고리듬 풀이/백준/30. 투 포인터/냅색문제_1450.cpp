/**
 * 백준 냅색문제_1450
 * N개의 물건과 C만큼의 무게를 넣을 수 있는 가방이 하나 있다.
 * 가방에 넣을 수 있는 물건들의 경우의 수를 구하라 
 * 조건을 만족하는 부분수열의 갯수를 모두 구하는 문제이다.
 * 그냥 시간 고려안하면 풀수야 있는데 
 * 시간고려해야 한다면 분할 정복 해야해서 조금 까다로워진다. 
 * 아직 이 문제에 대한 이해가 부족한것 같으니 추후 다시 풀어보기로한다.
 * 
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 31                           *
 * 0 <= C < 1,000,000,001                *
 * 0 <= N(i) < 1,000,000,001             *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 60분
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const long long MAX_VALUE = 1000000001;

static int N, C, cnt = 0;

static vector<long long> objWeights;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    for (int i = 0; i < N; ++i)
    {
        long long input;
        cin >> input;
        objWeights.push_back(input);
    }
    
    // #try 1 부분집합 구성
    // TLE
    // for (int i = 0; i < (1 << N); ++i)
    // {
    //     long long sum = 0;

    //     for (int j = 0; j < N; ++j)
    //     {
    //         if (i & (1 << j))
    //         {
    //             sum += objWeights[j];
    //         }
    //     }
    //     if (sum <= C)
    //     {
    //         cnt++;
    //     }
    // }

    // try 2
    // MITM
    int mid = objWeights.size() / 2;

    vector<long long> left;
    for (int i = 0; i < (1 << mid); ++i)
    {
        long long sum = 0;

        for (int j = 0; j < mid; ++j)
        {
            if (i & (1 << j))
            {
                sum += objWeights[j];
            }
        }
        if (sum <= C)
        {
            left.push_back(sum);
        }
    }

    vector<long long> right;
    for (int i = 0; i < (1 << (N - mid)); ++i)
    {
        long long sum = 0;

        for (int j = 0; j < N - mid; ++j)
        {
            if (i & (1 << j))
            {
                sum += objWeights[mid + j];
            }
        }
        if (sum <= C)
        {
            right.push_back(sum);
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());


    int i = 0;
    int j = (int)right.size() - 1;

    while (i < (int)left.size() && j >= 0) 
    {
        if (left[i] + right[j] <= C) 
        {
            cnt += (j + 1);
            ++i;
        } 
        else 
        {
            --j;
        }
    }

    cout << cnt << '\n';
    return 0;
}