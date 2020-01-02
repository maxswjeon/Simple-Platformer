#include "Renderer.h"

SDL::Renderer::Renderer(SDL_Window* window, int index, Uint32 flags)
{
	renderer_ = SDL_CreateRenderer(window, index, flags);
}

SDL::Renderer::Renderer(SDL_Renderer* renderer)
{
	renderer_ = renderer;
}

SDL::Renderer::Renderer()
{
	renderer_ = nullptr;
}

SDL::Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer_);
}

void SDL::Renderer::Render(Object& object)
{
	assert(renderer_ != nullptr);
	object.Render(*this);
}

int SDL::Renderer::DrawLine(Point p1, Point p2) const
{
	assert(renderer_ != nullptr);
	return SDL_RenderDrawLineF(renderer_, p1.X, p1.Y, p2.X, p2.Y);
}

int SDL::Renderer::DrawLine(Line l) const
{
	assert(renderer_ != nullptr);
	return SDL_RenderDrawLineF(renderer_, l.Start.X, l.Start.Y, l.End.X, l.End.Y);
}

int SDL::Renderer::DrawLines(const std::vector<Point>& points) const
{
	assert(renderer_ != nullptr);
	SDL_FPoint* s_points = new SDL_FPoint[points.size()];
	for (int i = 0; i < points.size(); ++i)
	{
		s_points[i].x = points[i].X;
		s_points[i].y = points[i].Y;
	}

	int result = SDL_RenderDrawLinesF(renderer_, s_points, points.size());
	delete[] s_points;
	return result;
}

int SDL::Renderer::DrawLines(Point* points, int count) const
{
	assert(renderer_ != nullptr);
	SDL_FPoint* s_points = new SDL_FPoint[count];
	for (int i = 0; i < count; ++i)
	{
		s_points[i].x = points[i].X;
		s_points[i].y = points[i].Y;
	}

	int result = SDL_RenderDrawLinesF(renderer_, s_points, count);
	delete[] s_points;
	return result;
}

int SDL::Renderer::DrawPoint(Point p) const
{
	assert(renderer_ != nullptr);
	return SDL_RenderDrawPointF(renderer_, p.X, p.Y);
}

int SDL::Renderer::DrawPoints(const std::vector<Point>& points) const
{
	assert(renderer_ != nullptr);
	SDL_FPoint* s_points = new SDL_FPoint[points.size()];
	for (int i = 0; i < points.size(); ++i)
	{
		s_points[i].x = points[i].X;
		s_points[i].y = points[i].Y;
	}

	int result = SDL_RenderDrawPointsF(renderer_, s_points, points.size());
	delete[] s_points;
	return result;
}

int SDL::Renderer::DrawPoints(Point* points, int count) const
{
	assert(renderer_ != nullptr);
	SDL_FPoint* s_points = new SDL_FPoint[count];
	for (int i = 0; i < count; ++i)
	{
		s_points[i].x = points[i].X;
		s_points[i].y = points[i].Y;
	}

	int result = SDL_RenderDrawPointsF(renderer_, s_points, count);
	delete[] s_points;
	return result;
}

int SDL::Renderer::DrawRect(Rect r) const
{
	assert(renderer_ != nullptr);
	SDL_FRect rect;
	rect.x = r.X;
	rect.y = r.Y;
	rect.w = r.Width;
	rect.h = r.Height;
	return SDL_RenderDrawRectF(renderer_, &rect);
}

int SDL::Renderer::DrawRects(const std::vector<Rect>& rects) const
{
	assert(renderer_ != nullptr);
	SDL_FRect* s_rects = new SDL_FRect[rects.size()];
	for (int i = 0; i < rects.size(); ++i)
	{
		s_rects[i].x = rects[i].X;
		s_rects[i].y = rects[i].Y;
		s_rects[i].w = rects[i].Width;
		s_rects[i].h = rects[i].Height;
	}

	int result = SDL_RenderDrawRectsF(renderer_, s_rects, rects.size());
	delete[] s_rects;
	return result;
}

int SDL::Renderer::DrawRects(Rect* rects, int count) const
{
	assert(renderer_ != nullptr);
	SDL_FRect* s_rects = new SDL_FRect[count];
	for (int i = 0; i < count; ++i)
	{
		s_rects[i].x = rects[i].X;
		s_rects[i].y = rects[i].Y;
		s_rects[i].w = rects[i].Width;
		s_rects[i].h = rects[i].Height;
	}

	int result = SDL_RenderDrawRectsF(renderer_, s_rects, count);
	delete[] s_rects;
	return result;
}

int SDL::Renderer::FillRect(Rect r) const
{
	assert(renderer_ != nullptr);
	SDL_FRect rect;
	rect.x = r.X;
	rect.y = r.Y;
	rect.w = r.Width;
	rect.h = r.Height;
	return SDL_RenderFillRectF(renderer_, &rect);
}

int SDL::Renderer::FillRects(const std::vector<Rect>& rects) const
{
	assert(renderer_ != nullptr);
	SDL_FRect* s_rects = new SDL_FRect[rects.size()];
	for (int i = 0; i < rects.size(); ++i)
	{
		s_rects[i].x = rects[i].X;
		s_rects[i].y = rects[i].Y;
		s_rects[i].w = rects[i].Width;
		s_rects[i].h = rects[i].Height;
	}

	int result = SDL_RenderFillRectsF(renderer_, s_rects, rects.size());
	delete[] s_rects;
	return result;
}

int SDL::Renderer::FillRects(Rect* rects, int count) const
{
	assert(renderer_ != nullptr);
	SDL_FRect* s_rects = new SDL_FRect[count];
	for (int i = 0; i < count; ++i)
	{
		s_rects[i].x = rects[i].X;
		s_rects[i].y = rects[i].Y;
		s_rects[i].w = rects[i].Width;
		s_rects[i].h = rects[i].Height;
	}

	int result = SDL_RenderFillRectsF(renderer_, s_rects, count);
	delete[] s_rects;
	return result;
}

int SDL::Renderer::SetColor(Uint32 color) const
{
	return SetColor((color >> 24) & 0xFF, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
}

int SDL::Renderer::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const
{
	return SDL_SetRenderDrawColor(renderer_, r, g, b, a);
}
