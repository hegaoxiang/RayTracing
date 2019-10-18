#pragma once

#include"Math.h"
class AABB;
class Ray;
class Material;
typedef struct HitRecord
{
	HitRecord() :
		 m_pMateril(nullptr), m_t(INFINITY),m_isHit(false)
	{

	}
	Material* m_pMateril;
	bool m_isHit;
	float m_t;
	Vec3 m_hitPoint;
	Vec3 m_normal;
}HitRecord;
class Object
{
public:
	Material* m_pMaterial;
public:
	virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord) = 0;

	virtual HitRecord GetHitRecord(const Vec3& hitPoint) = 0;

	virtual AABB GenerateBox() = 0;
};



