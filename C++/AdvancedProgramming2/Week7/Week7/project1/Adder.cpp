#include "Adder.h"

Adder::Adder(int a, int b) {
	oper1 = a;
	oper2 = b;
}

int Adder::process() {
	return oper1 + oper2;
}