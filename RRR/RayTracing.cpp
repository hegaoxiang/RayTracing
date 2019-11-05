#pragma once
#include"Math.h"
#include<iostream>
#include"World.h"
int main()
{
	int nx = 50	;
	int ny = 50;
	auto canvas = new Canvas{ nx, ny };

	//Vec3 eyePos{ 0, 0, 0 };
	//
	//Vec3 target{ 0, 0, 3 };

	Vec3 lookFrom(13, 2, 3);
	Vec3 lookAt(0, 0, 0);
	float distToFocus = 10.0f;
	float aperture = 0.0f;

	
	auto camera = new Camera(lookFrom, lookAt, Vec3{ 0,1,0 }, 20, static_cast<float>(nx) / static_cast<float>(ny), aperture, distToFocus);
	auto world = new World(camera,canvas);

	world->SetCamera(*camera);

	world->Render();

	canvas->Display();

	return 0;
}