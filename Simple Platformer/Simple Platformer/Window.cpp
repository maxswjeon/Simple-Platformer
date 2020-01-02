#include "Window.h"


SDL::Window::Window(const char* title, 
	int x, 
	int y, 
	int width, 
	int height, 
	Uint32 wflags,
	int rindex,
	Uint32 rflags,
	Uint32 required)
{
	subsystems_ = required;

	/*
	 * Subsystem initialization is ref-counted, you must call
	 * SDL_QuitSubSystem() for each SDL_InitSubSystem() to correctly
	 * shutdown a subsystem manually (or call SDL_Quit() to force
	 * shutdown). If a subsystem is already loaded then this call
	 * will increase the ref-count and return.
	 *
	 * https://wiki.libsdl.org/SDL_InitSubSystem
	 */
	SDL_InitSubSystem(required);

	window_ = SDL_CreateWindow(title, x, y, width, height, wflags);
	renderer_ = Renderer(window_, rindex, rflags);
}

SDL::Window::Window(std::string title, 
	int x, 
	int y, 
	int width, 
	int height, 
	Uint32 wflags,
	int rindex,
	Uint32 rflags,
	Uint32 required)
{
	subsystems_ = required;

	/*
	 * Subsystem initialization is ref-counted, you must call
	 * SDL_QuitSubSystem() for each SDL_InitSubSystem() to correctly
	 * shutdown a subsystem manually (or call SDL_Quit() to force
	 * shutdown). If a subsystem is already loaded then this call
	 * will increase the ref-count and return.
	 *
	 * https://wiki.libsdl.org/SDL_InitSubSystem
	 */
	SDL_InitSubSystem(required);

	window_ = SDL_CreateWindow(title.c_str(), x, y, width, height, wflags);
	renderer_ = Renderer(window_, rindex, rflags);
}

SDL::Window::~Window()
{
	SDL_QuitSubSystem(subsystems_);
}

SDL::Window::Window(const Window& other) : renderer_(other.renderer_)
{
	subsystems_ = other.subsystems_;
	window_ = other.window_;
}

SDL::Window::Window(Window&& other) noexcept : renderer_(other.renderer_)
{
	subsystems_ = other.subsystems_;
	window_ = other.window_;
}

SDL::Window& SDL::Window::operator=(const Window& other)
{
}

SDL::Window& SDL::Window::operator=(Window&& other) noexcept
{
}
