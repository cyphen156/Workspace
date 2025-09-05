// 이진 최대공약수 판정법
// 시간복잡도 O(logN)
int binary_gcd(int a, int b)
{
    if (a == 0) 
    {
        return b;
    }
    if (b == 0) 
    {
        return a;
    }

    // 공통으로 나눌 수 있는 2의 최대 지수
    int shift = 0;

    // a와 b가 둘 다 짝수일 때만 2로 나눌 수 있음
    while (((a | b) & 1) == 0)
    {
        a >>= 1;
        b >>= 1;
        shift++;
    }

    // a는 홀수로 만든다
    while ((a & 1) == 0)
    {
        a >>= 1;
    }

    while (b != 0) 
    {
        // b를 홀수로 만든다
        while ((b & 1) == 0)
        {
            b >>= 1;
        }

        // a > b면 swap
        if (a > b) 
        {
            int temp = a;
            a = b;
            b = temp;
        }

        b = b - a;
    }

    return a << shift;
}