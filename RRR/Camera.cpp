#include"Math.h"
#include "Camera.h"

using namespace DirectX;
/*
Camera::Camera(Canvas* canvas, Point eyePos, Point target, float dist)
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
*/
/*
Ray Camera::GetRay(int x, int y)
{
	auto right = XMLoadFloat3(&m_right);
	auto forward = XMLoadFloat3(&m_forward);
	auto up = XMLoadFloat3(&m_up);

	int dx = x - m_canvas->m_sceenWidth / 2;
	int dy = y - m_canvas->m_sceenHeight / 2;

	Direction dir;
	XMStoreFloat3(&dir,XMVector3Normalize(right * dx + up * dy - forward * m_viewDist));

	return Ray(m_origin, dir);
}*/
Camera::Camera()
{
	m_lower_left_corner = Point{ -2.0,-1.0,-1.0 };
	m_horizontal = Direction{ 4.0,0.0,0.0 };
	m_vertical = Direction{ 0.0,2.0,0.0 };
	m_origin = Direction{ 0.0,0.0,0.0 };
}

Ray Camera::GetRay(float u, float v)
{
	

	auto horizontal = XMLoadFloat3(&m_horizontal);
	auto vertical = XMLoadFloat3(&m_vertical);
	auto lower_left_corner = XMLoadFloat3(&m_lower_left_corner);

	XMFLOAT3 target;
	XMStoreFloat3(&target, XMVector3Normalize(lower_left_corner + u * horizontal + v * vertical));

	return Ray{ Point{m_origin},Point{target} };
}