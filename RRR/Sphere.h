#pragma once
#include"Object.h"

class Sphere : public Object
{
public:
	Sphere(Vec3 o, double radius,Material *material):
		m_orgin(o),m_radius(radius)
	{
		m_pMaterial = material;
	}
	// 通过 Object 继承
	virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord);

public:
	Vec3	m_orgin;
	double		m_radius;


	// 通过 Object 继承
	virtual HitRecord GetHitRecord(const Vec3& hitPoint) override;


	// 通过 Object 继承
	virtual AABB GenerateBox() override;

};

