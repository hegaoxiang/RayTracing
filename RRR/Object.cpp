#include "Object.h"
#include"Ray.h"

bool Object::Hit(const Ray& ray,float t_min,float t_max, HitRecord& hitRecord)
{
	return true;
}

Direction RandomInUnitSphere()
{
	Direction p;
	do
	{
		p = mul(sub(Point{ drand(),drand(),drand() }, Point{ 0.5f,0.5f,0.5f }), 2);
	} while (length(p) >= 1.0f);
	return p;
}