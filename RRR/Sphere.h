#pragma once
#include"Object.h"

class Sphere : public Object
{
public:
	Sphere(Point o, double radius):
		m_orgin(o),m_radius(radius)
	{
		m_material.m_rgb = RGB{ 0.8,0,0 };
	}
	// ͨ�� Object �̳�
	virtual HitRecord Hit(const Ray& ray) override;

public:
	Point	m_orgin;
	double		m_radius;

};

