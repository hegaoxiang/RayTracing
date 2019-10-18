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
	// ͨ�� Object �̳�
	virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord);

public:
	Vec3	m_orgin;
	double		m_radius;


	// ͨ�� Object �̳�
	virtual HitRecord GetHitRecord(const Vec3& hitPoint) override;


	// ͨ�� Object �̳�
	virtual AABB GenerateBox() override;

};

