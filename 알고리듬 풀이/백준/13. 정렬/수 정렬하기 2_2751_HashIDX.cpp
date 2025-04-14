/**
 * 백준 수 정렬하기 2_2751_HashIDX
 * 중복 없는 오름차순 정렬, 버블정렬 말고 다른거 써라
 * // 퀵소트
 * 또는 중복이 없다는 전제조건이 있기 때문에 Bool 해시 배열로 사용가능
 * 
 * 제한사항
 *****************************************
 * 1 ≤ N ≤ 1,000,000                     *
 * -1,000,000 ≤ Input ≤ 1,000,000        *
 *****************************************
 *
 *
 *
 * 주의
 * 입력 자료 수가 커진다. 버블 정렬하면 TimeLimit 발생
 * 
 * 풀이시간 5분
 */

#include <iostream>
#define MAX_VALUE 1000000

using namespace std;

bool check[2 * MAX_VALUE + 1] = { 0 };  // 자동초기화  false

int main(void)
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        // 음수 특수처리
        check[input + MAX_VALUE] = true;
    }

    for (int i = 0; i < N + 1; ++i)
    {
        if (check[i] != 0)
        {
            cout << i - MAX_VALUE << '\n';
        }
    }
    return 0;
}