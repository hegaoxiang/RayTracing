#include "Render2D.h"

void Render2D::DrawLine(int x1, int y1, int x2, int y2, unsigned char* image)

{
#pragma region Bresenham
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
			int temp = (x * flagX + x1) * 400 * 3 + (y * flagY + y1) * 3;
			//image.SetPixel(x * flagX + x1, y * flagY + y1, Vec3(180, 180, 180));
			//SetPixel(dc, x * flagX + x1, y * flagY + y1, RGB(255, 1, 1));
			image[temp] = 255;
			image[temp + 1] = 1;
			image[temp + 2] = 1;
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
			int temp = (x * flagX + x1) * 400 * 3 + (y * flagY + y1) * 3;
			//image.SetPixel(x * flagX + x1, y * flagY + y1, Vec3(180, 180, 180));
			//SetPixel(dc, x * flagX + x1, y * flagY + y1, RGB(255, 1, 1));
			image[temp] = 255;
			image[temp + 1] = 1;
			image[temp + 2] = 1;
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