#pragma once
#include "Point.h"
#include "Renderer.h"

#include <chrono>

class Object
{
public:
	virtual ~Object() = default;
	
	bool Solid = true;
	int Velocity[2] = {0, 0};
	SDL::Point Position = SDL::Point(0, 0);
	
	virtual void Render(SDL::Renderer) = 0;
	virtual void Update(std::chrono::milliseconds) = 0;
};

