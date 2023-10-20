#pragma once
#include <string>

using namespace std;

class Car {
	string model, color;

public:
	Car();
	Car(string modelname);
	Car(string modelname, string carcolor);

	void printInfo();
};