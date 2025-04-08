/**
 * 백준 설탕 배달_2839
 * N키로그램 배달 해야 하는데 상품 무게가 3KG || 5KG 두 가지이다.
 * 이 둘을 조합하여 최대한 적은 봉지 갯수로 배달해야 할 무게를 구하라.
 * 
 * 제한사항
 *****************************************
 * Case == 3 || 5                        *
 * 3 <= N <= 5,000                       *
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

const static int case1 = 3;
const static int case2 = 5;

int main(void)
{
    int N;
    cin >> N;

    int count = 0;

    while (N >= 0) 
    {
        if (N % 5 == 0)
        {
            cout << N / 5 + count << endl;
            return 0;
        }
        N -= 3;
        count++;
    }

    cout << -1 << endl;
    return 0;
}