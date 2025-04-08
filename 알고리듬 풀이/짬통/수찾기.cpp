#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int BSearch(int* arr, int key, int N)
{
	int left = 0, right = N - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == key)
		{
			return 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return 0;
};

static int arr[100000];
int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
	
    sort(arr, arr + N);
	int M;
    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int T;
        cin >> T;
        
        printf("%d\n", BSearch(arr, T, N));
    }
    
    
    return 0;
}