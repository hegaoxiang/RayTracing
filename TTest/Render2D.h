#pragma once

#include "FrameBuffer.h"

class Render2D
{
public:
	void DrawLine(int x1, int y1, int x2, int y2,Vec4i color);
	void  DrawCircle(int x, int y, int radius);
	void DrawTriangle(int x0,int y0,int x1,int y1,int x2,int y2,Vec4i color);
	void DrawTriangle(Vec2i v0, Vec2i v1, Vec2i v2, Vec4i color);

	void DrawTriangle(Vec3f v0, Vec3f v1, Vec3f v2,FrameBuffer& zBuffer, Vec4i color);
	void SetFrameBuf(const FrameBuffer& frameBuf);

	FrameBuffer* m_pFrameBuf;
private:
	Vec3f Barycentric(Vec2f A, Vec2f B, Vec2f C, Vec2f P); 
	// ������ص�P��Vec3���ꡣ
	Vec3f Barycentric(Vec3f A, Vec3f B, Vec3f C, Vec2f P);
	void SetPixel(int x, int y, Vec4i color);
	void SetPixel(int x, int y);
	
};

