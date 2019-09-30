#pragma once

#include<iostream>

int main()
{
	World world;

	Canvas canvas{ 400, 600 };
	Vector3 eyePos{ 0, 0, 0 };
	Vector3 target{ 0, 0, 3 };

	Camera camera(canvas, XMLoadFloat3(&eyePos), XMLoadFloat3(&target));
	
	world.SetCamera(camera);
	world.Render();

	canvas.Display();

	return 0;
}