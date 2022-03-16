#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <cmath>

static TCHAR szWindowClass[] = _T("DesktopApp");
static TCHAR szTitle[] = _T("y = sin(x)");
HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow){
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    if (!RegisterClassEx(&wcex)){
        MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("y = sin(x)"), NULL);
        return 1;
    }
    hInst = hInstance;
    HWND hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1000, 500, NULL, NULL, hInstance, NULL);
    if (!hWnd){
        MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("y = sin(x)"), NULL);
        return 1;
    }
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
    PAINTSTRUCT ps;
    HDC hdc;
    HPEN axis = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    HPEN graph = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    switch (message){
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        SelectObject(hdc, axis);
        TextOut(hdc, 5, 5, TEXT("y = sin(x)"), strlen("y = sin(x)"));
        MoveToEx(hdc, 0, 25, NULL);
        LineTo(hdc, 1000, 25);
        TextOut(hdc, 925, 255, TEXT("X"), 1);
        MoveToEx(hdc, 5, 250, NULL);
        LineTo(hdc, 950, 250);
        MoveToEx(hdc, 950, 250, NULL);
        LineTo(hdc, 935, 253);
        MoveToEx(hdc, 950, 250, NULL);
        LineTo(hdc, 935, 247);
        TextOut(hdc, 435, 30, TEXT("Y"), 1);
        MoveToEx(hdc, 450, 30, NULL);
        LineTo(hdc, 450, 400);
        MoveToEx(hdc, 450, 30, NULL);
        LineTo(hdc, 447, 45);
        MoveToEx(hdc, 450, 30, NULL);
        LineTo(hdc, 453, 45);
        SelectObject(hdc, graph);
        for (float x = -10.0f; x <= 10.0f; x += 0.001f)
        {
            MoveToEx(hdc, 80 * x + 200, 80 * sin(x) + 250, NULL);
            LineTo(hdc, 80 * x + 200, 80 * sin(x) + 250);
        }
        ReleaseDC(hWnd, hdc);
        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}