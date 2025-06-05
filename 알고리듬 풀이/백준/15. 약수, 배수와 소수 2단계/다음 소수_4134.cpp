/**
 * 백준 다음 소수_4134
 * 주어진 수보다 크고 인접한 가장 작은 소수를 하나씩 출력한다.
 * 
 * 매우 큰 범위의 소수가 도출될 수 있다.
 * -> 일반적인 방법론 사용 불가능
 * --> 확률론적 방법론 사용
 * // 밀러 - 라빈 소수 판정법 사용
 * 메모이제이션 사용
 * 
 * 제한사항
 *****************************************
 * 0 <= N <= 4*10**9 == 약 40억          *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 0분
 */


#include <iostream>

using namespace std;

// 밀러-라빈 연산기
long long int ModulorPower(long long int base, long long int exponent, long long int modulos);

// 소수 판정기
bool IsPrime(unsigned int n);

// 나보다 큰 최인접소수 찾기
unsigned int FindNextPrime(unsigned int input);


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        unsigned int input;
        cin >> input;
        cout << FindNextPrime(input) << '\n';
    }
    return 0;
}

// d*2**r
long long int ModuloPower(long long int base, long long int exponent, long long int modulos)
{
    long long int result = 1;
    base %= modulos;

    while(exponent > 0)
    {
        if (exponent & 1)
        {
            result = (result * base) % modulos;
        }
        exponent >>= 1;
        base = (base * base) % modulos;
    }

    return result;
}


bool IsPrime(unsigned int n)
{
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    unsigned int d = n - 1;
    int r = 0;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }

    int bases[] = {2, 3};

    for (int a : bases)
    {
        if (a >= n) continue;

        long long x = ModuloPower(a, d, n);
        if (x == 1 || x == n - 1) continue;

        bool witness = false;
        for (int i = 1; i < r; i++)
        {
            x = ModuloPower(x, 2, n);
            if (x == n - 1)
            {
                witness = true;
                break;
            }
        }

        if (!witness) return false;
    }

    return true;
}


unsigned int FindNextPrime(unsigned int input)
{
    if (input <= 2)
    { 
        return 2;
    }

    // 만약 Input이 짝수라면 항상 합성수가 나올 테니 1을 올려서 홀수로 만들어서 소수 판별 시작
    if (input % 2 == 0) 
    {
        ++input;
    }

    while (!IsPrime(input))
    {
        input += 2;
    }
    
    return input;
}