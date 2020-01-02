#include "Point.h"

SDL::Point::Point(float x, float y)
{
	X = x;
	Y = y;
}

SDL::Point::Point(const Point& other)
{
	X = other.X;
	Y = other.Y;
}

SDL::Point::Point(Point&& other) noexcept
{
	X = other.X;
	Y = other.Y;	
}

SDL::Point& SDL::Point::operator=(const Point& other)
{
	X = other.X;
	Y = other.Y;
	return *this;
}

SDL::Point& SDL::Point::operator=(Point&& other) noexcept
{
	X = other.X;
	Y = other.Y;
	return *this;
}
