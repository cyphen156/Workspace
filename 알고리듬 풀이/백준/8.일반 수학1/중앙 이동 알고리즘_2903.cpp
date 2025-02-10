/**
 * 백준 중앙 이동 알고리즘_2903
 * 각 변의 중앙과 정사각형 중앙에 점을 하나 생성하는 프로그램
 * 모든 사각형들은 인접해 있으므로 중복 점을 고려해야한다.
 * 점의 갯수는 사각형의 넓이와 같다
 * 점의 증가율을 찾아내야 한다.
 * 
 * 제한사항
 *****************************************
 * 없다                                  *
 *****************************************
 *
 *
 *
 * 주의
 * 없다
 * 
 * 풀이시간 30분
 */


#include <iostream>

using namespace std;

int main(void)
{
    int totalVertex = 1;
    int repeat = 0;
    cin >> repeat;

    // 점의 갯수는 사각형의 넓이라고 본다
    // 중요한 것은 점의 증가율
    // ==> 1 : 2, 2 : 3, 3 : 5
    // ====> 초기상태 : (1+2**REPEAT)**2

    for (int i = 0; i < repeat; ++i)
    {
        totalVertex *= 2;
    }
    totalVertex++;
    // POWER 2
    totalVertex *= totalVertex;
    cout << totalVertex << endl;
    return 0;
}