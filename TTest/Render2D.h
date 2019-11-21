#pragma once

#include "FrameBuffer.h"

class Render2D
{
public:
	void DrawLine(int x1, int y1, int x2, int y2);
	void  DrawCircle(int x, int y, int radius);
	void DrawTriangle(int x0,int y0,int x1,int y1,int x2,int y2,Vec4i color);
	void DrawTriangle(Vec2i v0, Vec2i v1, Vec2i v2, Vec4i color);
	void SetFrameBuf(const FrameBuffer& frameBuf);

	FrameBuffer* m_pFrameBuf;
private:
	Vec3f barycentric(Vec2f A, Vec2f B, Vec2f C, Vec2f P); 
	void SetPixel(int x, int y, Vec4i color);
	void SetPixel(int x, int y);

};

