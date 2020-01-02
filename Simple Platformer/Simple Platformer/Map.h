#pragma once
#include <string>

class Map
{
	// private으로 선언된 생성자
	// 직접 생성을 막음
	Map();

public:
	// Builder Class 역할을 함
	// Builder Class는 
	class Loader
	{
	public:
		static Map& Load(std::string);
		static Map& Load(const char*);
	};
};

