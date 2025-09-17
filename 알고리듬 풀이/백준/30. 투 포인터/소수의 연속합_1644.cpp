/**
 * 백준 소수의 연속합_1644
 * 하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들과 
 * 나타낼 수 없는 자연수들이 있다. 
 * 가령 3+5 = 8은 연속된 두 소수의 합으로 나타낼 수 있는 자연수이고,
 * 7+13 = 20은 연속되지 않은 두 소수의 합이니 
 * 연속된 소수의 합으로 나타낼 수 없는 자연수이다.
 * 자연수가 주어졌을 때 
 * 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하라.
 * 
 * Hint
 * 에라토스테네스의 체를 통해 빠르게 소수를 구할 수 있다.
 * 

 * 제한사항
 *****************************************
 * 1 <= N < 4,000,001                    *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 15분
 */


#include <iostream>
#include <vector>

using namespace std;

static const int MAX_SIZE = 4000001;

static int N, cnt = 0;

// false = primeNumber, true = NotPrimeNumber
// Sorce of Prime Numbers
static bool isNotPrime[MAX_SIZE] = { false };

static vector<int> primeNumbers;

void FindPrimeNumber();
void Solve(int N);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    FindPrimeNumber();
    Solve(N);
    cout << cnt << '\n';
    return 0;
}

// using Sieve of Eratosthenes
void FindPrimeNumber()
{
    isNotPrime[0] = isNotPrime[1] = true;

    for (long long i = 2; i<= N; ++i)
    {
        if (!isNotPrime[i])
        {
            for (long long j = i * i; j <= N; j += i)
            {
                isNotPrime[j] = true;
            }
            primeNumbers.push_back(i);
        }
    }
}

void Solve(int N)
{
    int left = 0;
    int right = 0;

    int sum = 0;

    while (true)
    {
        if (sum >= N)
        {
            if (sum == N)
            {
                ++cnt;
            }
            if (left < primeNumbers.size())
            {
                sum -= primeNumbers[left++];
            }
            else 
            {
                break;
            }
        }
        else
        {
            if (right < primeNumbers.size())
            {
                sum += primeNumbers[right++];
            }
            else
            {
                break;
            }
        }
    }
}