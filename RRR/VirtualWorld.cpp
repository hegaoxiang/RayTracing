#include "VirtualWorld.h"
#include"Ray.h"
#include"Sphere.h"
#include"Plane.h"
#include<iostream>
VirtualWorld::VirtualWorld()
{
	m_pObj.push_back(new Sphere(Point{ 0,0,-1 }, 0.5f));
	m_pObj.push_back(new Sphere(Point{ 0,-100.5,-1 }, 100.0f));
	//m_pObj.push_back(new Plane(Point{ 0,0.3,-0.5 }, Direction{ 0,1,0 }));
	//m_pObj.push_back(new Sphere(Point{ 0,0,-2 }, 1));
}

RGB VirtualWorld::Color(Ray& ray)
{
	HitRecord hitRecord;
	HitRecord tempHitR;
	float closestSoFar = INFINITY;
	int objIdx = -1;
	int i = -1;
	for (auto obj : m_pObj)
	{
		++i;
		if (obj->Hit(ray, 0, closestSoFar, tempHitR))
		{
			closestSoFar = tempHitR.m_t;
			objIdx = i;
		}
	}
	if (-1 != objIdx)
	{
		hitRecord = tempHitR;
		return mul(puls(hitRecord.m_normal, XMFLOAT3{ 1,1,1 }),0.5);
		
	}

	float t = 0.5 * (ray.m_dir.y + 1.0);
	return puls(mul(XMFLOAT3{ 1.0,1.0,1.0 }, (1.0 - t)), mul(XMFLOAT3{0.5,0.7,1.0},t));
	
}
