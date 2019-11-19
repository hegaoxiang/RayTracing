#include "FrameBuffer.h"

FrameBuffer::FrameBuffer( int width, int height)
	:m_width(width),m_height(height)
{
	m_pImage = new unsigned char[width * height * 3];
}

void FrameBuffer::SetPixel(int x, int y)
{
	//for (int i = 0; i < 3; i++)
	//{
	//	m_pImage[x * m_height * 3 + y * 3 + i] = 255;
	//}
	m_pImage[x * m_height * 3 + y * 3 ] = 200;
	m_pImage[x * m_height * 3 + y * 3 + 1] = 1;
	m_pImage[x * m_height * 3 + y * 3 + 2] = 1;
}
