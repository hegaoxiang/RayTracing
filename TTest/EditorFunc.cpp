#include "EditorFunc.h"
#include "Window.h"
#include"Render2D.h"
#include"Model.h"

#include<iostream>
#define TEST MessageBox(NULL, L"test", L"se", MB_OK)
Window* g_pWnd;
Render2D* g_pRender;
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{

	//
	//  函数: MyRegisterClass()
	//
	//  目标: 注册窗口类。
	//
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance,NULL );
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"test";
	wcex.hIconSm = LoadIcon(wcex.hInstance, NULL);

	RegisterClassExW(&wcex);

	//hInst = hInstance; // 将实例句柄存储在全局变量中

	HWND hWnd = CreateWindowW(L"test", L"testtitle", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 400, 600, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}
	
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	EditorMain((int*)hInstance, (int*)hPrevInstance, (int*)hWnd, nCmdShow, 400, 600);

	HACCEL hAccelTable = LoadAccelerators(hInstance, NULL);

	MSG msg;



	// 主消息循环:
	while (GetMessage(&msg, nullptr, 0, 0))
	{

		RenderFrame();
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}
int EditorMain(int* instancePtrAddress, int* hPrevInstancePtrAddress, int* hWndPtrAddress, int nCmdShow, int screenWidth, int screenHeight)
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
/*
void WndProc(int* hWndPtrAddress, int msg, int wParam, int lParam)
{
	
}*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		
	}
	break;
	case WM_PAINT:
	{

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


void RenderFrame()
{
	auto screen = g_pRender->m_pFrameBuf;
	auto model = new Model("D:\\OBJ\\african_head.obj");
	
	for (int i = 0; i < model->NumFaces(); i++) {
		if (i == 53)
		{
			int a = 10;
			a += 5;
		}
		std::vector<int> face = model->Face(i);
		// face: i0,i1,i2 of triangle
		/*
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
		*/
		int x[3], y[3];
		for (int j = 0; j < 3; j++) {
			Vec3 v0 = model->Vert(face[j]);
			
			x[j] = (v0.X() + 1.) * g_pWnd->m_width / 2.;
			y[j] = (v0.Y() + 1.) * g_pWnd->m_height / 2.;
			
		}
		g_pRender->DrawTriangle(x[0], y[0], x[1], y[1], x[2], y[2]);
		
		g_pWnd->Draw(*g_pRender->m_pFrameBuf);
		
	}
	
	g_pRender->DrawLine(393, 204,392,208);
	//g_pRender->DrawCircle(100, 200, 99);
	g_pWnd->Draw(*g_pRender->m_pFrameBuf);
	delete model;
}
