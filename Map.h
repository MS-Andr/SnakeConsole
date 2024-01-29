#pragma once
class Map
{
private:
	const char wall = char(177);
	const char snake = char(8);
	
	enum ObjectMap
	{
		Vaccum = 0,
		Walls = 1,
		Snakes = 2
	};
public:
	int mapp[20][40]{ 0 };
	Map();
	void displayMap();
};

