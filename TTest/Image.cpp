#include "Image.h"
#include"FrameBuffer.h"
Image::Image(int width, int height, int channels, unsigned char* pImage)
	: m_width(width), m_height(height), m_channels(channels), m_pImage(pImage)
{
}

unsigned char* Image::GetPixel(int row, int col)
{
	int idx = row * m_width * m_channels + col * m_channels;
	return &m_pImage[idx];
}

void BlitBufferRGB(const FrameBuffer& src, Image& dst)
{
	int width = fmin(src.m_width, dst.m_width);
	int height = fmin(src.m_height, dst.m_height);
	int r, c;

	assert(width > 0 && height > 0);
	assert(dst.m_channels == 3 || dst.m_channels == 4);

	for (r = 0; r < height; r++) {
		for (c = 0; c < width; c++) {
			int flipped_r = src.m_height - 1 - r;
			Vec4i src_value = src.GetPixel( flipped_r, c);
			if (flipped_r == 0 && c == 0)
			{
				int a = 1;
			}
			unsigned char* dst_pixel = dst.GetPixel( r, c);
			dst_pixel[0] = (src_value.x);  /* red */
			dst_pixel[1] = (src_value.y);  /* green */
			dst_pixel[2] = (src_value.z);  /* blue */
		}
	}
}
void BlitBufferBGR(const FrameBuffer& src, Image& dst)
{
	int width = fmin(src.m_width, dst.m_width);
	int height = fmin(src.m_height, dst.m_height);
	int r, c;

	assert(width > 0 && height > 0);
	assert(dst.m_channels == 3 || dst.m_channels == 4);

	for (r = 0; r < height; r++) {
		for (c = 0; c < width; c++) {
			int flipped_r = src.m_height - 1 - r;
			if (flipped_r == 0 && c == 0)
			{
				int a = 1;
			}
			Vec4i src_value = src.GetPixel(flipped_r, c);
			unsigned char* dst_pixel = dst.GetPixel(r, c);
			dst_pixel[0] = (src_value.z);  /* blue */
			dst_pixel[1] = (src_value.y);  /* green */
			dst_pixel[2] = (src_value.x);  /* red */
		}
	}
}

