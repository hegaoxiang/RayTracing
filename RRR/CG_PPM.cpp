#include "CG_PPM.h"
#include<fstream>
#include"Math.h"
using namespace std;

void CG_PPM::SetPixel(int x, int y, RGB color)
{
	m_buffer[y][x] = color;
}

void CG_PPM::Display()
{
	ofstream file(m_fileName);
	file << "P3\n" << m_bufferWidth << " " << m_bufferHeight << "\n" <<"255\n";

	for (int j = m_bufferHeight - 1; j >= 0; j--)
	{
		for (int i = 0; i < m_bufferWidth; i++)
		{
			file << static_cast<int>(m_buffer[j][i].x) << " " << static_cast<int>(m_buffer[j][i].y) << " " << static_cast<int>(m_buffer[j][i].z) << "\n";
		}
	}
	file.close();
}
