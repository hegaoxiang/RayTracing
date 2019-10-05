#pragma once
#include"Object.h"

class Plane:public Object
{
public:
	Plane(Point center,Direction normal):
		m_center(center)
	{
		m_normal = unit(normal);
	}

	// ͨ�� Object �̳�
	virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord);

public:
	Point m_center;
	Direction m_normal;
};

