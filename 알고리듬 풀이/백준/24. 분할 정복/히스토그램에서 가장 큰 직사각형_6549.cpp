/**
 * 백준 히스토그램에서 가장 큰 직사각형_6549
 * 히스토그램이 주어졌을 때 
 * 가장 큰 넓이를 갖는 직사각형을 만들어라.
 * 
 * 제한사항
 *****************************************
 * 1 <= n < 100,001                      *
 * 0 <= hi < 1,000,000,001               *
 * If Input == 0 then exit Input         *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 1 + 90분
 */


#include <iostream>
#include <vector>
#include <stack>

static const int MAX_SIZE = 100001;

using namespace std;

static int inputs[MAX_SIZE] = { 0 };
static int N;
static long long maxArea = 0;
void Calculate();

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    while (true)
    {
        cin >> N;
        if (N == 0)
        {
            break;
        }

        maxArea = 0;

        for (int i = 0; i < N; ++i)
        {
            cin >> inputs[i];
        }

        Calculate();

        cout << maxArea << '\n';
    }
    
    return 0;
}

void Calculate()
{
    // 1차 알고리즘 == 브루트 포싱
    // start with 0
    // for (int i = 0; i < N; ++i)
    // {
    //     long long minHeight = inputs[i];

    //     for (int j = i; j < N; ++j)
    //     {
    //         if (inputs[j] < minHeight)
    //         {
    //             minHeight = inputs[j];
    //         }

    //         long long width = (long long)(j - i + 1);
    //         long long area = minHeight * width;

    //         if (area > maxArea)
    //         {
    //             maxArea = area;
    //         }
    //     }
    // }

    // 2차 알고리즘 단조 증가 방식
    stack<int> indexStack;

    for (int currentIndex = 0; currentIndex < N; ++currentIndex)
    {
        while (!indexStack.empty() && inputs[indexStack.top()] > inputs[currentIndex])
        {
            int poppedIndex = indexStack.top();
            indexStack.pop();

            long long rectangleHeight = (long long)inputs[poppedIndex];

            int leftBoundary;
            if (indexStack.empty())
            {
                leftBoundary = 0;
            }
            else
            {
                leftBoundary = indexStack.top() + 1;
            }

            int rectangleWidth = currentIndex - leftBoundary; // right = currentIndex - 1
            long long rectangleArea = rectangleHeight * (long long)rectangleWidth;

            if (rectangleArea > maxArea)
            {
                maxArea = rectangleArea;
            }
        }

        indexStack.push(currentIndex);
    }

    while (!indexStack.empty())
    {
        int poppedIndex = indexStack.top();
        indexStack.pop();

        long long rectangleHeight = (long long)inputs[poppedIndex];

        int leftBoundary;
        if (indexStack.empty())
        {
            leftBoundary = 0;
        }
        else
        {
            leftBoundary = indexStack.top() + 1;
        }

        int rectangleWidth = N - leftBoundary; // right = N - 1
        long long rectangleArea = rectangleHeight * (long long)rectangleWidth;

        if (rectangleArea > maxArea)
        {
            maxArea = rectangleArea;
        }
    }
}
