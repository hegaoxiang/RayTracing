
#include "Ray.h"

using namespace DirectX;
Point Ray::PointAtPara(float t) const
{
	auto dir = XMLoadFloat3(&m_dir);
	auto orgin = XMLoadFloat3(&m_origin);

	Point newPoint;
	XMStoreFloat3(&newPoint, (orgin + t * dir));

	return newPoint;

}
