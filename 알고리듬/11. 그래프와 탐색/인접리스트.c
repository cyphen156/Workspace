#define MAX_SIZE 5

typedef struct Node
{
    int linkCount;
    Node* to[MAX_SIZE];
}Node;

int main(void)
{
    // 방향그래프
    Node A = { 0 }, B = { 0 }, C = { 0 }, D = { 0 }, E = { 0 };
    A.to[A.linkCount++] = &B;
    A.to[A.linkCount++] = &C;
    B.to[A.linkCount++] = &D;
    C.to[A.linkCount++] = &E;
    D.to[A.linkCount++] = &E;
    
    // 무방향 그래프로 전환하기
    B.to[A.linkCount++] = &A;
    C.to[A.linkCount++] = &A;
    D.to[A.linkCount++] = &B;
    E.to[A.linkCount++] = &C;
    E.to[A.linkCount++] = &D;
    return 0;
}