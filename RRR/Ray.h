#pragma once
#include"Math.h"
class Ray
{
public:
	Ray(Point orgin, Direction dir) :
		m_origin(orgin),
		m_dir(dir)
	{

	}

	Point PointAtPara(float t)const;
	
public:
	Point m_origin;
	Direction m_dir;
};

