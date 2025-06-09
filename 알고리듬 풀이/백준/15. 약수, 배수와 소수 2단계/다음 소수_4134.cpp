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
 * 꼭 다시 한번 더 보고 이해해보기
 * 
 * 풀이시간 120분
 */


#include <iostream>

typedef unsigned long long ull;
using namespace std;

// 거듭제곱 연산을 통해 합성수인지 판단
ull ModuloPower(ull base, ull exponent, ull modulos);

// 밀러-라빈 소수 판정기
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

// 지수 연산
ull ModuloPower(ull base, ull exponent, ull modulos)
{
    ull result = 1;
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

// 실제 소수 판정
bool IsPrime(unsigned int n)
{
    // 예외 처리부
    if (n < 2) 
    {
        return false;
    }

    if (n == 2 || n == 3) 
    {
        return true;
    }

    if (n % 2 == 0) 
    {
        return false;
    }

    // n-1 = d * 2^r 꼴로 분해
    unsigned int d = n - 1;

    int r = 0;

    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }

    // 밑
    unsigned int bases[3] = {2, 7, 61};

    for (int a : bases)
    {
        // 예외처리
        if (a >= n) 
        {
            continue;
        }

        long long x = ModuloPower(a, d, n);
        
        if (x == 1 || x == n - 1) 
        {
            continue;
        }

        bool isPassed  = false;
        
        for (int i = 1; i < r; i++)
        {
            x = ModuloPower(x, 2, n);
            if (x == n - 1)
            {
                isPassed  = true;
                break;
            }
        }

        if (!isPassed) 
        {
            return false;
        }
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

    // 단순하게 2씩 늘려가면서 순회
    while (!IsPrime(input))
    {
        input += 2;
    }
    
    return input;
}