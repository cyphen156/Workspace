#include <iostream>

using namespace std;

int main()
{
    int H, M;
    cin >> H >> M;

    // 45분 이상일 경우 시간, 분을 건드릴 이유가 없음
    if (M >= 45)
    {
        M -= 45;
    }

    // 45분 이하일 경우 시간-- 분+60 -45
    else
    {
        // H > 0일 경우 24시로 올릴 필요 없음
        if (H != 0)
        {
            H--;
        }
        else
            H += 23;
        M += 15;
    }
    cout << H << ' ' << M << endl;
    return 0;
}