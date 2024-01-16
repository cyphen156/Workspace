#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (y > 0) 
    {
        if (x > 0)
            cout << 1;
        else if (x < 0)
            cout << 2;
    }
    else if (y < 0) 
    {
        if (x > 0)
            cout << 4;
        else if (x < 0)
            cout << 3;
    }
    return 0;
}