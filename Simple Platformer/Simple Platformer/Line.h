#pragma once
#include "Point.h"

namespace SDL {
	class Line
	{
	public:
		Point Start;
		Point End;

		Line(Point, Point);
	};
}

