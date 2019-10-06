#pragma once

class Ray
{
public:
	Ray(Vec3 orgin, Vec3 dir) :
		m_origin(orgin),
		m_dir(dir)
	{

	}

	Vec3 PointAtPara(float t)const;
	
public:
	Vec3 m_origin;
	Vec3 m_dir;
};

