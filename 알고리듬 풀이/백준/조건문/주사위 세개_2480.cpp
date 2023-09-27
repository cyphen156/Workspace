#include <iostream>

using namespace std;

int main()
{
    int A, B, C, max;

    cin >> A >> B >> C;
	if (A == B && A == C) {
		cout << A * 1000 + 10000;
	}
	else {
		if (A == B || A == C)
			cout << A * 100 + 1000;
		else if (B == C)
			cout << B * 100 + 1000;
		else {
			max = A;
			if (max < B)
				if (B < C)
					max = C;
				else
					max = B;
			else if (max < C)
				max = C;
			cout << max * 100;
		}
	}
    return 0;
}