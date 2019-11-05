#include"Math.h"
#include "World.h"
#include<thread>
#include<iostream>
#include"Material.h"
#include"ThreadPool.h"

void World::SetWorld()
{
}

void World::SetCamera(Camera& camera)
{
	m_camera = &camera;
}
//test
ThreadPool g_threadPool(8);
std::vector<std::future<Vec3>> g_Colors;
void World::Render()
{
	
	//g_threadPool.Start();
	

	Canvas &canvas = *m_canvas;
	
	
	int sum = canvas.m_sceenWidth * canvas.m_sceenHeight;
	for (int i = 0; i < canvas.m_sceenWidth; i++)
	{
		for (int j = 0; j < canvas.m_sceenHeight; j++)
		{

			
			// ms
			/*
			auto f = [i,j,this,&canvas]()
			{
				size_t ns = 50;

				Ray ray = Ray{ Vec3{0,0,0},Vec3{0,0,-1} };
				Vec3 color{ 0,0,0 };

				for (size_t s = 0; s < ns; s++)
				{
					//test
					//std::thread t(time,i,j,sum);

					auto offsetX = drand();
					auto offsetY = drand();

					auto u = (i + offsetX) / canvas.m_sceenWidth;
					auto v = (j + offsetY) / canvas.m_sceenHeight;
					ray = m_camera->GetRay(u, v);
					color += World::Color(ray, 0);
				}

				color /= ns;

				color = Vec3{ sqrt(color.X()),sqrt(color.Y()) ,sqrt(color.Z()) };
				// calculate the color that belongs to the ray

				color *= 255.99;
				canvas.SetPixel(i, j, color);
			};*/
			auto f = [i, j, this, &canvas]()
			{
				size_t ns = 50;

				Ray ray = Ray{ Vec3{0,0,0},Vec3{0,0,-1} };
				Vec3 color{ 0,0,0 };

				for (size_t s = 0; s < ns; s++)
				{
					//test
					//std::thread t(time,i,j,sum);

					auto offsetX = drand();
					auto offsetY = drand();

					auto u = (i + offsetX) / canvas.m_sceenWidth;
					auto v = (j + offsetY) / canvas.m_sceenHeight;
					ray = m_camera->GetRay(u, v);
					color += World::Color(ray, 0);
				}

				color /= ns;

				color = Vec3{ sqrt(color.X()),sqrt(color.Y()) ,sqrt(color.Z()) };
				// calculate the color that belongs to the ray

				color *= 255.99;
				return color;
			};
			//f();
			//g_threadPool.AppendTask(f);
			g_Colors.emplace_back(g_threadPool.enqueue(f));
			//g_Colors.emplace_back(f());
		}
	}

	//g_threadPool.Stop();
	for (__int64 i = 0; i < canvas.m_sceenWidth; i++)
	{
		for (__int64 j = 0; j < canvas.m_sceenHeight; j++)
		{
			canvas.SetPixel(i, j, g_Colors[i * (__int64)canvas.m_sceenHeight + j].get());
		}
	}
}

Vec3 World::Color(const Ray& ray,int depth)
{
	HitRecord hitRecord;
	if (m_world.Hit(ray, 0.0001, INFINITY, hitRecord))
	{
		Ray scattered;
		Vec3 attenuation;
		if (depth < 50 && hitRecord.m_pMateril->Scatter(ray, hitRecord, attenuation, scattered))
		{
			return attenuation * Color(scattered, depth + 1);
		}
		else
		{
			return Vec3(0, 0, 0);
		}
	}
	else// Ìì¿ÕÉ«
	{
		float t = 0.5 * (ray.m_dir.Y() + 1.0);
		return Vec3{ 1.0,1.0,1.0 }*(1.0 - t) + Vec3{ 0.5,0.7,1.0 }*t;
	}
}


