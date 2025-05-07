/**
 * 백준 나이순 정렬_10814
 * 입력데이터(나이),  입력된 순서를 통해 2계층 정렬하기
 * 
 * 제한사항
 *****************************************
 * 0 < N ≤ 100,000                       *
 * 1 <= age <= 200                       *
 * 0 < Name <= 100                       *
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
#include <string>

using namespace std;

struct Member
{
    int age;
    string name;
    int order;
};

bool Compare(Member* first, Member* second)
{
    if (first->age < second->age)
    {
        return 1;
    }
    else if (first->age == second->age)
    {
        if (first->order < second->order)
        {
            return 1;
        }
    }
    return 0;
};

void Merge(Member* arr[], int left, int right, int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Member** L = new Member*[n1];
    Member** R = new Member*[n2];

    for (int i = 0; i < n1; ++i)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (Compare(L[i], R[j]))
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void MergeSort(Member* arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, right, mid);
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    Member* memberArray[100000];
    for(int i = 0; i < N; ++i)
    {
        memberArray[i] = new Member;
        cin >> memberArray[i]->age >> memberArray[i]->name;
        memberArray[i]->order = i;
    }

    MergeSort(memberArray, 0, N-1);

    for(int i = 0; i < N; ++i)
    {
        cout << memberArray[i]->age << ' ' << memberArray[i]->name << '\n';
    }

    for (int i = 0; i < N; ++i)
    {
        delete memberArray[i];
    }
    return 0;
}