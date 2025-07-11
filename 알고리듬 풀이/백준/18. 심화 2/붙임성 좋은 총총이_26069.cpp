/**
 * 백준 붙임성 좋은 총총이_26069
 * 맨 처음 문자열 "ChongChong"이 나온 시점부터 기록을 시작한다.
 * 이후 총총이와 만난 사람, 만난사람과 만난사람으로 연쇄 적으로 춤추는 사람의 수가 늘어난다.
 * 
 * 제한사항
 *******************************************
 * 0 < N <= 1000                           *
 * 0 < NameLength <= 20                    *
 * Name "ChongChong" appears at Least once *
 *******************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 30분
 */


#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    bool _start = false;

    set<string> meatPeoples;

    for (int i = 0; i < N; ++i)
    {
        string first, second;
        cin >> first >> second;

        if (first == "ChongChong" ||  second == "ChongChong")
        {
            _start = true;
            meatPeoples.insert(first);
            meatPeoples.insert(second);
        }

        if (_start)
        {
            if (meatPeoples.count(first) || meatPeoples.count(second))
            {
                meatPeoples.insert(first);
                meatPeoples.insert(second);
            }
        }
    }

    cout << meatPeoples.size() << '\n';
    return 0;
}