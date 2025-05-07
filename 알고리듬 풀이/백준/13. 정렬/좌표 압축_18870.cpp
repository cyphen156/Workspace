/**
 * 백준 좌표 압축_18870
 * 1차원 좌표가 주어진다. 
 * f(x1) =  countIF(x1 > Except Equal val( x2 || x3 || xn-1))
 * 
 * 제한사항
 *****************************************
 * 0 < N ≤ 1,000,000                     *
 * -10**9 <= Input <= 10**9              *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 30분
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BSearch(int search, vector<int>& copyVector)
{
    int left = 0;
    int right = size(copyVector) - 1;
    
    while (left <= right)
    {
        int mid =  (left + right) / 2;
        if (search == copyVector[mid])
        {
            return mid;
        }
        else if (search > copyVector[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return 0;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> inputs;

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        inputs.push_back(input); 
    }

    vector<int> copyVector(inputs);

    sort(copyVector.begin(), copyVector.end());
    copyVector.erase(unique(copyVector.begin(),copyVector.end()),copyVector.end());
    for (int i = 0; i < size(inputs); ++i)
    {
        cout << BSearch(inputs[i], copyVector)<< ' '; 
    }

    cout << '\n';
    return 0;
}