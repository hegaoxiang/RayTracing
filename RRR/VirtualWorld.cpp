#include "VirtualWorld.h"
#include"Ray.h"
#include"Sphere.h"
#include"Plane.h"
#include<iostream>
#include"Lambertian.h"
#include"Metal.h"
VirtualWorld::VirtualWorld()
{
	m_pObj.push_back(new Sphere(Vec3{ 0,0,-1 }, 0.5f,new Lambertian(Vec3(0.8,0.3,0.3))));
	m_pObj.push_back(new Sphere(Vec3{ 0,-100.5,-1 }, 100.0f,new Lambertian(Vec3(0.8, 0.8, 0.0))));
	m_pObj.push_back(new Sphere(Vec3{ 1,0,-1 }, 0.5f, new Metal(Vec3(0.8, 0.6, 0.2))));
	m_pObj.push_back(new Sphere(Vec3{ -1,0,-1 }, 0.5f, new Metal(Vec3(0.8, 0.8, 0.8))));

	//m_pObj.push_back(new Plane(Vec3{ 0,0.3,-0.5 }, Vec3{ 0,1,0 }));
	//m_pObj.push_back(new Sphere(Vec3{ 0,0,-2 }, 1));
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

