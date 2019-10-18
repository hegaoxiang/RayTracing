#pragma once
#include<vector>
#include"Math.h"

constexpr int MAX_WIDTH =  1100;
constexpr int MAX_HEIGHT = 1000;

class Canvas
{
	
public:
	Canvas(int width, int height) :
		m_sceenHeight(height),
		m_sceenWidth(width)
	{
	}
public:
	// ��ӡ����
	void Display();

	// �����ص���ɫ
	void SetPixel(int x,int y,Vec3 color);

public:
	int m_sceenWidth;
	int m_sceenHeight;

	Vec3 m_buffer[MAX_HEIGHT][MAX_WIDTH ] = { };
	
};

