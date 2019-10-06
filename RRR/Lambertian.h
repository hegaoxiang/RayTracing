#pragma once
#include "Material.h"
class Lambertian :
	public Material
{
public:
	Lambertian(const Vec3& a) :
		m_albedo(a) {}
	// ͨ�� Material �̳�
	virtual bool Scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& rOut) const override;

	// ������
	Vec3 m_albedo;

};

