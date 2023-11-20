#include <iostream>

using namespace std;

class Calculator {

};

class Adder : public Calculator {

};

class Subtractor : public Calculator {

};

int main() {
	Adder adder;
	Subtractor subtractor;
	return 0;
}