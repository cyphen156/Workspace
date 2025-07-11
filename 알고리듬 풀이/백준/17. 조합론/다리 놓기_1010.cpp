/**
 * 백준 다리 놓기_1010
 * 다리를 설치할 수 있는 적합한 위치를 사이트라고 부른다. 
 * 서쪽에 N개, 동쪽에 M개가 존재할 때
 * 한 사이트는 다른 사이트 한개에 연결될 수 있다.
 * 다리를 건설할 수 있는 경우의 수를 구하라
 * 
 * 제한사항
 *****************************************
 * 0 < N <= M < 30                       *
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int N, M;

        cin >> N >> M;
        
        // mCn
        long long int result = 1;
        int combineCount = 1;
        for (int j = M; j > M-N; --j)
        {
            result *= j;
            result /= combineCount++;
        }

        cout << result << '\n';
        }
    
    return 0;
}