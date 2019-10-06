
#include "Ray.h"

using namespace DirectX;
Vec3 Ray::operator()(float t) const
{
	return PointAtPara(t);
}
Vec3 Ray::PointAtPara(float t) const
{
	auto newPoint = m_origin + t * m_dir;

	return newPoint;

}
