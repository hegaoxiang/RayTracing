#include "EditorFunc.h"
#include "Window.h"
#include"Render2D.h"
#include"Model.h"
#include<iostream>
#define TEST MessageBox(NULL, L"test", L"se", MB_OK)
Window* g_pWnd;
Render2D* g_pRender;
DllExport int EditorMain(int* instancePtrAddress, int* hPrevInstancePtrAddress, int* hWndPtrAddress, int nCmdShow, int screenWidth, int screenHeight)
{
	HINSTANCE hInstance = (HINSTANCE)instancePtrAddress;
	HINSTANCE hPrevInstance = (HINSTANCE)hPrevInstancePtrAddress;
	HWND hWnd = (HWND)hWndPtrAddress;

	g_pWnd = new Window(hWnd,screenWidth,screenHeight);
	std::cout << screenWidth << screenHeight << "\n"<<std::endl;
	g_pRender = new Render2D();
	
	g_pRender->SetFrameBuf(FrameBuffer(screenWidth+1, screenHeight+1,4 ));
	
	return 0;
}
void WndProc(int* hWndPtrAddress, int msg, int wParam, int lParam)
{
	
}
static int i = 0;
DllExport void RenderFrame()
{
	auto model = new Model("D:\\OBJ\\african_head.obj");
	
	for (int i = 0; i < model->NumFaces(); i++) {
		std::vector<int> face = model->Face(i);
		// face: i0,i1,i2 of triangle
		for (int j = 0; j < 3; j++) {
			Vec3 v0 = model->Vert(face[j]);
			// this % used for when j = 2 to get i2, i0
			Vec3 v1 = model->Vert(face[(j + 1) % 3]);
			int x0 = (v0.X() + 1.) * g_pWnd->m_width / 2.;
			int y0 = (v0.Y() + 1.) * g_pWnd->m_height / 2.;
			int x1 = (v1.X() + 1.) * g_pWnd->m_width / 2.;
			int y1 = (v1.Y() + 1.) * g_pWnd->m_height / 2.;
			
			g_pRender->DrawLine(x0, y0, x1, y1);
		}
		
	}
	
	g_pRender->DrawLine(393, 204,392,208);
	//g_pRender->DrawCircle(100, 200, 99);
	g_pWnd->Draw(*g_pRender->m_pFrameBuf);
	g_pWnd->Draw(*g_pRender->m_pFrameBuf);
	
	//delete model;
}
