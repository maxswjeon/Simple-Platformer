#pragma once
#include "Renderer.h"

class Object
{
public:
	virtual void Render(SDL::Renderer) = 0;
};

