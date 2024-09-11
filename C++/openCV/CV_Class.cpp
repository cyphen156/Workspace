#include <opencv2/core.hpp>
#include <iostream>

using namespace std;

int main()
{
	//// Point 클래스 기본 생성
	cv::Point_<int> arr{ 0, 5 };
	cv::Point2i arr2{ 3, 5 };
	cout << "arr : " << arr << "\n"
		<< "arr2 : " << arr2 << "\n";
	//cv::Point arr3{ 5, 5 };
	//cv::Point2d dP{ 4.5, 9.4 };
	//cout << typeid(arr).name() << "\n";
	//cout << typeid(arr2).name() << "\n";
	//cout << typeid(arr3).name() << "\n";
	//cout << typeid(dP).name() << "\n";
	//cout << dP << "\n";


	//cout << arr.dot(arr2) << "\n";
	//cout << arr.cross(arr2) << "\n";

	//cv::Rect_<int> r{ 0, 0, 10, 10};
	//cout << arr.inside(r) << "\n";

	//cv::Point2d dcpy(arr);
	//cv::Point& arr4 = arr3;

	//cout << dcpy << "\n";
	//cout << arr4 << "\n";

	// Size 클래스
	cv::Size sz1{ 5, 10 };
	cout << "sz1 : " << sz1 << "\n";

	// Rect 클래스
	cv::Rect rc1(0, 0, 5, 5);
	cv::Rect rc2(10, 10, 20, 30);

	cout << "rc1 : " << rc1 << "\n"
		<< "rc2 : " << rc2 << "\n";

	cv::Rect rc3 = rc1 + arr;
	cv::Rect rc2sz1 = rc2 + sz1;

	cout << "rc1 + arr : " << rc3 << "\n"
		<< "rc2 + sz1 : " << rc2sz1 << "\n";

	cv::Rect re1 = rc3 | rc2sz1;
	cv::Rect re2 = rc3 & rc2sz1;
	cout << "rc1 + arr | rc2 + sz1 : " << re1 << "\n"
		<< "rc1 + arr & rc2 + sz1 : " << re2 << "\n";
	return 0;
}