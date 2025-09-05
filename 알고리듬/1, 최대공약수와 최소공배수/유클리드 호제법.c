// 최대공약수
// 시간복잡도 O(logN)
int GCD(int A, int B) {
    int C;
    while(B != 0) {
        C = A % B;
        A = B;
        B = C;
    }
    return A;
}

// 최소공배수
int LCM(int A, int B, int GCD) {
    int result;
    result = A * B / GCD;
    return result;
}