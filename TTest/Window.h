#pragma once
#include<windows.h>
#include<assert.h>
#include"Image.h"	
class FrameBuffer;
class Window
{
public:
	Window(HWND hwnd,int width,int height) :
		m_hWnd(hwnd), m_width(width), m_height(height) 
	{
		CreateSurface();
	} 
	
public:
	HWND m_hWnd;
	HDC m_memoryDc;
	int m_width;
	int m_height;

	Image *m_surface;

	void Draw(const FrameBuffer& buffer);
private:
	void CreateSurface();
	void PresentSurface();
};

