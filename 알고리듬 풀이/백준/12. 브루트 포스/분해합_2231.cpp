/**
 * 백준 분해합_2231
 * 분해합 : N과 N을 이루는 각 자리수의 합 (245 => 245 + 2 + 4 + 5 == 256)
 * 생성자 :  M의 분해합이 N인 경우
 * 분해합이 주어졌을 때 가장 작은 생성자를 구하라
 * 
 * 제한사항
 *****************************************
 * 0 < N <= 1,000,000                    *
 * if No Result, returns 0               *
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

using namespace std;

int main(void)
{
    bool isConstructor = false;
    int N;

    cin >> N;
    int idx = 0;
    for (idx = 1; idx < N; idx++) {
        int sum = idx;
        int temp = idx;

        while (temp) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == N) {
            isConstructor = true;
            break;
        }
    }
    if (isConstructor)
    {
        cout << idx << endl;
    }
    else 
    {
        cout << 0 << endl;
    }
    return 0;
}

