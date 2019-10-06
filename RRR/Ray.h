#pragma once
#include"Math.h"

class Ray
{
public:
	Ray() {}
	Ray(Vec3 orgin, Vec3 target) :
		m_origin(orgin),
		m_target(target)
	{
		m_dir = m_target- m_origin;
		m_dir = m_dir.UnitVector();
	}
	Vec3 operator()(float t)const;
	Vec3 PointAtPara(float t)const;
	
public:
	Vec3 m_origin;
	Vec3 m_target;
	Vec3 m_dir;
};

