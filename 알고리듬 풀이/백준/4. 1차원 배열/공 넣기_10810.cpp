/**
* 백준 1차원 배열 10810 공 넣기
* N개의 바구니, 번호 N이 적혀있는 무수히 많은 공들(ex 1번공 N개)
* 한 바구니에 공을 한개씩 넣을 수 있다. 그런데 M번만 넣을 것 이다.
* 공을 넣는 방법은 주어진 세 정수(i, j, k)를 통해 i번 바구니부터 j번 바구니까지 k번 공을 넣는다.
*
* 제한사항
*****************************************
* 0 < N, M, <= 100                      *
* 0 < i <= j <= N                     *
* 0 < k <= N                            *
* if (j < N) print 0                    *
*****************************************
*
*
*
* 주의
* 첫 번째 입력사항에선 N과 M의 입력을 실시한다.
* 두번째 줄부터 M개의 줄에 공을 넣는 방법이 주어진다. 
* 배열 입력을 덮어쓸 수 있는지 물어보는 문제다.
*
* 풀이시간 3분
*/

#include <iostream>

using namespace std;

int main() {

    int N, M, i, j, k;

    cin >> N >> M;

    int* arr = new int[N+1] {0};
    for (int t = 1; t <= M; ++t)
    {
        cin >> i >> j >> k;
        for (int IDX = i; IDX <= j; ++IDX)
        {
            arr[IDX] = k;
        }
    }

    for (int t = 1; t <= N; ++t)
    {
        cout << arr[t] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}