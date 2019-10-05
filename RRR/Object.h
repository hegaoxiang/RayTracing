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
		m_color(RGB{ 1,1,1 }), m_t(INFINITY)
	{

	}
	RGB m_color;
	float m_t;
	Point m_hitPoint;
	Direction m_normal;
}HitRecord;/*
class HitRecord
{
public:
	HitRecord() :
		m_color(RGB{ 1,1,1 }), m_t(INFINITY), m_bHit(false)
	{

	}
	~HitRecord();

	bool m_bHit;
	RGB m_color;
	float m_t;
private:

};


HitRecord::~HitRecord()
{
}

*/
class Object
{
public:
	virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord);

public:
	Material m_material;
};

