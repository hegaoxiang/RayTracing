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
			Vec4 src_value = src.GetPixel( flipped_r, c);
			unsigned char* dst_pixel = dst.GetPixel( r, c);
			dst_pixel[0] = float2uchar(src_value.R());  /* red */
			dst_pixel[1] = float2uchar(src_value.G());  /* green */
			dst_pixel[2] = float2uchar(src_value.B());  /* blue */
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
			Vec4 src_value = src.GetPixel(flipped_r, c);
			unsigned char* dst_pixel = dst.GetPixel(r, c);
			dst_pixel[0] = float2uchar(src_value.B());  /* blue */
			dst_pixel[1] = float2uchar(src_value.G());  /* green */
			dst_pixel[2] = float2uchar(src_value.R());  /* red */
		}
	}
}

