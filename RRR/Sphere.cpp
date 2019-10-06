#include "Sphere.h"
#include"Ray.h"


bool Sphere::Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord)
{
	//auto o = XMLoadFloat3(&m_orgin);
	//auto p = XMLoadFloat3(&ray.m_origin);
	//
	//auto pSubO = p - o;
	auto pSubO = ray.m_origin - m_orgin;

	//auto d = XMLoadFloat3(&ray.m_dir);

	float A = Dot(ray.m_dir, ray.m_dir);
	float B = 2 * Dot(ray.m_dir, pSubO);
	float C = Dot(pSubO, pSubO) - m_radius * m_radius;

	float discriminant = B * B - 4 * A * C;
	if (discriminant >= 0)
	{
		float t = (-B - sqrtf(discriminant)) / 2 * A;
		if (t_min < t && t < t_max)
		{
			Vec3 hitPoint = ray(t);
			hitRecord = GetHitRecord(hitPoint);
			hitRecord.m_isHit = true;
			hitRecord.m_t = t;
			
			return true;
		}
		t = (-B + sqrtf(discriminant)) / 2 * A;
		if (t_min < t && t < t_max)
		{
			Vec3 hitPoint = ray(t);
			hitRecord = GetHitRecord(hitPoint);
			hitRecord.m_isHit = true;
			hitRecord.m_t = t;

			return true;
		}
	}
	return false;
}

HitRecord Sphere::GetHitRecord(const Vec3& hitPoint)
{
	HitRecord hitRecord;

	hitRecord.m_hitPoint = hitPoint;
	hitRecord.m_normal = (hitPoint - m_orgin).UnitVector();
	hitRecord.m_pMateril = m_pMaterial;
	return hitRecord;
}
