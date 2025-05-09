/**
 * 백준 회사에 있는 사람_7785
 * 출근 할 때 Push, 퇴근 할때 Pop
 * 언제든 출근하고 퇴근할 수 있으므로 스택, 큐 자료형이 아니다.
 * -> 퇴근 할 때 탐색해서 제거해야 한다.
 * 아직 퇴근하지 않은 사람을 출력하는 프로그램
 * 첫단어를 기준으로 해싱
 * 
 * 제한사항
 *****************************************
 * 1 < N <= 1,000,000                    *
 * 0 < NameLength <= 5                   *
 * InputsStr == "enter"                  *
 * InputsStr == "leave"                  *
 * 대소문자 구분                          *
 *****************************************
 *
 *
 *
 * 주의
 * 퇴근 먼저하고 출근하는 경우는 없다.
 * 사전 순의 역순으로 한 줄에 한 명씩 출력
 * 
 * 풀이시간 20분
 */


#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    set<string> arr;

    for (int i = 0; i < N; ++i)
    {
        string name , message;
        cin >> name  >> message;
        if (message == "enter")
        {
            arr.insert(name );
        }
        else if (message == "leave")
        {
            arr.erase(name);
        }
    }

    for (auto iter= arr.rbegin(); iter != arr.rend(); ++iter)
        {
            cout << *iter << '\n';
        }
    return 0;
}