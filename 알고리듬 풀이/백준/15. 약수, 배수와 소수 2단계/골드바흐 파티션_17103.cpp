/**
 * 백준 골드바흐 파티션_17103
 * 골드바흐는 2보다 큰 짝수는 두 소수의 합으로 나타낼 수 있다는 것을 추측했다.
 * --> 2를 제외하면 모든 소수는 홀수이기 때문에 홀수 + 홀수는 짝수이다.
 * 짝수가 주어졌을 때 두 소수의 합으로 만들 수 있는 경우의 수를 구하라.
 * 
 * 제한사항
 *****************************************
 * 0 < Test T <= 100                     *
 * 2 < N <= 1,000,000                    *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 30분
 */


#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 1000001

static bool isNotPrime[MAX_SIZE];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 소수 배열
    vector<int> primeNumbers;

    // 에라토스테네스스
    isNotPrime[0] = isNotPrime[1] = true;

    for (int i = 2; i * i < MAX_SIZE; ++i)
    {
        // 현재 소수라고 마스킹 되어 있다면
        if (!isNotPrime[i])
        {
            // 곱한수는 모두 합성수 처리
            for (int j = i * i; j <= MAX_SIZE; j += i)
            {
                isNotPrime[j] = true;
            }
        }
    }
    
    for (int i = 2; i < MAX_SIZE; ++i)
    {
        // 소수 배열 만들기
        if (!isNotPrime[i])
        {
            primeNumbers.push_back(i);
        }
    } 

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {   
        int input;
        cin >> input;
        
        int count = 0;

        for (int j = 0; j < size(primeNumbers); ++j)
        {
            if (primeNumbers[j] > input / 2)
            {
                break;
            }
            // 입력받은 짝수에서 현재 소수를 빼고
            int idx = input - primeNumbers[j];
            if (!isNotPrime[idx])
            {
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}