// openCV.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    cout << "Hello CV2" << CV_VERSION << endl;
    string path = "Resources/test.png";
    Mat img = imread(path);

    // 이미지 불러오기 실패 처리
    if (img.empty())
    {
        cerr << "img read failed" << endl;
        return -1;
    }

    // (입력데이터, 출력데이터, 사이즈기반 크기조정, X비율, Y비율) 원본사이즈 2060 X 2060;;;;
    resize(img, img, Size(), 0.1, 0.1); 

    // 이미지 크기 row, col
    int imsize[] = { img.rows, img.cols };
    cout << "행 크기 : " << imsize[0] << "\t" << "열 크기 : " << imsize[1] << endl;

    // 원본 크기가 너무 크기 때문에 출력문도 너무 많다. 그러니까 보기 쉽게 전체를 10등분 해서 보여준다.
    // 격자의 간격 206px
    int gridSize = imsize[0] / 10;

    // 수평선 그리기
    for (int i = 0; i <= imsize[0]; i += gridSize)
    {
        line(img, Point(0, i), Point(imsize[1], i), Scalar(0, 0, 0), 1); // 검은선, 두께 1
    }

    // 수직선 그리기
    for (int j = 0; j <= imsize[1]; j += gridSize)
    {
        line(img, Point(j, 0), Point(j, imsize[0]), Scalar(0, 0, 0), 1); // 검은 선, 두께 1
    }

    for (int i = gridSize / 2; i < imsize[0]; i += gridSize)
    {
        for (int j = gridSize / 2; j < imsize[1]; j += gridSize)
        {
            // 이미지가 컬러일 경우 BGR 픽셀 값을 추출
            Vec3b pixel = img.at<Vec3b>(i, j);

            // 텍스트로 표시할 내용 "(B, G, R)" 형식으로 변환
            // 흰색 공간은 \t로 무시하기
            if ((int)pixel[0] == 255 && (int)pixel[1] == 255 && (int)pixel[2] == 255)
            {
                cout << "\t";
            }
            else
            {
                string pixelText = to_string((int)pixel[0]) + ","
                    + to_string((int)pixel[1]) + ","
                    + to_string((int)pixel[2]);         
                cout << pixelText << "\t";
            }
        }
        cout << endl;
    }
    cv::imshow("img", img);

    namedWindow("namedImg", WINDOW_NORMAL);

    imshow("namedImg", img);

    waitKey(0);
    vector<int> params;
    params.push_back(IMWRITE_JPEG_QUALITY);
    params.push_back(95);
    imwrite("sample.jpeg", img, params);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
