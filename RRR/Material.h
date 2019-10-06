#pragma once
#include"Object.h"

class Material
{
public:
	virtual bool Scatter(const Ray& rIn, const HitRecord& rec,Vec3& attenuation,Ray& rOut)const = 0;
};
