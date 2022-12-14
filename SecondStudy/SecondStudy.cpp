// SecondStudy.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "SecondStudy.h"

#define MAX_LOADSTRING 100

int WinposX = GetSystemMetrics(SM_CXSCREEN) / 2 - WINSIZEX / 2;
int WinposY = GetSystemMetrics(SM_CYSCREEN) / 2 - WINSIZEY / 2;

//int ResoulutionX = GetSystemMetrics(SM_CXSCREEN);
//int ResoulutionY = GetSystemMetrics(SM_CYSCREEN);
//
//int Winposx = 

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SECONDSTUDY, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SECONDSTUDY));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SECONDSTUDY));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SECONDSTUDY);
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


            /*
            wstring wstr = L"게임 프로그래밍 2학기 시작!";
            RECT rt = {};
            rt.left = 300;
            rt.top = 300;
            rt.right = 400;
            rt.bottom = 400;
            Rectangle(hdc, 10, 10, 110, 110);
            TextOut(hdc, 200, 200, wstr.c_str(), wstr.length()); // 텍스트 출력
            DrawText(hdc,L"hello world!!",13,&rt,DT_SINGLELINE| DT_RIGHT); // 임의의 사각형 안에 텍스트 출력
            MoveToEx(hdc, 0, 0, nullptr);// 선 그리기 시작
            LineTo(hdc, 800, 600); // 선 그리기 끝
            Ellipse(hdc, 50, 50, 150, 150);

            */


            //1280x720 16x9
            /*RECT rt = {};
            AdjustWindowRect(&rt,WS_OVERLAPPEDWINDOW,true);
            MoveWindow(hWnd, Winposx, Winposy,
                rt.right - rt.left,
                rt.bottom - rt.top,
                true);
            int xWid = 1280 / 16;
            int xCurWid = 0;
            int yWid = 720 / 9;
            int yCurWid = 0;
            for (int i = 0; i < 16; i++)
            {
                MoveToEx(hdc, xCurWid, 0, nullptr);
                LineTo(hdc, xCurWid, 720);
                xCurWid += xWid;
            }
            for (int i = 0; i < 9; i++)
            {
                MoveToEx(hdc, 0, yCurWid, nullptr);
                LineTo(hdc, 1280, yCurWid);
                yCurWid += yWid;
            }*/

            int xPos = 100;
            int yPos = 100;
            int gap = 120;

            for (int i = 0; i < 25; ++i)
            {
                /*if (i % 5 == 0)
                {
                    xPos -= gap * 4;
                    yPos += gap;
                }
                if (i % 2 == 1)
                {
                    Rectangle(hdc, xPos, yPos, 50, 50);
                }
                else
                {
                    Ellipse(hdc, xPos, yPos, 50, 50);
                }
                xPos += gap;*/

                int left = (i%5*70)+100;
                int top = (i/5*70)+100;
                if (i / 5 % 2 == 0)
                {
                    Rectangle(hdc, left,top,left+50,top+50);
                }
                else
                {
                    Ellipse(hdc, left, top, left + 50, top + 50);
                }
            }


            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
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
