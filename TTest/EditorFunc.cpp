#include "EditorFunc.h"
#include "Window.h"
#include"Render2D.h"
Window* g_pWnd;
DllExport int EditorMain(int* instancePtrAddress, int* hPrevInstancePtrAddress, int* hWndPtrAddress, int nCmdShow, int screenWidth, int screenHeight)
{
	HINSTANCE hInstance = (HINSTANCE)instancePtrAddress;
	HINSTANCE hPrevInstance = (HINSTANCE)hPrevInstancePtrAddress;
	HWND hWnd = (HWND)hWndPtrAddress;

	g_pWnd = new Window(hWnd,screenWidth,screenHeight);
	
	return 0;
}
void WndProc(int* hWndPtrAddress, int msg, int wParam, int lParam)
{
	
}
DllExport void RenderFrame()
{
	
	unsigned char* buf = new unsigned char[400 * 400 * 3];
	Render2D::DrawLine(0, 0, 320, 380, buf);
	g_pWnd->Draw(buf);
	delete[] buf;
}
