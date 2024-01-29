#include <iostream>
#include "SnakeConsole.h"
#include "conio.h"
using namespace std;

// Игровые обьекты
enum gameObject
{
	blank = 0,
	wall = 1,
	snake = 2,
	apple = 3
};

//положение змейки "начальные"
	int xPozSnake = 5;
	int yPozSnake = 5;

//Наравление движение змейки
int way;
enum waySnake 
{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

bool dSnake = false;

// начальное положение яблока
int xPozApple = 15;
int yPozApple = 15;

//счет съеденных яблок;
int score = 0;

//обьявление карты
int Map[20][50]{ 0 };

//внутренник границы карты
enum BordersMap
{
	xStart = 1,
	yStart = 1,
	xEnd = 49,
	yEnd = 19,
};

//функции
void fillMap();
void moveSnake();
void displayMap();
void genApple();
bool deadSnake();

int main()
{
	srand(time(0));

	fillMap();//заполнение карты
	displayMap();//вывод начальной карты на экран

	while (true) {
		moveSnake();
		dSnake = deadSnake();
		if (dSnake) {
			break;
		}
		genApple();
		system("cls");
		displayMap();
	}
	system("cls");
	cout << "DEAD \n" << "Score: " << score<< endl;
	cout << "yPozSnake: " << yPozSnake << "  xPozSnake: " << xPozSnake << endl;
	cout << "yPozApple: " << yPozApple << "  xPozApple: " << xPozApple << endl;

}

//заполнение карты начальными обьектами
void fillMap(){
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 50; ++j) {
			if (i == 0 || j == 0 || i == 19 || j == 49) {
				Map[i][j] = wall;
			}
			else if (j == xPozSnake && i== yPozSnake) {
				Map[i][j] = snake;
			}else if (j == xPozApple && i == yPozApple) {
				Map[i][j] = apple;
			}
			else {
				Map[i][j] = blank;
			}
		}
	}
}

//перемещение змейки по карте
void moveSnake() {
	
	if (_kbhit()) { //обработка нажатия
		switch (_getch())
		{
		case 'w':
			way = UP;
			break;
		case 'a':
			way = LEFT;
			break;
		case 's':
			way = DOWN;
			break;
		case 'd':
			way = RIGHT;
			break;
		}
	}
	Map[yPozSnake][xPozSnake] = blank;
	switch (way)
	{
	case UP:
		--yPozSnake;
		break;
	case LEFT:
		--xPozSnake;
		break;
	case DOWN:
		++yPozSnake;
		break;
	case RIGHT:
		++xPozSnake;
		break;
	}
	Map[yPozSnake][xPozSnake] = snake;
}

//отображение карты
void displayMap(){
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 50; ++j) {
			switch (Map[i][j])
			{
			case blank:
				cout << " ";
				break;
			case wall:
				cout << char(177);
				break;
			case snake:
				cout << char(2);
				break;
			case apple:
				cout << char(48);
				break;
			}
		}
		cout << endl;
	}
	cout << "Score: " << score;
}

//генерация яблок
void genApple() {
	if (Map[yPozApple][xPozApple] == blank || Map[yPozApple][xPozApple]== snake) {
		++score;

		xPozApple = rand() % (xEnd - xStart+2) + xStart;
		yPozApple = rand() % (yEnd - yStart+2) + yStart;

		Map[yPozApple][xPozApple] = apple;
	}
}

//смерть змейки
bool deadSnake()
{
	if (yPozSnake == 19 || yPozSnake == 0 || xPozSnake == 49 || xPozSnake == 0) {
		return true;
	}
	return false;
}
