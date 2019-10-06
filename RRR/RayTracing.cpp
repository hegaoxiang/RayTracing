#pragma once
#include"Math.h"
#include<iostream>
#include"World.h"

int main()
{
	auto canvas = new Canvas{ 200, 100 };

	Vec3 eyePos{ 0, 0, 0 };

	Vec3 target{ 0, 0, 3 };

	auto camera = new Camera();
	
	auto world = new World(camera,canvas);

	world->SetCamera(*camera);

	world->Render();

	canvas->Display();

	return 0;
}