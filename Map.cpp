#include "Map.h"
#include <iostream>

using namespace std;

Map::Map()
{
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 40; ++j) {
			if (i == 0 || j == 0 || i == 19 || j == 39) {
				mapp[i][j] = Walls;
			}
		}
	}
}

void Map::displayMap()
{
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 40; ++j) {
			switch (mapp[i][j])
			{
			case Snakes:
				cout << snake;
				break;
			case Walls:
				cout << wall;
				break;
			case Vaccum:
				cout << " ";
				break;
			}
		}
		cout << endl;
	}
}

