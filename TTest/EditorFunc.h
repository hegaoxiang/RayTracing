#pragma once

#define DllExport _declspec(dllexport)

// Editor Framework Functions
extern "C" DllExport int EditorMain(int* instancePtrAddress, int* hPrevInstancePtrAddress, int* hWndPtrAddress, int nCmdShow, int screenWidth, int screenHeight);
extern "C" DllExport void WndProc(int* hWndPtrAddress, int msg, int wParam, int lParam);
extern "C" DllExport void RenderFrame();

