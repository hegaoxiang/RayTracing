#pragma once
#include<vector>
#include"Math.h"

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
	void SetPixel(int x,int y,RGB color);

public:
	int m_sceenWidth;
	int m_sceenHeight;

	RGB m_buffer[MAX_HEIGHT][MAX_WIDTH ] = { };
	
};

