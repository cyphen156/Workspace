/**
 * 백준 약수 구하기_2501
 * 두 자연수를 제공했을 때 첫번째 수의 약수들 중 K번째로 작은 수 출력하기
 * 약수가 존재하지 않는 경우 0을 출력한다.
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 10,000                       *
 * 1 <= k <=N                            *
 *****************************************
 *
 *
 *
 * 주의
 * 
 * 
 * 풀이시간 5분
 */


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;
    // 인덱스 맞추기
    --K;
    vector<int> v;

    for (int i = 1; i <= N; ++i)
    {
        if (N % i == 0)
        {
            v.push_back(i);
        }
    }
    if (v.size() == 0)
    {
        cout << 0 << endl;
        return 1;
    }
    cout << v[K] << endl;
    return 0;
}