#include <iostream>
#include <string>

using namespace std;

class Car {
	string model;
	int speed;

public:
	//생성자
	Car();
	Car(string model);
	Car(int speed);
	Car(string model, int speed);
	Car operator+ (Car op2);
	Car operator- (Car op2);
	Car operator+= (Car op2);
	Car operator-= (Car op2);
	void show();
};

Car::Car() :Car("소나타", 50) {};
Car::Car(string model) :Car(model, 50) {};
Car::Car(int speed):Car("소나타", speed) {};
Car::Car(string model, int speed) {
	this->model = model;
	this->speed = speed;
}

Car Car::operator+ (Car op2) {
	Car temp;
	temp.speed = this->speed + op2.speed;
	return temp;
}

Car Car::operator- (Car op2) {
	Car temp;
	temp.speed = this->speed - op2.speed;
	return temp;
}

Car Car::operator+= (Car op2) {
	this->speed += op2.speed;
	return *this;
}

Car Car::operator-= (Car op2) {
	this->speed -= op2.speed;
	return *this;
}

void Car::show() {
	cout << this->model << " speed = " << this->speed << endl;
}
int main() {

	/*Car urcar(1);
	urcar.show();
	Car mycar("람보르기니");
	mycar.show();

	cout << "\n\n\n\n" << endl;
	*/
	Car myCar("그랜저", 100);
	myCar.show();
	Car yourCar("아반떼", 70);
	yourCar.show();

	cout << "myCar + yourCar 결과 : ";
	(myCar + yourCar).show();

	cout << "myCar - yourCar 결과 : ";
	(myCar - yourCar).show();

	cout << "myCar += yourCar 결과 : ";
	(myCar += yourCar).show();

	cout << "myCar -= yourCar 결과 : ";
	(myCar -= yourCar).show();
	return 0;
}