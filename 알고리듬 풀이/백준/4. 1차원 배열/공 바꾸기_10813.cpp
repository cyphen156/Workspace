/**
* 백준 1차원 배열 10813 공 바꾸기
* 이전 문제에서 이어지는 연계문제, 초기에 공이 모두 N번 바구니에 N번 공이 들어가있다고 가정한다. 
* M번 교환을 시도하는데 두 바구니를 선택하여 서로 공을 교환한다.
*
* 제한사항
*****************************************
* 0 < N, M <= 100                       *
* 0 < i <= j <= N                       *
*****************************************
*
*
*
* 주의
* 간단한 변수 교체 가능 여부를 물어보는 문제이다. 임시변수를 사용하여 두 바구니에 있는 공들을 바꾼다.
*
* 풀이시간 10분
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, M, i, j;

    cin >> N >> M;

    vector<int> arr;

    int IDX = 0;

    // 바구니 초기화
    while (1)
    {
        if (IDX > N)
        {
            break;
        }
        arr.push_back(IDX++);
    }

    for (int k = 0; k < M; ++k)
    {
        cin >> i >> j;

        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    for (int k = 1; k <= N; ++k)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
    return 0;
}