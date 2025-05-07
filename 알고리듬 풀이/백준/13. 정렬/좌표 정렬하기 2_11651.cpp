/**
 * 백준 좌표 정렬하기 2_11651
 * 1과 다른 점은 y축 기준으로 정렬하기 정도이다. 그렇기 때문에 1의 좌표 입력을 거꾸로하면된다.
 * 
 * 제한사항
 *****************************************
 * 0 <  N ≤ 100,000                      *
 * -100,000 ≤ X, Y ≤ 100,000             *
 *****************************************
 *
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 0분
 */


 #include <iostream>

 #define MAXCOUNT 100000
 
 using namespace std;
 
 struct Position
 {
     int x;
     int y;
 };
 void MergeSort(Position* array, int left, int right);
 void Merge(Position* array, int left, int mid, int right);
 
 void MergeSort(Position* array, int left, int right)
 {
     if (left >= right)
     {
         return;
     }
     int mid = left + (right - left) / 2;
 
     MergeSort(array, left, mid);
     MergeSort(array, mid + 1, right);
 
     Merge(array, left, mid, right);
 }
 
 void Merge(Position* array, int left, int mid, int right)
 {
     int leftSize = mid - left + 1;
     int rightSize = right - mid;
 
     Position* leftArr = new Position[leftSize];
     Position* rightArr = new Position[rightSize];
 
     for (int i = 0; i < leftSize; ++i)
     {
         leftArr[i] = array[left + i];
     }
 
     for (int i = 0; i < rightSize; ++i)
     {
         rightArr[i] = array[mid + 1 + i];
     }
 
     int i = 0, j = 0, k = left;
 
     while (i < leftSize && j < rightSize)
     {
         if (leftArr[i].y < rightArr[j].y ||
             (leftArr[i].y == rightArr[j].y && leftArr[i].x <= rightArr[j].x))
         {
             array[k++] = leftArr[i++];
         }
         else
         {
             array[k++] = rightArr[j++];
         }
     }
 
     while (i < leftSize)
     {
         array[k++] = leftArr[i++];
     }
 
     while (j < rightSize)
     {
         array[k++] = rightArr[j++];
     }
 
     delete[] leftArr;
     delete[] rightArr;
 }
 
 
 int main(void)
 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
     int N;
     cin >> N;
 
     Position position[MAXCOUNT]; 
     for (int i = 0; i < N; ++i)
     {
         int x, y;
         cin >> x >> y;
         
         position[i].x = x;
         position[i].y = y;
     }
 
     
     MergeSort(position, 0, N - 1);
 
     for (int i = 0; i < N; ++i)
     {
         cout << position[i].x << ' ' << position[i].y << '\n';
     }
     return 0;
 }