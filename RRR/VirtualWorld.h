#pragma once

#include"Math.h"
#include<vector>
#include"Object.h"
class Ray;

class VirtualWorld
{
public:
	VirtualWorld();
	RGB Color(Ray& ray);
	
	std::vector<Object*> m_pObj;
};

