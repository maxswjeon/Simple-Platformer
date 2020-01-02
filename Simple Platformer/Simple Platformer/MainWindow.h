#pragma once
#include "Object.h"
#include "Map.h"
#include "Window.h"

#include <chrono>
#include <vector>
#include <string>

class MainWindow : public SDL::Window, public Object
{
	std::vector<Object> elements_;
	Map map_;
	
public:
	MainWindow(const char* title, Map map,
		int width, int height,
		int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED,
		Uint32 wflags = SDL_WINDOW_HIDDEN, 
		int index = -1, Uint32 rflags = SDL_RENDERER_SOFTWARE);

	void Update(std::chrono::milliseconds);
	void setGravity(double g);
	void Render(SDL::Renderer) override;
};

