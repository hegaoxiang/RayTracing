#include"CG_PPM.h"
#include "Canvas.h"
#include<fstream>
using namespace std;

CG_PPM g_CGppm{ "test.ppm"};

void Canvas::Display()
{
	g_CGppm.Resize(m_sceenWidth, m_sceenHeight);
	g_CGppm.Display();
}

void Canvas::SetPixel(int x, int y, RGB color)
{
	g_CGppm.SetPixel(x, y, color);
}
