#pragma once
#include<array>
#include<string>
#include"Math.h"

using std::string;
using std::array;
const int SCREEN_HEIGHT = 1921;
const int SCREEN_WIDTH = 1081;

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
			fill(item.begin(), item.end(), Vec3{ 0,0,0 });
		}
	}
	void Resize(int width, int height)
	{
		m_bufferWidth = width;
		m_bufferHeight = height;
	}
	void SetPixel(int x, int y, Vec3 color);

	void Display();

	array<array<Vec3, SCREEN_WIDTH>, SCREEN_HEIGHT> m_buffer;

	int m_bufferWidth;
	int m_bufferHeight;
	const string m_fileName;
};

