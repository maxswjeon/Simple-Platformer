#pragma once
#include "Renderer.h"

#include <SDL.h>

#include <string>

namespace SDL
{
	/*
	 * Wrapper Class�� ����� ����
	 * 1. std::shared_ptr �� C++ Pointer ��� �� Destructor �ʿ�
	 * 2. OOP�� ����
	 */
	
	class Window
	{
	protected:
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
		virtual ~Window();

		void Show();
		void Hide();
		
		Window(const Window& other);
		Window(Window&& other) noexcept;
		Window& operator=(const Window& other);
		Window& operator=(Window&& other) noexcept;
	};
}
