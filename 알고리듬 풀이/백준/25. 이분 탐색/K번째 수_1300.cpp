/**
 * 백준 K번째 수_1300
 * N X N크기의 배열 A가 존재한다.
 * 이 배열의 요소를 일차원 배열B에 넣어 오름차순으로 정렬했을 때 B[k]를 구하라
 * 
 * 제한사항
 *****************************************
 * 1 <= N < 100,001                      *
 * 1 <= K < min(1,000,000,001, N^2)      * 
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 30분
 */


#include <iostream>
#include <vector>
#include <algorithm>

static const long long MAX_N_SIZE = 100000;
static const long long MAX_K_SIZE = 10000000000;

using namespace std;

static long long N;
static long long K;

long long BinarySearch(long long value);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N >> K;
    
    // 1차 알고리즘 
    // 정답은 맞는데 메모리 사용량 초과
    // 최대 동적 할당 
    // => 8Byte X 10,000,000,000
    //             G   M    K   Byte
    // ==> 80GB
    // 
    // vector<long long> matrixB;
    // 
    // for (long long i = 1; i <= N; ++i)
    // {
    //     for (long long j = 1; j <= N; ++j)
    //     {
    //         matrixB.push_back(i * j);
    //     }   
    // }
    // 
    // sort(matrixB.begin(), matrixB.end());
    // 
    // cout << matrixB[K - 1] << '\n';

    cout << BinarySearch(K);

    return 0;
}

long long BinarySearch(long long value)
{
    long long left = 1;
    long long right = min(value, N * N);

    long long result = right;
    while (left <= right)
    {
        long long mid = (right + left) / 2;

        long long cnt = 0;

        for (long long i = 1; i <= min(mid, N); ++ i)
        {
            long long add = mid / i;
            if (add > N)
            {
                add = N;
            }
            cnt += add;

            if (cnt >= value)
            {
                break;
            }
        }
        if(cnt >= value)
        {
            result = mid;
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }
    }

    return result;
}
