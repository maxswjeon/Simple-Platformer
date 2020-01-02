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

	void Render(SDL::Renderer) override;
public:
	MainWindow(const char* title, Map map,
		int width, int height,
		int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED,
		Uint32 wflags = SDL_WINDOW_HIDDEN, 
		int index = -1, Uint32 rflags = SDL_RENDERER_SOFTWARE);

	void SetGravity(double g);
	void AddObject(Object& o);
	
	void Update(std::chrono::milliseconds) override;
	void Render();
};

