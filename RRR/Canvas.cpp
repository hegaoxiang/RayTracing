
#include "Canvas.h"
#include<fstream>
using namespace std;

void Canvas::Display()
{
	/*
	*	ppm
	*/
	ofstream ppmFile("TEST.ppm");
	
	ppmFile << "P3\n" << m_sceenWidth << " " << m_sceenHeight << "\n255\n";

	for (int j = m_sceenHeight - 1; j >= 0; j--)
	{
		for (int i = 0; i < m_sceenWidth; i++)
		{
			ppmFile << static_cast<int>(m_buffer[j][i].x) << " " << static_cast<int>(m_buffer[j][i].y) << " " << static_cast<int>(m_buffer[j][i].z) << "\n";
		}
	}

	ppmFile.close();
}

void Canvas::SetPixel(int x, int y, RGB color)
{
	m_buffer[y][x] = color;
}
