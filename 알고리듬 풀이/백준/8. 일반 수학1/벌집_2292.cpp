/**
 * 백준 벌집_2292
 * 정육각형 모양의 중앙 방에서 부터 시작하여 회전하면서 방에 번호를 매기고 최단거리를 구하는 프로그램
 * 방 만드는 갯수의 수식은 from N=0 to N−1 ∑(6N) + 1개
 * ==> 6N(N-1)/2 + 1
 * Room까지 가려면 걸리는 최단 거리 경로는 항상 N칸이다
 * 
 * 제한사항
 *****************************************
 * 0 < roomNumber <= 1,000,000,000       *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 60분
 */


#include <iostream>

using namespace std;

int main(void)
{
    int roomNumber = 0;
    int N = 1;

    cin >> roomNumber;

    --roomNumber;
    while (3*(N * (N-1)) < roomNumber)
    {
        ++N;
    }
    
    cout << N << endl;
    return 0;
}