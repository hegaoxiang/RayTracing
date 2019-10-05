
#include "Ray.h"

using namespace DirectX;
Point Ray::operator()(float t) const
{
	return PointAtPara(t);
}
Point Ray::PointAtPara(float t) const
{
	auto dir = XMLoadFloat3(&m_dir);
	auto orgin = XMLoadFloat3(&m_origin);

	Point newPoint;
	XMStoreFloat3(&newPoint, (orgin + t * dir));

	return newPoint;

}
