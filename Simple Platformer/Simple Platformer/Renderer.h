#pragma once
#include "Object.h"
#include "Point.h"
#include "Line.h"
#include "Rect.h"

#include <cassert>
#include <vector>

#include <SDL.h>

namespace SDL {
	class Renderer
	{
		SDL_Renderer* renderer_;

	public:
		Renderer(SDL_Window* window, int index = -1, Uint32 flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		Renderer(SDL_Renderer* renderer);
		Renderer();
		~Renderer();

		int DrawLine(Point, Point) const;
		int DrawLine(Line) const;
		int DrawLines(const std::vector<Point>&) const;
		int DrawLines(Point*, int) const;
		int DrawPoint(Point) const;
		int DrawPoints(const std::vector<Point>&) const;
		int DrawPoints(Point*, int) const;
		int DrawRect(Rect) const;
		int DrawRects(const std::vector<Rect>&) const;
		int DrawRects(Rect*, int) const;
		int FillRect(Rect) const;
		int FillRects(const std::vector<Rect>&) const;
		int FillRects(Rect*, int) const;
		int SetColor(Uint32) const;
		int SetColor(Uint8, Uint8, Uint8, Uint8) const;
		
		void Render(Object& object);
	};
}
