//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Car {
//	string model;
//	double speed = 0.f;
//
//public:
//	
//	void setModel(string model){
//		this->model = model;
//	}
//	
//	void setSpeed(int speed) {
//		this->speed = speed;
//	}
//
//	string getModel() {
//		return this->model;
//	}
//
//	double getSpeed() {
//		return this->speed;
//	}
//};
//
//class SportCar : public Car {
//	bool turbo = false;
//
//public: 
//	void setTurbo() {
//		this->turbo = !turbo;
//	}
//
//	bool isTurbo() {
//		return turbo;
//	}
//};
//int main()
//{
//	SportCar sCar;
//
//	sCar.setModel("lamborgini");
//	sCar.setSpeed(150.f);
//	sCar.setTurbo();
//
//	cout << "model : " << sCar.getModel() 
//		 << "speed : " << sCar.getSpeed() 
//		 << "turboMode : " << sCar.isTurbo() << endl;
//	return 0;
//}