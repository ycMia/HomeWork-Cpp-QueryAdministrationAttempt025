// OldFriendWindowsForm.cpp : Define entry points for the application。
//

#include "framework.h"
#include "OldFriendWindowsForm.h"

#include<shellapi.h>
#include<fstream>
#include <cassert>

#define MAX_LOADSTRING 100

// global variables:
HINSTANCE hInst;                                // Current instance 
WCHAR szTitle[MAX_LOADSTRING];                  // Title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // Main window class name

// This code module contains a forward declaration of the function:
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

    // TODO: CODE here

    // initialize the global string variables
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_OLDFRIENDWINDOWSFORM, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // exec initialize:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OLDFRIENDWINDOWSFORM));

    MSG msg;

    // main message loop:
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
//  Function: MyRegisterClass()
//
//  target: Register a windows form class
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OLDFRIENDWINDOWSFORM));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OLDFRIENDWINDOWSFORM);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   function: InitInstance(HINSTANCE, int)
//
//   target: Save the instance of the handle, and create the main window form.
//
//   Comment:
//
//      In this function, we save instance handles in global variables
//      and create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Save the handle that belongs to the current entity into the global variable.

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
//  Function: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Target: address the messages form the main window
//
//  WM_COMMAND  - Process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - Send the message of DESTROY and return back (exit)
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analyze which selection the user has made.:
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
            // Painting logics. Pleasse coding here using hdc...

            // I'm partly using the method in https://stackoverflow.com/questions/30934184/bitmap-not-being-painted-in-win32-c
            // And the official mannuals are here : 
            // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-loadbitmapw
            // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-loadimagew
            // However they are separated, so it is really hard to get its source / examples (ANY of them !). I'm trying my best.
            
            HANDLE image = LoadImage(hInst, L".\\resources\\Meow.bmp",
                IMAGE_BITMAP, 0,0, LR_LOADFROMFILE);
            //HBITMAP bmp = LoadBitmap(hInst, L".\\Meow.bmp");
            //assert(bmp != NULL);
            assert(image != NULL);
            HDC memDC = CreateCompatibleDC(hdc);
            SelectObject(memDC, image);
            BitBlt(hdc, 0, 0, 2000, 1800, memDC, 0, 0, SRCCOPY);
            DeleteDC(memDC);
            DeleteObject(image);

            // If we want to load images in various extension names, see this page
            //https://stackoverflow.com/questions/4567875/how-would-i-load-a-png-image-using-win32-gdi-no-gdi-if-possible
            // Which redirects to here
            // https://learn.microsoft.com/en-us/archive/msdn-magazine/2008/april/windows-with-c-windows-imaging-component-basics
            
            

            

            /*
            // May consider using this one.
            // https://stackoverflow.com/questions/7620450/how-to-paint-to-a-bitmap
            
            HDC memDC = CreateCompatibleDC(hdc);
            RECT rect;
            GetWindowRect(hWnd, &rect);
            HBITMAP memBitmap = CreateCompatibleBitmap(hdc, rect.right - rect.left, rect.bottom - rect.top);

            //clean the garbage
            DeleteObject(memDC);
            DeleteObject(memBitmap);
            */

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

// The program which ready to tackle the selection of 'About'.
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
        else if (LOWORD(wParam) == IDC_BUTTON1)
        {
            //The reaction of 'Wonder More?' button, just for fun
            ShellExecute(0, 0, L"https://github.com/ycMia", 0, 0, SW_SHOW);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
