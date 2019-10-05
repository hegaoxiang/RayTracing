#pragma once
#include"Ray.h"
#include"Canvas.h"

class Camera
{
public:
	Camera(Canvas* canvas, Point eyePos, Point target,float dist = 1.0f);
	Camera();
	Ray GetRay(float u, float v);
	
public:
	
	Point m_origin;

	// ÓÒÊÖ×ø±êÏµ unit vector
	Direction m_forward;
	Direction m_right;
	Direction m_up;

	float m_viewDist;
	


	Point m_lower_left_corner;
	Direction m_horizontal;
	Direction m_vertical;
	
public:

};

