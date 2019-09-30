#pragma once
#include<array>
#include<string>
#include"Math.h"

using std::string;
using std::array;
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;

class CG_PPM
{
public:
	CG_PPM(const string& fileName,int width = SCREEN_WIDTH,int height = SCREEN_HEIGHT):
		m_fileName(fileName),
		m_bufferHeight(height),
		m_bufferWidth(width)
	{
		for (auto item : m_buffer)
		{
			fill(item.begin(), item.end(), RGB{ 0,0,0 });
		}
	}
	void SetPixel(int x, int y, RGB color);

	void Display();

	array<array<RGB, SCREEN_WIDTH>, SCREEN_HEIGHT> m_buffer;

	int m_bufferWidth;
	int m_bufferHeight;
	const string m_fileName;
};

