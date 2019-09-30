#pragma once
#include"Ray.h"
#include"Canvas.h"

class Camera
{
public:
	//Camera(Canvas* canvas, Point eyePos, Point target,float dist = 3.0f);
	Camera(Canvas* canvas)
	{
		m_canvas = canvas; 
		m_lower_left_corner = Point{ -2.0,-1.0,-1.0 };
		m_horizontal = Point{ 4.0,0.0,0.0 };
		m_vertical = Direction{ 0.0,2.0,0.0 };
		m_origin = Direction{ 0.0,0.0,0.0 };
	}
	Ray GetRay(int x, int y);
	
public:
	/*
	Point m_origin;

	// ÓÒÊÖ×ø±êÏµ unit vector
	Direction m_forward;
	Direction m_right;
	Direction m_up;

	float m_viewDist;
	*/
	Point m_lower_left_corner;
	Direction m_horizontal;
	Direction m_vertical;
	Point m_origin;
public:
	Canvas *m_canvas;
};

