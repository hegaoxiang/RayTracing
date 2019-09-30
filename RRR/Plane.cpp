#include "Plane.h"
#include"Ray.h"

// (p + t*d - o)*normal = 0
// (p - o + t*d)*normal = 0
// (p-o)*normal + t*d*normal = 0
//  t*d*normal = -(p-o)*normal 
//  t = -(p-o)*normal / d*normal

HitRecord Plane::Hit(const Ray& ray)
{
	HitRecord hitInfo;

	auto o = XMLoadFloat3(&m_center);
	auto normal = XMLoadFloat3(&m_normal);

	auto p = XMLoadFloat3(&ray.m_origin);

	auto pSubO = p - o;

	auto d = XMLoadFloat3(&ray.m_dir);

	float denominator = XMVectorGetX(XMVector3Dot(d, normal));
	if (denominator != 0)
	{
		hitInfo.m_t = (-XMVectorGetX(XMVector3Dot(pSubO, normal))) / denominator;
		hitInfo.m_bHit = true;
		hitInfo.m_color = RGB{ 0.7,0.7,0 };
	}
	else
		hitInfo.m_t = -1;
	return hitInfo;
}
