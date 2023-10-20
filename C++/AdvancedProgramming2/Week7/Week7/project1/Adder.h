#pragma once
#include <iostream>

using namespace std;

class Adder {
	int oper1, oper2;

public:
	Adder(int a, int b);
	int process();
};