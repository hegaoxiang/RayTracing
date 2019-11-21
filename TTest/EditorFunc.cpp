#include "EditorFunc.h"
#include "Window.h"
#include"Render2D.h"
#include"Model.h"

#include<iostream>
#define TEST MessageBox(NULL, L"test", L"se", MB_OK)
Window* g_pWnd;
Render2D* g_pRender;
auto model = new Model("D:\\OBJ\\african_head.obj");
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
	
	for (int i = 0; i < model->NumFaces(); i++) {
		
		std::vector<int> face = model->Face(i);
		// face: i0,i1,i2 of triangle
		Vec2i screenCoords[3];
		Vec3f worldCoords[3];
	
		Vec3f norm;
		for (int j = 0; j < 3; j++) {
			Vec3f v0 = model->Vert(face[j*2]);
			
			screenCoords[j] = Vec2i((v0.x + 1.) * g_pWnd->m_width / 2., (v0.y + 1.) * g_pWnd->m_height / 2.);
			worldCoords[j] = v0;
			norm = norm + model->m_norms[face[j * 2 + 1]];
			
		}
		norm = norm.normalize();
		//auto n = (worldCoords[1] - worldCoords[0]) ^ (worldCoords[2] - worldCoords[0]);
		//n = n.normalize();
		auto intensity = norm * Vec3f{ 0,0,-1 };
		if (intensity > 0)
		{
			
			g_pRender->DrawLine(screenCoords[0].x, screenCoords[0].y, screenCoords[0].x + norm.x*20, screenCoords[0].y + norm.y*20);

			//g_pRender->DrawTriangle(screenCoords[0].x, screenCoords[0].y, screenCoords[1].x, screenCoords[1].y, screenCoords[2].x, screenCoords[2].y, Vec4f{ intensity * 255,intensity * 255, intensity * 255, 255 });
			//g_pRender->DrawTriangle(screenCoords[0], screenCoords[1], screenCoords[2], Vec4i(n.x * 255,n.y * 255, n.z * 255, 255 ));
			g_pRender->DrawTriangle(screenCoords[0], screenCoords[1], screenCoords[2], Vec4i(intensity * 255, intensity * 255, intensity * 255, 255));

		}
		
	}
	
	//cross((Vec3f[2] - worldCoords[0]), (worldCoords[1] - worldCoords[0]));
	//g_pRender->DrawTriangle(0, 0, 200, 200, 400, 0, Vec4i(255, 127, 127, 255));;
	//g_pRender->DrawLine(0, 0, 200,200);
	//g_pRender->DrawLine(400, 0, 200, 200);
	//g_pRender->DrawLine(0, 0, 400, 0);
	
	g_pWnd->Draw(*g_pRender->m_pFrameBuf);
}
