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
	size_t ns = 100;

	Canvas &canvas = *m_canvas;
	Ray *ray;
	for (int i = 0; i < canvas.m_sceenWidth; i++)
	{
		for (int j = 0; j < canvas.m_sceenHeight; j++)
		{
			RGB color{0,0,0};

			// ms
			for (size_t s = 0; s < ns; s++)
			{
				auto offsetX = static_cast<float>(rand()) / RAND_MAX;
				auto offsetY = static_cast<float>(rand()) / RAND_MAX;

				auto u = (i + offsetX) / canvas.m_sceenWidth;
				auto v = (j + offsetY) / canvas.m_sceenHeight;
				ray = &(m_camera->GetRay(u,v));
				color = puls(color, m_world.Color(*ray));
			}
			
			color = mul(color,1.0f/ns);
			// calculate the color that belongs to the ray
			
			color.x *= 255.99;
			color.y *= 255.99;
			color.z *= 255.99;
			canvas.SetPixel(i, j, color);
		}
	}
}
