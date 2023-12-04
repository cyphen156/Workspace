/**
* STL ;
*
* container
* <Vector>, <queue>, <Map>, <List>, <Set>
* // 가변 배열
* ==> 좌표 일치시 에러 발생
*
* 반복자
* <Iterator>
*
* Algorithms
* <tamlplate function>
* 
* auto keyword
* ==> 자동 형식지정자
* 
* use lambda
*/


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
#include <typeinfo>

using namespace std;

//class Vector
//{
//	vector<int> x;
//	vector<int> y;
//
//public:
//	Vector(int x, int y) {
//		this->x.at = x;
//		y = y;
//	}
//};


int fSum(int x, int y) {
	return x + y;
};
//int main()
//{
//	cout << fSum(3, 7) << endl;
//	auto lamb = [](int x, int y) {
//		cout << x + y << endl;
//	};
//
//	lamb(3, 9);
//
//	// return 값이 있는 람다식
//	// 캡쳐리스트 = []
//	// 람다식 외부의 지역변수를 사용할 때
//	// 참조만 하는것이 아닌 값을 변경할 때는 ptr 또는 참조변수 &연산자 사용
//	double pi = 3.14f;
//	auto calc = [pi](int r)->double {
//		return pi * r * r;
//		};
//	auto calc2 = [pi](int r)->double {
//		return pi;
//		};
//	cout << "면적은 " << calc(7) << '\n' << calc2(9);
//	vector<int> v;
//	//Vector vector2D(1, 5);
//	for (int i = 0; i < 10; ++i) {
//		v.push_back(i);
//	}
//	vector<int>::iterator iter;
//
//	cout << "V * 2 = ? \n";
//	for (iter = v.begin(); iter != v.end(); ++iter) {
//		int n = *iter;
//		*iter = 2 * n;
//		// == *iter = 2 * (*iter);
//		cout << *iter << '\n';
//	}
//
//	reverse(v.begin(), v.end());
//	cout << "reverse\n";
//
//	for (iter = v.begin(); iter != v.end(); ++iter) {
//		cout << *iter << '\n';
//	}
//
//	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	//vector<string> strV;
	//string name;
	//
	//for (int i = 0; i < 5; ++i)
	//{
	//	cout << "입력하시오.";
	//	cin >> name;
	//	strV.push_back(name);
	//}
	//name = strV[0];
	//for (int i = 0; i < size(strV); ++i)
	//{
	//	if (name < strV[i]) {
	//		name = strV[i];
	//	}
	//	cout << strV[i] << '\n';
	//}
	//cout  << name << endl;

	//map<string, string> dic;
	//dic.insert(make_pair("key", "value"));
	//// == dic["key"] = "value";
	//dic["key2"] = "hello";
	//dic["key3"] = "world";
	/*auto dic22 = make_pair("", "");

	cout << typeid(lamb).name();*/
	/*while (1)
	{
		string str;
		cin >> str;
		if (str._Equal("exit")) {
			break;
		}
		if (dic.find(str) == dic.end())
		{
			cout << "그런 단어 없다.\n";
		}
		else {
			cout << dic[str] << '\n';
		}
		cout << endl;
	}*/
	
	// for_each(start; end; print)

//	for_each(v.begin(), v.end(), [](int i) {
//		cout << i << '\n';
//	});
//	return 0;
//}