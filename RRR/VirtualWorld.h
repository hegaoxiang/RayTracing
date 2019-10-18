#pragma once

#include"Math.h"
#include<vector>
#include"Object.h"
class Ray;
class BVHNode;
class VirtualWorld
{
public:
	VirtualWorld();
	bool Hit(const Ray& ray,float tMin,float tMax,HitRecord& record);
	
	std::vector<Object*> m_pObj;
	BVHNode* m_pBVHNode;
};

