#include "Lambertian.h"
#include "Ray.h"

bool Lambertian::Scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& rOut) const
{
	Vec3 target = rec.m_hitPoint + rec.m_normal + RandomInUnitSphere();
	rOut = Ray{ rec.m_hitPoint,target };
	attenuation = m_albedo;

	return true;
}

