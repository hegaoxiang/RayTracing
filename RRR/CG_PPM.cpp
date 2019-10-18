#include "CG_PPM.h"
#include<fstream>
#include"Math.h"
using namespace std;

void CG_PPM::SetPixel(int x, int y, Vec3 color)
{
	m_buffer[y][x] = color;
}

void CG_PPM::Display()
{
	ofstream file;
	try
	{
		file.open(m_fileName);
		file << "P3\n" << m_bufferWidth << " " << m_bufferHeight << "\n" << "255\n";
	}
	catch (const std::exception& e)
	{
		return;
	}
	

	for (int j = m_bufferHeight - 1; j >= 0; j--)
	{
		for (int i = 0; i < m_bufferWidth; i++)
		{
			file << static_cast<int>(m_buffer[j][i].X()) << " " << static_cast<int>(m_buffer[j][i].Y()) << " " << static_cast<int>(m_buffer[j][i].Z()) << "\n";
		}
	}
	file.close();
}
