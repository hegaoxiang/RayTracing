
#include "Window.h"
#include"FrameBuffer.h"
void Window::CreateSurface()
{
	BITMAPINFOHEADER bi_header;
	HDC window_dc;
	HBITMAP dib_bitmap;
	HBITMAP old_bitmap;
	unsigned char* buffer;

	window_dc = GetDC(m_hWnd);
	m_memoryDc = CreateCompatibleDC(window_dc);
	ReleaseDC(m_hWnd, window_dc);

	memset(&bi_header, 0, sizeof(BITMAPINFOHEADER));
	bi_header.biSize = sizeof(BITMAPINFOHEADER);
	bi_header.biWidth = m_width;
	bi_header.biHeight = -m_height;  /* top-down */
	bi_header.biPlanes = 1;
	bi_header.biBitCount = 32;
	bi_header.biCompression = BI_RGB;
	dib_bitmap = CreateDIBSection(m_memoryDc, (BITMAPINFO*)& bi_header,
		DIB_RGB_COLORS, (void**)& buffer, NULL, 0);
	assert(dib_bitmap != NULL);
	old_bitmap = (HBITMAP)SelectObject(m_memoryDc, dib_bitmap);
	DeleteObject(old_bitmap);

	m_surface = new Image(m_width, m_height, 4, buffer);
}
void Window::PresentSurface()
{
	HDC window_dc = GetDC(m_hWnd);
	HDC memory_dc = m_memoryDc;
	Image* surface = m_surface;
	int width = surface->m_width;
	int height = surface->m_height;
	BitBlt(window_dc, 0, 0, width, height, memory_dc, 0, 0, SRCCOPY);
	ReleaseDC(m_hWnd, window_dc);
}
void Window::Draw(const FrameBuffer& buffer)
{
	BlitBufferRGB(buffer, *m_surface);
	PresentSurface();
}
