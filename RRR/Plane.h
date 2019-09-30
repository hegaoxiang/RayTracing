#pragma once
#include"Object.h"

class Plane:public Object
{
public:
	Plane(Point center,Direction normal):
		m_center(center),m_normal(normal)
	{}

	// Í¨¹ý Object ¼Ì³Ð
	virtual HitRecord Hit(const Ray& ray) override;

public:
	Point m_center;
	Direction m_normal;
};

