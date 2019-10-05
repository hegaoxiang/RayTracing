#pragma once
#include"Math.h"
class Ray
{
public:
	Ray(Point orgin, Point target) :
		m_origin(orgin),
		m_target(target)
	{
		m_dir = sub(m_target, m_origin);
		m_dir = unit(m_dir);
	}

	Point PointAtPara(float t)const;
	
public:
	Point m_origin;
	Point m_target;
	Direction m_dir;
};

