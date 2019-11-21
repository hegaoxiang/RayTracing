#pragma once
#include"Math.h"
#include<vector>
class FrameBuffer
{
public:
	// RBG
	FrameBuffer(int width,int height,int channels);
	~FrameBuffer() { ; }
	void SetPixel(int row, int col,Vec4i kcolor);
	const Vec4i GetPixel(int row, int col) const;
	
	std::vector<Vec4i> m_buffer;

	int m_width;
	int m_height;
	int m_channels;
};

