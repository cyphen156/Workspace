#include <iostream>

using namespace std;

int add(int a, int b);
int multiply(int a, int b);
void divide(int a, int b);

int main(){
    char ch;
    int A, B;
    cin >> ch;
    cin >> A, B;
    if (ch == '+')
    {
        cout << add(A, B) << endl;
    }
    else if(ch == '-')
    {
        B = ~B;
        B++;
        cout << add(A, B) << endl;
    }
    else if (ch == '*')
    {
        cout << multiply(A, B) << endl;
    }
    else 
    {
        divide(A, B);
    }

    return 0;
}

int add(int a, int b) {
    int carry;
    while (b & ~0)
    {
        carry = a & b;
        a = a ^ b;
        carry <<= 1;
        b = carry;
    }
    return a;
}

int multiply(int a, int b) {
    while(b != 0)
    {
        a << 1;
        b >> 1;
    }
}

void divide(int a, int b) {

    ;
}