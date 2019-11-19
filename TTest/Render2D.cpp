#include "Render2D.h"


void Render2D::DrawLine(int x1, int y1, int x2, int y2)
{

	int dx = x2 - x1;
	int dy = y2 - y1;

	int flagX = (dx > 0) ? 1 : -1;
	int flagY = (dy > 0) ? 1 : -1;

	dx *= flagX;
	dy *= flagY;

	int step = (dx > dy) ? dx : dy;

	int e = 0;// e = d * dx
	int x = 0, y = 0;// 将直线平移到x1，y1为原点，通过flagX和flagY解决非第一象限的直线问题

	if (dx > dy)
	{
		for (int i = 0; i < step; i++)
		{
			
			SetPixel(x * flagX + x1, y * flagY + y1);
			
			x++;

			e = e + dy;

			if (2 * e > dx)
			{
				e -= dx;
				y++;
			}
		}
	}
	else
	{
		for (int i = 0; i < step; i++)
		{
			
			SetPixel(x * flagX + x1, y * flagY + y1);
			y++;

			e = e + dx;

			if (2 * e > dy)
			{
				e -= dy;
				x++;
			}
		}
	}
}

void Render2D::DrawCircle(int x, int y, int radius)
{
	int x0 = 0;
	int y0 = radius;

	int d = 1 - radius;
	while (x0 <= y0)
	{
		SetPixel(x + x0, y + y0);
		SetPixel(x + x0, y + -y0);
		SetPixel(x + -x0, y + y0);
		SetPixel(x + -x0, y + -y0);
		SetPixel(x + y0, y + x0);
		SetPixel(x + y0, y + -x0);
		SetPixel(x + -y0, y + x0);
		SetPixel(x + -y0, y + -x0);
		
		if (d < 0)
			d += 2 * x0 + 3;
		else
		{
			d += 2 * (x0 - y0) + 5;
			y0--;
		}
		x0++;
	}
}

void Render2D::SetFrameBuf(const FrameBuffer& frameBuf)
{
	m_pFrameBuf = new FrameBuffer(frameBuf);
}

void Render2D::SetPixel(int x, int y,Vec4 color)
{
	m_pFrameBuf->SetPixel(x, y, color);
}

void Render2D::SetPixel(int x, int y)
{
	SetPixel(x, y, Vec4{ 255,1,1,0 });
}

