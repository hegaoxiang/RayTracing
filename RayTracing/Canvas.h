#pragma once
#include<vector>


constexpr int MAX_WIDTH = 600;
constexpr int MAX_HEIGHT = 600;

class Canvas
{
public:
	Canvas(int width, int height) :
		m_sceenHeight(height),
		m_sceenWidth(width)
	{
	}
public:
	// 打印画布
	void Display();

	// 给像素点上色
	void SetPixel(int x,int y,Vec3 color);

public:
	int m_sceenWidth;
	int m_sceenHeight;

	Vec3 m_buffer[MAX_HEIGHT][MAX_WIDTH ] = { };
	
};

