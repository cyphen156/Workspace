#include <iostream>

using namespace std;

int main()
{
    int H, M, T;
    cin >> H >> M >> T;

    M += T;
    // 분 단위 시간이 60을 넘어 갈 때
    // 시간 ++ 분 -60
    while (1)
    {
        // 분 단위가 60을 넘어가지 않으면 루프 탈출
        if (M < 60)
            break;
        if (M >= 60)
        {
            M -= 60;
            ++H;
        }
    }


    // 시간이 24를 넘어가면 0으로 초기화
    if (H >= 24)
        H -= 24;
    cout << H << ' ' << M << endl;
    return 0;
}