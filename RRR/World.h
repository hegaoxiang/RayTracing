#pragma once
#include<vector>
#include"Camera.h"
#include"Canvas.h"
#include"VirtualWorld.h"

using std::vector;

class World
{

public:
	World(Camera* camera, Canvas* canvas) :
		m_camera(camera), m_canvas(canvas)
	{}
	Camera* m_camera;
	Canvas* m_canvas;
	VirtualWorld m_world;
public:
	void SetWorld();
	void SetCamera(Camera& camera);
	void Render();
	RGB Color(const Ray& ray);
};

