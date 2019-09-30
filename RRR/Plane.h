#pragma once
#include"Object.h"

class Plane:public Object
{
public:
	Plane(Point center,Direction normal):
		m_center(center),m_normal(normal)
	{}

	// ͨ�� Object �̳�
	virtual HitRecord Hit(const Ray& ray) override;

public:
	Point m_center;
	Direction m_normal;
};

