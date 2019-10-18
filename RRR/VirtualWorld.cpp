#include "VirtualWorld.h"
#include"Ray.h"
#include"Sphere.h"
#include"Plane.h"
#include<iostream>
#include"Lambertian.h"
#include"Metal.h"
#include"BVHNode.h"
#include<algorithm>
#include"AABB.h"
VirtualWorld::VirtualWorld()
{
	int n = 500;

	m_pObj.push_back(new Sphere(Vec3{ 0,-1000,0 }, 1000.0f,new Lambertian(Vec3(0.5,0.5,0.5))));
	
	int i = 0;
	
	for (int a = -11; a < 11; a++)
	{
		for (int b = -11; b < 11; b++)
		{
			float chooseMat = drand();
			Vec3 center(a + 0.9 * drand(), 0.2, b + 0.9 * drand());
			if ((center - Vec3(4, 0.2, 0)).Length() > 0.9)
			{
				if (chooseMat < 0.8)
				{
					m_pObj.push_back(new Sphere(center, 0.2, new Lambertian(Vec3(drand() * drand(), drand() * drand(), drand() * drand()))));
				}
				else
				{
					m_pObj.push_back(new Sphere(center, 0.2, new Metal(Vec3(0.5 * (1 + drand()), 0.5 * (1 + drand()), 0.5 * (1 + drand())), 0.5 * (1 + drand()))));
				}
			}
		}
	}
	m_pObj.push_back(new Sphere(Vec3{ 0,1,0 }, 1.0,new Lambertian(Vec3(0.8, 0.8, 0.0))));
	m_pObj.push_back(new Sphere(Vec3{-4,1,0 }, 1.0, new Lambertian(Vec3(0.4, 0.2, 0.1))));
	m_pObj.push_back(new Sphere(Vec3{ 4,1,0 }, 1.0, new Metal(Vec3(0.7, 0.6, 0.5),0.0)));

	auto f = [](Object* a1, Object* a2) {
		return a1->GenerateBox().m_min.X() > a2->GenerateBox().m_min.X();
	};
	std::sort(m_pObj.begin(), m_pObj.end(), f);

	m_pBVHNode = new BVHNode{ m_pObj,0,static_cast<int>(m_pObj.size()) - 1 };
	//m_pObj.push_back(new Plane(Vec3{ 0,0.3,-0.5 }, Vec3{ 0,1,0 }));
	//m_pObj.push_back(new Sphere(Vec3{ 0,0,-2 }, 1));
}

bool VirtualWorld::Hit(const Ray& ray, float tMin, float tMax, HitRecord& record)
{
	float closestSoFar = tMax;

	// test
	bool isUseBVH = true;
	
	if (isUseBVH == false)
	{
		for (auto obj : m_pObj)
		{
			if (obj->Hit(ray, tMin, closestSoFar, record))
			{
				closestSoFar = record.m_t;
			}

		}
	}
	else
	{
		m_pBVHNode->Hit(ray, tMin, closestSoFar, record);
	}
	return record.m_isHit;
}

