
#include "Camera.h"

using namespace DirectX;

Camera::Camera(Canvas* canvas, Vec3 eyePos, Vec3 target, float dist)
{
	// orgin
	m_origin = eyePos;

	XMFLOAT3 dir{ eyePos.x - target.x,eyePos.y - target.y ,eyePos.z - target.z };
	// base coord
	auto forward = XMVector3Normalize(XMLoadFloat3(& dir));

	XMFLOAT3 tempUp{ 0,1,0 };
	auto right = XMVector3Normalize(XMVector3Cross(forward, XMLoadFloat3(&tempUp)));

	auto up= XMVector3Normalize(XMVector3Cross(right, forward));

	// viewDist
	m_viewDist = dist;

	// canvas
	m_canvas = canvas;

	XMStoreFloat3(&m_forward, forward);
	XMStoreFloat3(&m_right, right);
	XMStoreFloat3(&m_up, up);
}

Ray Camera::GetRay(int x, int y)
{
	auto right = XMLoadFloat3(&m_right);
	auto forward = XMLoadFloat3(&m_forward);
	auto up = XMLoadFloat3(&m_up);

	int dx = x - m_canvas->m_sceenWidth / 2;
	int dy = y - m_canvas->m_sceenHeight / 2;

	Vec3 dir;
	XMStoreFloat3(&dir,XMVector3Normalize(right * dx + up * dy - forward * m_viewDist));

	return Ray(m_origin, dir);
}
