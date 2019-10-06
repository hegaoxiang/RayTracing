#pragma once
#include"Object.h"

class Plane:public Object
{
public:
	Plane(Vec3 center,Vec3 normal,Material* material):
		m_center(center)
	{
		m_normal = normal.UnitVector();

		m_pMaterial = material;
	}

	// 通过 Object 继承
	virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord);

public:
	Vec3 m_center;
	// united
	Vec3 m_normal;

	// 通过 Object 继承
	virtual HitRecord GetHitRecord(const Vec3& hitPoint) override;
};

