#include "Plane.h"
#include"Ray.h"

// (p + t*d - o)*normal = 0
// (p - o + t*d)*normal = 0
// (p-o)*normal + t*d*normal = 0
//  t*d*normal = -(p-o)*normal 
//  t = -(p-o)*normal / d*normal



bool Plane::Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord)
{
	//auto o = XMLoadFloat3(&m_center);
	//
	//auto normal = XMLoadFloat3(&m_normal);
	//
	//auto p = XMLoadFloat3(&ray.m_origin);

	//auto pSubO = p - o;
	auto pSubO = ray.m_origin - m_center;

	//auto d = XMLoadFloat3(&ray.m_dir);

	//float denominator = XMVectorGetX(XMVector3Dot(d, normal));
	float denominator = Dot(ray.m_dir, m_normal);

	if (denominator != 0)
	{
		float t = Dot(pSubO, m_normal) / -denominator;

		if (t_min < t && t < t_max)
		{
			Vec3 hitPoint = ray(t);
			hitRecord = GetHitRecord(hitPoint);
			hitRecord.m_isHit = true;
			hitRecord.m_t = t;
			return true;
		}
		
		return false;
	}
}

HitRecord Plane::GetHitRecord(const Vec3& hitPoint)
{
	HitRecord hitRecord;

	hitRecord.m_hitPoint = hitPoint;
	hitRecord.m_normal = m_normal;
	hitRecord.m_pMateril = m_pMaterial;
	return hitRecord;
}
