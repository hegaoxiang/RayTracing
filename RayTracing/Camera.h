#pragma once
#include"Ray.h"
#include"Canvas.h"

class Camera
{
public:
	Camera(Canvas* canvas, Point eyePos, Point target,float dist = 3.0f);
	Ray GetRay(int x, int y);
	
public:
	Point m_origin;

	// ÓÒÊÖ×ø±êÏµ unit vector
	Direction m_forward;
	Direction m_right;
	Direction m_up;

	float m_viewDist;

public:
	Canvas *m_canvas;
};

