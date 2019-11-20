#pragma once

#include "FrameBuffer.h"
class Render2D
{
public:
	void DrawLine(int x1, int y1, int x2, int y2);
	void  DrawCircle(int x, int y, int radius);
	void DrawTriangle(int x0,int y0,int x1,int y1,int x2,int y2);

	void SetFrameBuf(const FrameBuffer& frameBuf);

	FrameBuffer* m_pFrameBuf;
private:
	void SetPixel(int x, int y, Vec4 color);
	void SetPixel(int x, int y);

};

