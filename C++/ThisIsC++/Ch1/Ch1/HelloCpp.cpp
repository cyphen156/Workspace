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
			max = first;
			if (max < second)
				if (second < third)
					max = third;
				else
					max = second;
			else if (max < third)
				max = third;
			printf("%d", max * 100);
		}
	}
    return 0;
}