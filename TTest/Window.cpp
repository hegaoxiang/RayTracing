
#include "Window.h"
#include"FrameBuffer.h"
void Window::Draw(const FrameBuffer& buffer)
{
	auto hdc = GetDC(m_hWnd);
	
	BITMAPINFO info = { 0 };
	info.bmiHeader.biBitCount = 24;
	info.bmiHeader.biWidth = buffer.m_width;
	info.bmiHeader.biHeight = -buffer.m_height;
	info.bmiHeader.biPlanes = 1;
	info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	info.bmiHeader.biSizeImage = buffer.m_width * buffer.m_height * 3;
	info.bmiHeader.biCompression = BI_RGB;

	StretchDIBits(hdc, 0, 0, m_width, m_height, 0, 0, buffer.m_width, buffer.m_height, buffer.m_pImage, &info, DIB_RGB_COLORS, SRCCOPY);
	ReleaseDC(m_hWnd, hdc);
}
