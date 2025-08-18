/**
 * 백준 행렬 제곱_10830
 * N * N크기의 정방 행렬이 주어졌을 때, A의 B제곱을 구하는 프로그램을 작성하라
 * 각 원소를 1,000으로 나눈 나머지를 출력한다.
 * 이 문제에서 정방 행렬의 크기가 5 이하로 작기 때문에 분할정복하지 않는다.
 * 대신 제곱수가 매우 크기 때문에 이진 분할하여 빠른 제곱을 이용한다.
 * 
 * 제한사항
 *****************************************
 * 2 <= N < 6                            *
 * 1 <= B < 100,000,000,001              *
 * 0 <= Value < 1,001                    *
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

static const long long int MAX_POWER_VALUE = 100000000001;
static const int MAX_SIZE = 5;
static const int MOD = 1000;

using namespace std;

static long long int matrix[MAX_SIZE][MAX_SIZE] = { 0 };
static long long int resultMatrix[MAX_SIZE][MAX_SIZE] = { 0 };

int N;
long long int B;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> B;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    long long tmp[MAX_SIZE][MAX_SIZE];
    bool inited = false;

    while (B > 0)
    {
        if (B & 1){
            if (!inited)
            {
                // 첫 1비트: R := base
                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < N; ++j)
                    {
                        resultMatrix[i][j] = matrix[i][j];
                    }
                }
                inited = true;
            } 
            else 
            {
                // R = R * base  (tmp = resultMatrix * matrix)
                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < N; ++j)
                    {
                        long long sum = 0;
                        for (int k = 0; k < N; ++k)
                        {
                            sum = (sum + (resultMatrix[i][k] % MOD) * (matrix[k][j] % MOD)) % MOD;
                        }
                        tmp[i][j] = sum;
                    }
                }
                // resultMatrix = tmp
                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < N; ++j)
                    {
                        resultMatrix[i][j] = tmp[i][j];
                    }
                }
            }
        }

        // base = base * base  (tmp = matrix * matrix)
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                long long sum = 0;
                for (int k = 0; k < N; ++k)
                {
                    sum = (sum + (matrix[i][k] % MOD) * (matrix[k][j] % MOD)) % MOD;
                }
                tmp[i][j] = sum;
            }
        }
        // matrix = tmp
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                matrix[i][j] = tmp[i][j];
            }
        }

        B >>= 1;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << resultMatrix[i][j] % 1000 << ' ';
        }
        cout << '\n';
    }

    return 0;
}