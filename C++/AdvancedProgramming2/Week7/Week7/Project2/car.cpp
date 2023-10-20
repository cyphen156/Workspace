#include "car.h"
#include <iostream>

Car::Car() : Car("Benz", "white") {};
Car::Car(string modelname) : Car(modelname, "white") {};
Car::Car(string modelname, string carcolor) {
	model = modelname;
	color = carcolor;
};

void Car::printInfo() {
	cout << "model = " << model << ", color = " << color << endl;
}