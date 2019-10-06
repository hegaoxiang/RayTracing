#include"Math.h"
#include "World.h"

#include<thread>
#include<iostream>

void World::SetWorld()
{
}

void World::SetCamera(Camera& camera)
{
	m_camera = &camera;
}

//test

void World::Render()
{
	size_t ns = 100;

	Canvas &canvas = *m_canvas;
	Ray ray = Ray{ Point{0,0,0},Point{0,0,-1}};
	int sum = canvas.m_sceenWidth * canvas.m_sceenHeight;
	for (int i = 0; i < canvas.m_sceenWidth; i++)
	{
		for (int j = 0; j < canvas.m_sceenHeight; j++)
		{
			RGB color{0,0,0};

			// ms
			for (size_t s = 0; s < ns; s++)
			{
				//test
				//std::thread t(time,i,j,sum);
				
				auto offsetX = drand();
				auto offsetY = drand();

				auto u = (i + offsetX) / canvas.m_sceenWidth;
				auto v = (j + offsetY) / canvas.m_sceenHeight;
				ray = m_camera->GetRay(u,v);
				color = puls(color,Color(ray));
			}
			color = mul(color,1.0f/ns);

			color = RGB{ sqrt(color.x),sqrt(color.y) ,sqrt(color.z) };
			// calculate the color that belongs to the ray
			
			color.x *= 255.99;
			color.y *= 255.99;
			color.z *= 255.99;
			canvas.SetPixel(i, j, color);
		}
	}
}

RGB World::Color(const Ray& ray)
{
	HitRecord hitRecord;
	if (m_world.Hit(ray, 0.0001, INFINITY, hitRecord))
	{
		Point target = puls(hitRecord.m_hitPoint, puls(hitRecord.m_normal, RandomInUnitSphere()));
		return mul(Color(Ray{ hitRecord.m_hitPoint,target }), 0.5f);
	}
	else
	{
		float t = 0.5 * (ray.m_dir.y + 1.0);
		return puls(mul(XMFLOAT3{ 1.0,1.0,1.0 }, (1.0 - t)), mul(XMFLOAT3{ 0.5,0.7,1.0 }, t));
	}
}


