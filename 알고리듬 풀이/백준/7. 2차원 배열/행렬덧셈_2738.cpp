/**
 * 백준 행렬 덧셈_2738
 * 두 행렬을 더하는 프로그램을 만들면 된다.
 * 
 * 제한사항
 *****************************************
 * 0 < N, M <= 100                       *
 * -100 <= Element <= 100                *
 *****************************************
 *
 *
 *
 * 주의
 * 행렬의 원소의 절댓값이 100 이하인 정수 -> 음수 양수 모두 가능
 * 두 행렬의 크기는 항상 같아야 한다. -> 행렬 연산의 공리
 * 
 * 풀이시간 30분
 */


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N = 0, M = 0;
    cin >> N >> M;

    int** arr1 = new int*[N];
    int** arr2 = new int*[N];
    // 두번의 행렬 입력
    for (int T = 0; T < 2; ++T)
    {
        for (int i = 0; i < N; ++i)
        {
            // 목표 배열 설정
            int** Dest;
            if (T == 0)
            {
                Dest = arr1;
            }
            else 
            {   
                Dest = arr2;
            }

            // 행 생성
            int* arr = new int[M];
            Dest[i] = arr;

            // 열 입력
            for (int j = 0; j < M; ++j)
            {
                int Input;
                cin >> Input;
                // 행 입력
                Dest[i][j] = Input;
            }
        }
    }

    for (int i = 0; i < N; ++i)
        {
            // 열 덧셈
            for (int j = 0; j < M; ++j)
            {
                // 행 덧셈
                cout << arr1[i][j] +  arr2[i][j] << " ";
            }
            cout << "\n";
        }
    return 0;
}