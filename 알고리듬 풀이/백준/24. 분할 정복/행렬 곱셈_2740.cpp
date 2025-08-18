/**
 * 백준 행렬 곱셈_2740
 * N X M크기의 행렬과 M X K 크기의  행렬이 주어졌을 때 두 행렬을 곱하는 프로그램을 작성한다.
 * 그래픽 카드에서 보통 행렬의 연산은 병렬연산을 지원해야 한다는것을 생각하면 분할 정복해야 하는 이유를 알 수 있다.
 * 1. 블록 단위  행렬 연산의 분할 정복을 구성할 수 있다. O(N^3)
 * 
 * 2. 슈트라센(Strassen)의 알고리즘을 이용할 수 있다. O(N^2.807)
 * 
 * (N X M) * (M X K) => (N X K)의 행렬이 나오는데, 
 * 슈트라센의 알고리즘은 이 N과 M, K를 2의 거듭제곱의 형태를 갖는 행렬로 만들어
 * 확장된 부분은 모두 0으로 채워넣어 최소 크기인 2X2크기의 단위로 분할 / 병합 정복하는 기법이다.
 * 슈트라센 알고리즘은 크기가 패딩을 채워 정방 행렬을 구성하는 과정이 추가 되기 때문에 
 * 필연적으로 기존 블록 단위 분할 정복 기법보다 덧셈 연산 횟수가 늘어난다.
 * 
 * 하지만 그럼에도 불구하고 이론적 성능이 더 빠른 이유는 
 * 
 * 블록마다 발생하는 8번의 곱셈 연산을 
 * 7번의 곱셈과 추가 덧셈으로 치환했기 때문에 
 * 덧셈 연산은 일반적으로 점화식의 지배항이 더 낮은 차수이기 때문에 무시되어 
 * 곱셈 연산만을 시간복잡도에 고려하기 때문이다.
 * 
 * 
 * 제한사항
 *****************************************
 * 1 <= N, M, K < 101                    *
 * -100 <= value < 101                   *
 *****************************************
 *
 *
 *
 * 주의
 * 없다.
 * 
 * 풀이시간 (문제 해석 + 구현)
 * 30 + 30/90분
 */


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static const int MAX_SIZE = 128;

static int N, M, K;
static int maxSize = 0;
static int paddingSize = 1;
static int depth = 0;

static int matrixA[MAX_SIZE][MAX_SIZE] = { 0 };
static int matrixB[MAX_SIZE][MAX_SIZE] = { 0 };

static int resultMatrix[MAX_SIZE][MAX_SIZE] = { 0 };

void DivideAndConquer(int rowA, int colA, int rowB, int colB, int depth);
void Strassen(int rowA, int colA, int rowB, int colB, int depth);
static vector<vector<int>> addsub(const vector<vector<int>>& X, const vector<vector<int>>& Y, int s);

static void StrassenRec(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // Input
    // MatrixA
    cin >> N >> M;
    maxSize = max(N, M);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> matrixA[i][j];
        }
    }

    // MatrixB
    cin >> M >> K;
    maxSize = max(maxSize, K);
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            cin >> matrixB[i][j];
        }
    }

    // calculate
    while (paddingSize < maxSize)
    {
        paddingSize <<= 1;
        depth++;
    }

    // for (int i = 0; i < N; ++i)
    // {
    //     for (int j = 0; j < K; ++j)
    //     {
    //         for (int k = 0; k < M; ++k)
    //         {
    //             resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
    //         }
    //     }
    // }
    // DivideAndConquer(0, 0, 0, 0, depth);
    Strassen(0, 0, 0, 0, depth);

    // Output
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            cout << resultMatrix[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

void DivideAndConquer(int rowA, int colA, int rowB, int colB, int depth)
{
    if (depth == 0)
    {
        resultMatrix[rowA][colB] += matrixA[rowA][colA] * matrixB[rowB][colB];
        return;
    }

    int h = 1 << (depth - 1);

    // C11 = A11*B11 + A12*B21
    DivideAndConquer(rowA, colA, rowB, colB, depth - 1);
    DivideAndConquer(rowA, colA + h, rowB + h, colB, depth - 1);

    // C12 = A11*B12 + A12*B22
    DivideAndConquer(rowA, colA, rowB, colB + h, depth - 1);
    DivideAndConquer(rowA, colA + h, rowB + h, colB + h, depth - 1);

    // C21 = A21*B11 + A22*B21
    DivideAndConquer(rowA + h, colA, rowB, colB, depth - 1);
    DivideAndConquer(rowA + h, colA + h, rowB + h, colB, depth - 1);

    // C22 = A21*B12 + A22*B22
    DivideAndConquer(rowA + h, colA, rowB, colB + h, depth - 1);
    DivideAndConquer(rowA + h, colA + h, rowB + h, colB + h, depth - 1);
}

void Strassen(int rowA /*00*/, int colA /*01*/, int rowB /*10*/, int colB /*11*/, int depth)
{
    // Base 수식
    // // 정복
    // if (depth == 1)
    // {
    //     int m1 = (matrixA[rowA][colA] + matrixA[rowA+1][colA+1]) * (matrixB[rowB][colB] + matrixB[rowB+1][colB+1]);
    //     int m2 = (matrixA[rowA+1][colA] + matrixA[rowA+1][colA+1]) * matrixB[rowB][colB];
    //     int m3 = matrixA[rowA][colA] * (matrixB[rowB][colB+1] - matrixB[rowB+1][colB+1]);
    //     int m4 = matrixA[rowA+1][colA+1] * (matrixB[rowB+1][colB] - matrixB[rowB][colB]);
    //     int m5 = (matrixA[rowA][colA] + matrixA[rowA][colA+1]) * matrixB[rowB+1][colB+1];
    //     int m6 = (matrixA[rowA+1][colA] - matrixA[rowA][colA]) * (matrixB[rowB][colB] + matrixB[rowB][colB+1]);
    //     int m7 = (matrixA[rowA][colA+1] - matrixA[rowA+1][colA+1]) * (matrixB[rowB+1][colB] + matrixB[rowB+1][colB+1]);

    //     int c1 = m1 + m4 - m5 + m7;
    //     int c2 = m3 + m5;
    //     int c3 = m2 + m4;
    //     int c4 = m1 - m2 + m3 + m6;
    //     resultMatrix[rowA][colB] += c1;
    //     resultMatrix[rowA][colB+1] += c2;
    //     resultMatrix[rowA+1][colB] += c3;
    //     resultMatrix[rowA+1][colB+1] += c4;
    //     return;
    // }

    // // 분할
    // int h = 1 << (depth - 1);
    // // C11
    // Strassen(rowA, colA, rowB, colB, depth - 1);
    // Strassen(rowA, colA + h, rowB + h, colB, depth - 1);

    // // C12
    // Strassen(rowA, colA, rowB, colB + h, depth - 1);
    // Strassen(rowA, colA + h, rowB + h, colB + h, depth - 1);

    // // C21
    // Strassen(rowA + h, colA, rowB, colB, depth - 1);
    // Strassen(rowA + h, colA + h, rowB + h, colB, depth - 1);

    // // C22
    // Strassen(rowA + h, colA, rowB, colB + h, depth - 1);
    // Strassen(rowA + h, colA + h, rowB + h, colB + h, depth - 1);

    int size = 1 << depth;

    // 전역 A,B에서 해당 블록을 로컬 정방으로 복사
    vector<vector<int>> Ablk(size, vector<int>(size, 0));
    vector<vector<int>> Bblk(size, vector<int>(size, 0));
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            Ablk[i][j] = matrixA[rowA + i][colA + j];
            Bblk[i][j] = matrixB[rowB + i][colB + j];
        }
    }

    // 7곱 Strassen 수행
    vector<vector<int>> Cblk(size, vector<int>(size, 0));
    StrassenRec(Ablk, Bblk, Cblk);

    // 전역 C(rowA,colB)에 누적
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j)
        {
            resultMatrix[rowA + i][colB + j] += Cblk[i][j];
        }
    }
}

