#pragma once
#include<windows.h>
class FrameBuffer;
class Window
{
public:
	Window(HWND hwnd,int width,int height) :
		m_hWnd(hwnd), m_width(width), m_height(height) {} 

public:
	HWND m_hWnd;
	int m_width;
	int m_height;

	void Draw(const FrameBuffer& buffer);
};

