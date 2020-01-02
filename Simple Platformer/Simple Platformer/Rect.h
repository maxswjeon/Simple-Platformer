#pragma once
#include "Point.h"

namespace SDL {
	class Rect
	{
	public:
		float Width;
		float Height;
		float X;
		float Y;

		Rect(Point, Point);
		Rect(float, float, float, float);
	};
}

