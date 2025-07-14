/**
 * 백준 알고리즘 수업 - 병합 정렬 1_24060
 * 병합 정렬 구현하기
 * N은 배열의 크기, K는 병합 정렬 수행시 저장되는 횟수를 체크하는 수이다.
 * 
 * 출력은 다음과 같다.
 * 배열 A에 K 번째 저장 되는 수를 출력한다. 
 * 저장 횟수가 K 보다 작으면 -1을 출력한다.
 * 
 * 의사 코드는 다음과 같다.
 ******************************************************************************
 * merge_sort(A[p..r]) { # A[p..r]을 오름차순 정렬한다.
 *     if (p < r) then {
 *         q <- ⌊(p + r) / 2⌋;       # q는 p, r의 중간 지점
 *         merge_sort(A, p, q);      # 전반부 정렬
 *         merge_sort(A, q + 1, r);  # 후반부 정렬
 *         merge(A, p, q, r);        # 병합
 *     }
 * }
 * 
 * # A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
 * # A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
 * merge(A[], p, q, r) {
 *     i <- p; j <- q + 1; t <- 1;
 *     while (i ≤ q and j ≤ r) {
 *         if (A[i] ≤ A[j])
 *         then tmp[t++] <- A[i++]; # tmp[t] <- A[i]; t++; i++;
 *         else tmp[t++] <- A[j++]; # tmp[t] <- A[j]; t++; j++;
 *     }
 *     while (i ≤ q)  # 왼쪽 배열 부분이 남은 경우
 *         tmp[t++] <- A[i++];
 *     while (j ≤ r)  # 오른쪽 배열 부분이 남은 경우
 *         tmp[t++] <- A[j++];
 *     i <- p; t <- 1;
 *     while (i ≤ r)  # 결과를 A[p..r]에 저장
 *         A[i++] <- tmp[t++]; 
 * }
 ******************************************************************************
 * 
 * 제한사항
 *****************************************
 * 4 < ArraySize N <= 500,000            *
 * 0 < StoredCount K <= 100,000,000      *
 * 0 < Ai ≤ 1,000,000,000                *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 90분
 */

#define MAX_SIZE 5000001

#include <iostream>

static int arr[MAX_SIZE];
static int temp[MAX_SIZE];

using namespace std;

void merge_sort(int* origin, int left, int right);
void merge(int* origin, int left, int mid, int right);

static int cnt = 0;
static int result = 0;
static int K; 

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        unsigned long long input;
        cin >> input;
        arr[i] = input;
    }
    

    merge_sort(arr, 0, N - 1);

    if (cnt < K)
    {
        result = -1;
    }

    cout << result << '\n';
    return 0;
}

void merge_sort(int* origin, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(origin, left, mid);
        merge_sort(origin, mid + 1, right);
        merge(origin, left, mid, right);
    }
}

void merge(int* origin, int left, int mid, int right)
{
    int i = left, j = mid + 1, t = 1;

    while (i <= mid && j <= right)
    {
        if (origin[i] <= origin[j])
        {
            temp[t++] = origin[i++];
        }
        else 
        {
            temp[t++] = origin[j++];
        }
    }

    while (i <= mid)
    {
        temp[t++] = origin[i++];
    }

    while (j <= right)
    {
        temp[t++] = origin[j++];
    }

    i = left;
    t = 1;

    while (i <= right)
    {
        origin[i] = temp[t++];
        
        cnt++;
        
        if (cnt == K)
        {
            result = origin[i];
        }
        
        i++;
    }
}