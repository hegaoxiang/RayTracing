#pragma once

#include"Math.h"

class Ray;
typedef struct Material
{
	RGB m_rgb;

}Material;

typedef struct HitRecord
{
	HitRecord() :
		m_color(RGB{ 1,1,1 }), m_t(INFINITY),m_isHit(false)
	{

	}
	RGB m_color;
	bool m_isHit;
	float m_t;
	Point m_hitPoint;
	Direction m_normal;
}HitRecord;
class Object
{
public:
	virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord);

public:
	Material m_material;
};
Direction RandomInUnitSphere();


