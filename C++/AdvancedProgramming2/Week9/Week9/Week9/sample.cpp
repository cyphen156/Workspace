#pragma once
#include <iostream>

using namespace std;

class Sample {
	int a;

public:
	Sample() {
		a = 100;
		cout << a << " ";
	}

	Sample(int n) {
		a = n;
		cout << a << " ";
	}

	Sample(int n1, int n2) {
		a = n1 * n2;
		cout << a << " ";
	}

	int get() {
		return a;
	}
};