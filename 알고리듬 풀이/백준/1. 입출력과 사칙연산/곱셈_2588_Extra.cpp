#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    cout << setw(6) << setfill(' ') << A * (B % 10) << '\n'
        << setw(6) << setfill(' ') << A * ((B % 100) / 10) * 10 << '\n'
        << setw(6) << setfill(' ')<< A * (B / 100) * 100 << '\n'
        << setw(6) << setfill('0') << A * B << endl;
    return 0;
}