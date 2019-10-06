
#include "World.h"

void World::SetWorld()
{
}

void World::SetCamera(Camera& camera)
{
	m_camera = &camera;
}

void World::Render()
{
	Canvas canvas = *(m_camera->m_canvas);

	for (int i = 0; i < canvas.m_sceenWidth; i++)
	{
		for (int j = 0; j < canvas.m_sceenHeight; j++)
		{
			Ray ray = m_camera->GetRay(i, j);
			
			// calculate the color that belongs to the ray
			Vec3 color =  m_world.Color(ray);

			canvas.SetPixel(i, j, color);
		}
	}
}
