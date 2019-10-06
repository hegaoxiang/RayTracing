#pragma once
#include"Material.h"

class Metal:public Material
{
public:
	Metal(const Vec3& a,float f):
		m_albedo(a)
	{
		if (f < 1)m_fuzz = f;
		else m_fuzz = 1;
	}

	// Í¨¹ý Material ¼Ì³Ð
	virtual bool Scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& rOut) const override;

	Vec3 m_albedo;
	float m_fuzz;
};

