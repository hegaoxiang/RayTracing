#include "Sphere.h"
#include"Ray.h"


bool Sphere::Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord)
{
	auto o = XMLoadFloat3(&m_orgin);
	auto p = XMLoadFloat3(&ray.m_origin);

	auto pSubO = p - o;

	auto d = XMLoadFloat3(&ray.m_dir);

	// xmvector3dot计算得到一个vector，其中每个分量都是点积值。
	float A = XMVectorGetX(XMVector3Dot(d, d));
	float B = 2 * XMVectorGetX(XMVector3Dot(d, pSubO));
	float C = XMVectorGetX(XMVector3Dot(pSubO, pSubO)) - powf(m_radius, 2);

	float discriminant = B * B - 4 * A * C;
	if (discriminant >= 0)
	{
		float t = (-B - sqrtf(discriminant)) / 2 * A;
		if (t_min < t && t < t_max)
		{
			Point hitPoint = ray(t);
			hitRecord.m_t = t;
			hitRecord.m_hitPoint = hitPoint;
			hitRecord.m_normal = unit(sub(hitPoint, m_orgin));

			return true;
		}
		t = (-B + sqrtf(discriminant)) / 2 * A;
		if (t_min < t && t < t_max)
		{
			Point hitPoint = ray(t);
			hitRecord.m_t = t;
			hitRecord.m_hitPoint = hitPoint;
			hitRecord.m_normal = unit(sub(hitPoint, m_orgin));

			return true;
		}
	}
	return false;
}
