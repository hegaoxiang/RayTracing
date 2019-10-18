#pragma once
#include"Math.h"
#include"Object.h"
class AABB
{
public:
	Vec3 m_min;
	Vec3 m_max;

	AABB(const Vec3& min, const Vec3& max) :
		m_max(max), m_min(min)
	{}
	
	bool Hit(const Ray& ray, float t_min, float t_max);

	AABB(const AABB& b1, const AABB& b2);
};

