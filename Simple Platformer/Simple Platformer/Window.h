#pragma once
#include "Renderer.h"

#include <SDL.h>

#include <string>

namespace SDL
{
	/*
	 * Wrapper Class를 만드는 이유
	 * 1. std::shared_ptr 등 C++ Pointer 사용 시 Destructor 필요
	 * 2. OOP가 편함
	 */
	
	class Window
	{
		SDL_Window* window_;

		Renderer renderer_;
		
		Uint32 subsystems_;
	public:
		Window(const char* title,
			int x,
			int y,
			int width, 
			int height, 
			Uint32 wflags,
			int rindex,
			Uint32 rflags, 
			Uint32 required = SDL_INIT_VIDEO);

		Window(std::string title,
			int x,
			int y,
			int width,
			int height,
			Uint32 wflags,
			int rindex,
			Uint32 rflags,
			Uint32 required = SDL_INIT_VIDEO);
		~Window();

		void Show();
		void Hide();
		
		Window(const Window& other);
		Window(Window&& other) noexcept;
		Window& operator=(const Window& other);
		Window& operator=(Window&& other) noexcept;
	};
}
