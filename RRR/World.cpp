#include"Math.h"
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
	Canvas *canvas = (m_camera->m_canvas);
	Ray *ray;
	for (int i = 0; i < canvas->m_sceenWidth; i++)
	{
		for (int j = 0; j < canvas->m_sceenHeight; j++)
		{
			ray = &(m_camera->GetRay(i, j));
			
			// calculate the color that belongs to the ray
			RGB color =  m_world.Color(*ray);

			color.x *= 255.99;
			color.y *= 255.99;
			color.z *= 255.99;
			canvas->SetPixel(i, j, color);
		}
	}
}
