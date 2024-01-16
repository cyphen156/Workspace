#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (x == 0 || y == 0)
        return -1;
    cout << (y > 0 ? (x > 0 ? 1 : 2) : (x > 0 ? 4 : 3));
    return 0;
}