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
	// Í¨¹ý Object ¼Ì³Ð
	virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord);

public:
	Point	m_orgin;
	double		m_radius;

};

