#pragma once
#include "Material.h"
class Lambertian :
	public Material
{
public:
	Lambertian(const Vec3& a) :
		m_albedo(a) {}
	// 通过 Material 继承
	virtual bool Scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& rOut) const override;

	// 反射率
	Vec3 m_albedo;

};

