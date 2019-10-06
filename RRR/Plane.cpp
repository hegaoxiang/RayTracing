#include "Plane.h"
#include"Ray.h"

// (p + t*d - o)*normal = 0
// (p - o + t*d)*normal = 0
// (p-o)*normal + t*d*normal = 0
//  t*d*normal = -(p-o)*normal 
//  t = -(p-o)*normal / d*normal



bool Plane::Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord)
{
	auto o = XMLoadFloat3(&m_center);
	auto normal = XMLoadFloat3(&m_normal);

	auto p = XMLoadFloat3(&ray.m_origin);

	auto pSubO = p - o;

	auto d = XMLoadFloat3(&ray.m_dir);

	float denominator = XMVectorGetX(XMVector3Dot(d, normal));
	if (denominator != 0)
	{
		float t = (-XMVectorGetX(XMVector3Dot(pSubO, normal))) / denominator;

		if (t_min < t && t < t_max)
		{
			Point hitPoint = ray(t);
			hitRecord.m_isHit = true;
			hitRecord.m_t = t;
			hitRecord.m_hitPoint = hitPoint;
			hitRecord.m_normal = m_normal;

			return true;
		}
		
		return false;
	}
}
