/**
 * 백준 약수들의 합_9506
 * 자기 자신을 제외한 모든 약수들을 더했을 때 자기자신과 같다면 완전수이다.
 * 완전수를 찾아라
 * 
 * 출력예시
 * 6 = 1 + 2 + 3
 * 2 is NOT perfect.
 * 8 = 1 + 2 + 4 + 7 + 14
 * 
 * 제한사항
 *****************************************
 * 6 = 1 + 2 + 3                         *
 * 12 is NOT perfect.                    *
 * 28 = 1 + 2 + 4 + 7 + 14               *
 *****************************************
 *
 *
 *
 * 주의
 * 오름차순 나열
 * if Input == -1  ==> end;
 * 2 < N < 100,000
 * 
 * 풀이시간 10분
 */


#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    
    while(1)
    {
        vector<int> v;
        int sum = 0;
        int input;
        cin >> input;
        if(input == -1)
        {
            break;
        }       
        for (int i = 1; i < input; ++i)
        {
            if (input % i == 0)
            {
                v.push_back(i);
                sum += i;
            }
        }
        cout << input << " ";
        if (sum != input)
        {
            cout << "is NOT perfect.";
        }
        else
        {
            cout << "= " << v[0];
            for (int i = 1; i < v.size(); ++i)
            {
                cout << " + " << v[i];
            }
        }
        cout << endl;
    }
    return 0;
}