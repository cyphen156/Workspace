#include<iostream>

int main() {
    int pointX = 5; // 이 점의 x 좌표
    int pointY = 5; // 이 점의 y 좌표

    int size = 10; // 평면의 크기

    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            if (i == pointY && j == pointX) {
                std::cout << "*"; // 점을 그립니다.
            }
            else if (i == 0 || j == 0) {
                std::cout << "#"; // 축을 그립니다.
            }
            else {
                std::cout << ".\t"; // 빈 공간을 그립니다.
            }
        }
        std::cout << "\n";
    }

    return 0;
}
