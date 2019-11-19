#include "EditorFunc.h"
#include "Window.h"
#include"Render2D.h"
#define TEST MessageBox(NULL, L"test", L"se", MB_OK)
Window* g_pWnd;
Render2D* g_pRender;
DllExport int EditorMain(int* instancePtrAddress, int* hPrevInstancePtrAddress, int* hWndPtrAddress, int nCmdShow, int screenWidth, int screenHeight)
{
	HINSTANCE hInstance = (HINSTANCE)instancePtrAddress;
	HINSTANCE hPrevInstance = (HINSTANCE)hPrevInstancePtrAddress;
	HWND hWnd = (HWND)hWndPtrAddress;

	g_pWnd = new Window(hWnd,screenWidth,screenHeight);
	
	g_pRender = new Render2D();
	
	g_pRender->SetFrameBuf(FrameBuffer(450, 451 ));
	
	return 0;
}
void WndProc(int* hWndPtrAddress, int msg, int wParam, int lParam)
{
	
}
DllExport void RenderFrame()
{
	//g_pRender->DrawLine(0, 0, 320, 380);
	g_pRender->DrawCircle(100, 200, 100);
	g_pWnd->Draw(*g_pRender->m_pFrameBuf);
	
}
