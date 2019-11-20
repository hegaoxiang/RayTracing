#pragma once
#include<Windows.h>

//#define DllExport _declspec(dllexport)
#define DllExport  
// Editor Framework Functions
 int EditorMain(int* instancePtrAddress, int* hPrevInstancePtrAddress, int* hWndPtrAddress, int nCmdShow, int screenWidth, int screenHeight);
 //void WndProc(int* hWndPtrAddress, int msg, int wParam, int lParam);
 void RenderFrame();
 LRESULT CALLBACK   WndProc(HWND, UINT, WPARAM, LPARAM);
