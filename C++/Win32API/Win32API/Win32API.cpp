// Win32API.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API.h"
#include "iostream"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,  // main(str argc, srargv)
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32API, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32API));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32API));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32API);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HFONT hFont;
    static HPEN hPen;
    static HBRUSH hBrush, hBrush2;

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case ID_32771:
            {
                HWND hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_32771), hWnd, About);
                if (hDlg != NULL)
                {
                    ShowWindow(hDlg, SW_SHOW);
                }
                else
                {
                    MessageBox(hWnd, L"CreateDialog 실패", L"오류", MB_OK | MB_ICONERROR);
                }
            }
            break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            WCHAR str[128] = L"Hello World!";
            TextOut(hdc, 10, 10, str, 20);
            SetTextColor(hdc, RGB(255, 0, 0));
            SetBkColor(hdc, RGB(0, 0, 255));
            WCHAR str2[128] = L"안녀어어어어엉";
            TextOut(hdc, 25, 200, str2, 20);
            RECT RT;
            GetClientRect(hWnd, &RT);
            DrawText(hdc, L"텍스트그리기", -1, &RT, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

            // 선그리기
            LineTo(hdc, 100, 100); // 0, 0 -> 100, 100
            //Sleep(1000);
            LineTo(hdc, 75, 240); // 100, 100 -> 75, 240
            //Sleep(1000);
            MoveToEx(hdc, 25, 300, NULL); // 75, 240 -> 25, 300
            //Sleep(1000);
            LineTo(hdc, 300, 25);
            // 사각형 그리기
            Rectangle(hdc, 50, 50, 150, 150);

            // 타원그리기
            Ellipse(hdc, 200, 200, 300, 300);
            

            //폰트 바꿔서 그리기

            // 기존 폰트가 사라지는것을 방지하기 위한 변수 할당
            // SelectObject는 새로운 객체를 클라이언트에 할당하고
            // 반환 값으로 이전 객체를 반환 하기 때문이다.            
            HFONT holdFont = (HFONT)SelectObject(hdc, hFont);


            SetTextColor(hdc, RGB(0, 255, 0));
            WCHAR changeFont[128] = L"폰트가 바뀌어서 출력되요";
            TextOut(hdc, 150, 150, changeFont, 15);
            
            SelectObject(hdc, holdFont);

            // 기본 폰트로 복귀
            SetTextColor(hdc, RGB(0, 0, 255));
            SetBkColor(hdc, RGB(128, 0, 0));
            WCHAR defalutFont[128] = L"기본 폰트로 돌아왔어요";
            TextOut(hdc, 150, 175, changeFont, 20);

            // 펜과 브러시 실습하기
            HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
            HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

            // 큰 사각형 생성
            Rectangle(hdc, 400, 400, 500, 500);
            
            //HBrush2사용
            SelectObject(hdc, hOldPen);
            SelectObject(hdc, hBrush2);
            Ellipse(hdc, 400, 400, 450, 450);


            // 스톡 실습
            HPEN hPen = (HPEN)GetStockObject(DC_PEN);         // 스톡 펜 사용
            HBRUSH hBrush = (HBRUSH)GetStockObject(DC_BRUSH); // 스톡 브러시 사용

            // DC 펜과 브러시의 색상 설정
            SetDCPenColor(hdc, RGB(0, 0, 255));  // 파란색 펜
            SetDCBrushColor(hdc, RGB(0, 255, 0)); // 녹색 브러시

            // 사각형 그리기
            Rectangle(hdc, 100, 100, 200, 200);

            // 레스터 그래픽 실습
            SetROP2(hdc, R2_XORPEN);

            // XOR 연산용 색상 설정
            HPEN xorPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));  // 빨간색 펜
            HPEN oldPen = (HPEN)SelectObject(hdc, xorPen);

            // 선 그리기
            MoveToEx(hdc, 50, 50, NULL);
            LineTo(hdc, 200, 200);

            // 펜 복구
            SelectObject(hdc, oldPen);
            DeleteObject(xorPen);


            // 벡터 그래픽 실습
            HRGN hRgn = CreateEllipticRgn(300, 300, 450, 450); // 타원형 리전 생성
            SelectClipRgn(hdc, hRgn);  // 리전 클리핑 설정

            // 벡터 그래픽용 색상 설정
            HPEN vectorPen = CreatePen(PS_SOLID, 2, RGB(128, 0, 255));  // 보라색 계열 펜
            HBRUSH vectorBrush = CreateSolidBrush(RGB(255, 128, 0));    // 주황색 계열 브러시

            HPEN oldVectorPen = (HPEN)SelectObject(hdc, vectorPen);
            HBRUSH oldVectorBrush = (HBRUSH)SelectObject(hdc, vectorBrush);

            // 타원 그리기
            Ellipse(hdc, 300, 300, 450, 450);  // 리전 내에서만 그리기

            // 원래의 펜과 브러시 복구
            SelectObject(hdc, oldVectorPen);
            SelectObject(hdc, oldVectorBrush);
            DeleteObject(hRgn);
            DeleteObject(vectorPen);
            DeleteObject(vectorBrush);


            EndPaint(hWnd, &ps);
        }
        break;
    case WM_CREATE:
        {
            hFont = CreateFont(
                20,         // 세로 길이
                10,         // 가로 길이 (0으로 두면 자동 조정)
                0,          // 문자열 기울기 (단위: 0.1도)
                0,          // 문자 회전 각도
                FW_NORMAL,  // 두께 (FW_NORMAL, FW_BOLD 등)
                FALSE,      // 이탤릭 여부
                FALSE,      // 밑줄 여부
                FALSE,      // 취소선 여부
                DEFAULT_CHARSET, // 문자셋 (한글은 HANGUL_CHARSET)
                OUT_DEFAULT_PRECIS, // 출력 정밀도
                CLIP_DEFAULT_PRECIS, // 클리핑 정밀도
                DEFAULT_QUALITY,     // 출력 품질
                DEFAULT_PITCH | FF_SWISS, // 글꼴 스타일
                TEXT("Arial"));      // 글꼴 이름

            // 펜 설정
            hPen = CreatePen(PS_DASH, 2, RGB(127, 127, 127));
            
            // 브러쉬 설정
            hBrush = CreateSolidBrush(RGB(255, 0, 255));
            hBrush2 = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 255, 255));
            break;
        }
    case WM_DESTROY:
        DeleteObject(hFont);
        DeleteObject(hPen);
        DeleteObject(hBrush);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
