#pragma once
class FrameBuffer;
class Image
{
public:
	Image(int width, int height, int channels, unsigned char* pImage);
	unsigned char* GetPixel(int row, int col);
	unsigned char* m_pImage;
	int m_width;
	int m_height;
	int m_channels;
	//void FlipV
};

void BlitBufferRGB(const FrameBuffer& src, Image& dst);
void BlitBufferBGR(const FrameBuffer& src, Image& dst);