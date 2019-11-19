#pragma once
#include"Math.h"
#include<vector>
class FrameBuffer
{
public:
	// RBG
	FrameBuffer(int width,int height,int channels);
	~FrameBuffer() { ; }
	void SetPixel(int row, int col,Vec4 color);
	const Vec4 GetPixel(int row, int col) const;
	
	std::vector<Vec4> m_buffer;

	int m_width;
	int m_height;
	int m_channels;
};

