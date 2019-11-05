
#include "Window.h"

void Window::Draw(unsigned char* buffer)
{
	auto hdc = GetDC(m_hWnd);
	
	BITMAPINFO info = { 0 };
	info.bmiHeader.biBitCount = 24;
	info.bmiHeader.biWidth = 400;
	info.bmiHeader.biHeight = -400;
	info.bmiHeader.biPlanes = 1;
	info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	info.bmiHeader.biSizeImage = 400 * 400 * 3;
	info.bmiHeader.biCompression = BI_RGB;

	StretchDIBits(hdc, 0, 0, m_width, m_height, 0, 0, m_width, m_height, buffer, &info, DIB_RGB_COLORS, SRCCOPY);
	ReleaseDC(m_hWnd, hdc);

}
