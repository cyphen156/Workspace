#include <iostream>
using namespace std;

class Car
{
public:
	string model;
	string color;
	int fuel;
	int cSpeed;
	int maxSpeed;

	void addSpeed()
	{
		cSpeed += 50;
		fuelDown();
	}
	void speedDown()
	{
		cSpeed -= 50;
		fuelDown();
	}
	void addFuel() 
	{
		fuel += 10;
	}
	void fuelDown()
	{
		fuel -= 2;
	}
	void displaySpeed()
	{
		cout << "현재 속도 = " << cSpeed << "km/h(연료량: " << fuel << "리터)" << endl;
	}
};

int main()
{
	Car car;
	car.model = "그랜저";
	car.color = "white";
	car.fuel = 10;
	car.cSpeed = 0;
	car.maxSpeed = 250;

	int menu;
	cout << car.model + " 시승 준비 완료!" << endl;
	while (1)
	{
		cout << "메뉴 : 1.가속 2.감속 3.연료충전 4.종료" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			if (car.cSpeed <= (car.maxSpeed - 50))
				car.addSpeed();
			else
				car.fuelDown();
			car.displaySpeed();
			break;
		case 2:
			if (car.cSpeed >= 50)
				car.speedDown();
			else
				car.fuelDown();
			car.displaySpeed();
			break;
		case 3:	
			car.addFuel();
			break;
		case 4:
			if (car.cSpeed == 0 || car.fuel == 0)
				return 0;
		}
	}
	return 0;
}