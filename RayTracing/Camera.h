#pragma once
#include"Ray.h"
#include"Canvas.h"

class Camera
{
public:
	Camera(Canvas* canvas, Vec3 eyePos, Vec3 target,float dist = 3.0f);
	Ray GetRay(int x, int y);
	
public:
	Vec3 m_origin;

	// ÓÒÊÖ×ø±êÏµ unit vector
	Vec3 m_forward;
	Vec3 m_right;
	Vec3 m_up;

	float m_viewDist;

public:
	Canvas *m_canvas;
};

