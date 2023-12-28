#pragma once
#define spaceX 20  // поле 20 на 40 клеток
#define spaceY 40

const int a = spaceX + 2;  // настоящее поле
const int b = spaceY + 2;

class Life
{

	int space[a][b]; // массив для хранения информации поля и клеток

	int checkRule(int i, int j); // проверка правил
	void printSpace(); // вывод поля
	void generateLife(); // генерация

public:
	Life(); // конструктор
	~Life(); // деконструктор

	void runLife(); // функция запуска

};

