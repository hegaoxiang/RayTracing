
#include "Ray.h"

using namespace DirectX;
Vec3 Ray::PointAtPara(float t) const
{
	auto dir = XMLoadFloat3(&m_dir);
	auto orgin = XMLoadFloat3(&m_origin);

	Vec3 newPoint;
	XMStoreFloat3(&newPoint, (orgin + t * dir));

	return newPoint;

}
