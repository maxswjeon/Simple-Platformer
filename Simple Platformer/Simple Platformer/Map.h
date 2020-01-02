#pragma once
#include <string>

class Map
{
	// private���� ����� ������
	// ���� ������ ����
	Map();

public:
	// Builder Class ������ ��
	// Builder Class�� 
	class Loader
	{
	public:
		static Map& Load(std::string);
		static Map& Load(const char*);
	};
};

