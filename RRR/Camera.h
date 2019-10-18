#pragma once
#include"Ray.h"
#include"Canvas.h"

class Camera
{
public:
	Camera(Canvas* canvas, Vec3 eyePos, Vec3 target,float dist = 1.0f);
	Camera();
	Camera(Vec3 lookFrom, Vec3 lookAt, Vec3 up, float vfov, float aspect);
	Camera(Vec3 lookFrom, Vec3 lookAt, Vec3 up, float vfov, float aspect,float aperture,float focusDist);//散焦模糊”
	Ray GetRay(float u, float v);
	
public:
	
	Vec3 m_origin;

	// 右手坐标系 unit vector
	Vec3 m_forward;
	Vec3 m_right;
	Vec3 m_up;

	float m_viewDist;
	


	Vec3 m_lower_left_corner;
	Vec3 m_horizontal;
	Vec3 m_vertical;

	float m_lensRadius;
public:

};

