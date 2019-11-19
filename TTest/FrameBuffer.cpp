#include "FrameBuffer.h"

FrameBuffer::FrameBuffer( int width, int height,int channels)
	:m_width(width),m_height(height),m_channels(channels)
{
	m_buffer.resize(m_width * m_height);
}


void FrameBuffer::SetPixel(int row, int col, Vec4 color)
{
	m_buffer[row * m_width  + col] = color;
}

const Vec4 FrameBuffer::GetPixel(int row, int col)const
{
	return m_buffer[row * m_width + col];
}
