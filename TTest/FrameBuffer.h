#pragma once

class FrameBuffer
{
public:
	// RBG
	FrameBuffer(int width,int height);
	~FrameBuffer() { ; }
	void SetPixel(int x, int y);
	unsigned char* m_pImage;
	int m_width;
	int m_height;
};