static vector<vector<int>> addsub(const vector<vector<int>>& X,
       const vector<vector<int>>& Y,
       int s)
{
    int n = (int)X.size();
    vector<vector<int>> Z(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            Z[i][j] = X[i][j] + s * Y[i][j];
        }
    }
    return Z;
}

// 로컬 정방행렬 Strassen: A(n×n) * B(n×n) -> C(n×n) (7곱 재귀, 리프 n==1만 스칼라)
static void StrassenRec(const vector<vector<int>>& A,
                        const vector<vector<int>>& B,
                        vector<vector<int>>& C)
{
    int n = (int)A.size();
    if (n == 1) 
    {
        C[0][0] += A[0][0] * B[0][0];
        return;
    }

    int h = n / 2;

    // 사분면 분해
    vector<vector<int>>
        A11(h, vector<int>(h, 0)), A12(h, vector<int>(h, 0)),
        A21(h, vector<int>(h, 0)), A22(h, vector<int>(h, 0)),
        B11(h, vector<int>(h, 0)), B12(h, vector<int>(h, 0)),
        B21(h, vector<int>(h, 0)), B22(h, vector<int>(h, 0));

    for (int i = 0; i < h; ++i) 
    {
        for (int j = 0; j < h; ++j) 
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + h];
            A21[i][j] = A[i + h][j];
            A22[i][j] = A[i + h][j + h];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + h];
            B21[i][j] = B[i + h][j];
            B22[i][j] = B[i + h][j + h];
        }
    }

    // S1..S10
    auto S1  = addsub(A11, A22, +1);
    auto S2  = addsub(B11, B22, +1);
    auto S3  = addsub(A21, A22, +1);
    auto S4  = addsub(B12, B22, -1);
    auto S5  = addsub(B21, B11, -1);
    auto S6  = addsub(A11, A12, +1);
    auto S7  = addsub(A21, A11, -1);
    auto S8  = addsub(B11, B12, +1);
    auto S9  = addsub(A12, A22, -1);
    auto S10 = addsub(B21, B22, +1);

    // M1..M7
    vector<vector<int>>
        M1(h, vector<int>(h, 0)), M2(h, vector<int>(h, 0)),
        M3(h, vector<int>(h, 0)), M4(h, vector<int>(h, 0)),
        M5(h, vector<int>(h, 0)), M6(h, vector<int>(h, 0)),
        M7(h, vector<int>(h, 0));

    StrassenRec(S1,  S2,  M1);   // (A11+A22)*(B11+B22)
    StrassenRec(S3,  B11, M2);   // (A21+A22)*B11
    StrassenRec(A11, S4,  M3);   // A11*(B12-B22)
    StrassenRec(A22, S5,  M4);   // A22*(B21-B11)
    StrassenRec(S6,  B22, M5);   // (A11+A12)*B22
    StrassenRec(S7,  S8,  M6);   // (A21-A11)*(B11+B12)
    StrassenRec(S9,  S10, M7);   // (A12-A22)*(B21+B22)

    // C 조합
    for (int i = 0; i < h; ++i) 
    {
        for (int j = 0; j < h; ++j) 
        {
            C[i][j]         += M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j]; // C11
            C[i][j + h]     += M3[i][j] + M5[i][j];                       // C12
            C[i + h][j]     += M2[i][j] + M4[i][j];                       // C21
            C[i + h][j + h] += M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j]; // C22
        }
    }
}