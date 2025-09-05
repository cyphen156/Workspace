// 일반적인 방법
// 시간복잡도 O(N)
int findDivisor(int A){
    int i = 1;
    while(i <= A) {
        if(A % i == 0) {
            printf("%d ", i);
        }
        i++;
    }
}

// 일반적인 방법의 1/2
// 시간복잡도 O(N/2)
int findDivisor(int A){
    int i = 1;
    while(i <= A/2) {
        if(A % i == 0) {
            printf("%d ", i);
        }
        i++;
    }
}

// input의 약수를 찾는 방법 #3 제곱근까지만 확인하기
// 시간복잡도 O(sqrt(N))

int findDivisor_Root(int A) {
    int i;
    for (i = 1; i <= sqrt(A); i++) 
    {
        if (A % i == 0) 
        {
            printf("%d ", i);
            if (i != A / i) // 약수 쌍 출력
            {
                printf("%d ", A / i);
            }
        }
    }
    return 0;
}