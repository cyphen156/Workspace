//#include <iostream>
//
//using namespace std;
//
//int main() {
//	// 최대, 최소, 합구하기
//
//	//// len 길이구하기 ==>  문자열일 경우에는 '\0'체크하면 되지만 int 형변수일때는 어떻게 구할까...?
//	//int arr[] = { 1, 6, 9, 7, 3, 2, 0, 4, 8, 5 };
//	//int sum = 0, i = 0;
//	//int max = -99999999, min = 99999999;
//	//int len = sizeof(arr) / sizeof(int);
//	//cout << len;
//	//while (1) {
//	//	if (i == len)
//	//		break;
//	//	sum += arr[i];
//	//	if (arr[i] > max)
//	//		max = arr[i];
//	//	if (arr[i] < min)
//	//		min = arr[i];
//	//	i++;
//	//}
//	//cout << max << '\t' << min << '\t' << sum << endl;
//	
//
//
//
//
//	// 달력 일수 출력하기
//
//	/*int arr[12][31] = { 0 };
//
//	for (int i = 1; i < 13; i++) {
//		for (int j = 1; j < 32; j++) {
//			if (i < 7 && i/1 != 0){
//				
//			}
//		}
//	}*/
//
//	//int days[] = { 31, 29, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31 };
//
//	//for (int i = 0; i < 12; i++) {
//	//	cout << i+1 << "월은" << days[i] << "일까지 있습니다." << '\n';
//	//}
//	//cout << endl;
//
//
//
//
//	// 난수 생성하기
//
//	int arr[10], max = 0xfffffffff, min = 0x10000000;
//
//	// srand() == 시드 값을 생성하여 랜덤 난수 생성
//	// ==> 일반적으로 계속 변화하는 시스템 시간을 가져와서 사용
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < 10; i++) {
//		arr[i] = rand();
//		if (arr[i] > max)
//			max = arr[i];
//		if (arr[i] < min)
//			min = arr[i];	
//	}
//	return 0;
//}