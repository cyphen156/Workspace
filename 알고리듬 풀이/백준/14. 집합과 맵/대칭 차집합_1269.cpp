/**
 * 백준 대칭 차집합_1269
 * 대칭 차집합이란 (A - B) + (B - A)를 대칭 차집합이라고 한다.
 * 대칭 차집합의 원소 개수를 출력하는 프로그램을 만들어라
 * 한마디로 (A+B) - (A ∩ B)이다.
 * 
 * 제한사항
 *****************************************
 * 0 < Elements <= 200,000               *
 * 0 < Data <= 100,000,000               *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
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
    
    int A, B;

    cin >> A >> B;

    set<int> setA, setB;
    for (int i = 0; i < A; ++i)
    {
        int data;
        cin >> data;
        setA.insert(data);
    }
    
    for (int i = 0; i < B; ++i)
    {
        int data;
        cin >> data;
        setB.insert(data);
    }

    int count = 0;

    for (auto& data : setA)
    {
        if (setB.find(data) != setB.end())
        {
            count++;
        }
    }
    cout << setA.size() + setB.size() - 2 * count;
    return 0;
}