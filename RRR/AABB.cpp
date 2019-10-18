#include "AABB.h"
#include"Ray.h"

bool AABB::Hit(const Ray& ray, float t_min, float t_max)
{
	/*auto max_o = m_max - ray.m_origin;
	auto min_o = m_min - ray.m_origin;

	float min = min_o.X() / ray.m_dir.X();
	float max = max_o.X() / ray.m_dir.X();

	float min1 = min_o.Y() / ray.m_dir.X();
	float max1 = max_o.Y() / ray.m_dir.X();

	float min2 = min_o.Z() / ray.m_dir.Z();
	float max2 = max_o.Z() / ray.m_dir.Z();

	min = std::max({ min,min1,min2 });
	max = std::min({ max,max1,max2 });
	
	if (min < max && min <= t_min && t_min < max)
		return true;
	return false;*/

	for (int i = 0; i < 3; i++)
	{
		float t0 = fminf((m_min[i] - ray.m_origin[i]) / ray.m_dir[i],
			(m_max[i] - ray.m_origin[i]) / ray.m_dir[i]);
		float t1 = fmaxf((m_min[i] - ray.m_origin[i]) / ray.m_dir[i],
			(m_max[i] - ray.m_origin[i]) / ray.m_dir[i]);
		t_min = fmaxf(t0, t_min);
		t_max = fminf(t1, t_max);
		if (t_max <= t_min)
			return false;
	}
	return true;
}

AABB::AABB(const AABB& b1, const AABB& b2)
{
	m_min = Vec3{
		fminf(b1.m_min.X(),b2.m_min.X()),
		fminf(b1.m_min.Y(),b2.m_min.Y()),
		fminf(b1.m_min.Z(),b2.m_min.Z()) };
	m_max = Vec3{
		fmaxf(b1.m_max.X(),b2.m_max.X()),
		fmaxf(b1.m_max.Y(),b2.m_max.Y()),
		fmaxf(b1.m_max.Z(),b2.m_max.Z()) };
}
