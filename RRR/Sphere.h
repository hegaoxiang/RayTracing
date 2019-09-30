#pragma once
#include"Object.h"

class Sphere : public Object
{
public:
	Sphere(Point o, int radius):
		m_orgin(o),m_radius(radius)
	{
		m_material.m_rgb = RGB{ 0.8,0,0 };
	}
	// Í¨¹ý Object ¼Ì³Ð
	virtual HitRecord Hit(const Ray& ray) override;

public:
	Point	m_orgin;
	int		m_radius;

};

