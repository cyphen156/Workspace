//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main() {
//	// 이차원 배열
//	// 행은 초기화시 생략 가능하지만 열은 생략해선 안됨
//
//	int score[][3] = { 
//			{65, 75, 85},
//			{0, 10, 5}, 
//			{3, 5, 9}, 
//			{100, 55, 72} 
//	};
//	int max = 0, max_idx = 0;
//	for (int i = 0; i < size(score); i++) {
//		int sum = 0, avg = 0;
//		for (int j = 0; j < 3; j++) {
//			sum += score[i][j];
//		}
//		avg = sum / 3;
//		cout << "sum = " << sum << '\t' << "avg = " << avg << endl;
//		if (max > sum)
//			max = sum;
//			max_idx = i;
//	}
//	cout << "총점이 가장 높은 학생은 " << max_idx + 1 << "번 학생입니다." << endl;
//	cout << "성적은 ";
//	for (int i = 0; i < 3; i++) {
//		cout << score[max_idx][i] << ", ";
//	}
//	cout << "\b\b" << "입니다." << endl;
//	return 0;
//}