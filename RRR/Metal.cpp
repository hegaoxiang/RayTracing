#include "Metal.h"
#include"Ray.h"

bool Metal::Scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& rOut) const
{
	Vec3 reflectedTarget = Reflect(rIn.m_dir, rec.m_normal) + rec.m_hitPoint;
	rOut = Ray{ rec.m_hitPoint,reflectedTarget + m_fuzz * RandomInUnitSphere() };
	attenuation = m_albedo;
	return (Dot(rOut.m_dir, rec.m_normal) > 0);
}
