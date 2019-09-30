#include "VirtualWorld.h"
#include"Ray.h"
#include"Sphere.h"
#include"Plane.h"
#include<iostream>
VirtualWorld::VirtualWorld()
{
	//m_pObj.push_back(new Sphere(Point{ 0,0,-5 }, 5));
	//m_pObj.push_back(new Plane(Point{ 0,0,0 }, Direction{ 0,1,0 }));

}

RGB VirtualWorld::Color(Ray& ray)
{
	
	float t = 0.5 * (ray.m_dir.y + 1.0);
	//std::cout << ray.m_dir.x << " :x" << ray.m_dir.y << " :y" << ray.m_dir.z << " :z\n";

	return puls(mul(XMFLOAT3{ 1.0,1.0,1.0 }, (1.0 - t)), mul(XMFLOAT3{0.5,0.7,1.0},t));

	HitRecord hitRecord;

	for (auto obj : m_pObj)
	{
		
		HitRecord tempHR = obj->Hit(ray);
		if (tempHR.m_t > 0 && tempHR.m_t < hitRecord.m_t)
		{
			hitRecord = tempHR;
		}
	}
	if (hitRecord.m_bHit)
	{
		return hitRecord.m_color;
	}
	
}
