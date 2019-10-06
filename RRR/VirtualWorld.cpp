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

bool VirtualWorld::Hit(const Ray& ray, float tMin, float tMax, HitRecord& record)
{
	float closestSoFar = tMax;
	for (auto obj : m_pObj)
	{
		if (obj->Hit(ray, tMin, closestSoFar, record))
		{
			closestSoFar = record.m_t;
		}
	}
	return record.m_isHit;
}

