#include "Life.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <Windows.h>
using namespace std;

Life::Life()  // конструктор
{
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            space[i][j] = 0;
}

Life::~Life() // деструктор
{
}

int Life::checkRule(int i, int j) // проверяет правила игры для указанной клетки с координатами (i, j).
{
    int lifeCount = 0; // количество живых клеток
    for (int k = i - 1; k < i + 2; k++)
        for (int n = j - 1; n < j + 2; n++)
            lifeCount = lifeCount + space[k][n];
    lifeCount = lifeCount - space[i][j];

    if (lifeCount == 3 && space[i][j] == 0) // если у клетки есть 3 живых соседа и клетка сама мертва она оживает
        space[i][j] = 1;
    if ((lifeCount < 2 || lifeCount > 3) && space[i][j] == 1) // если у клетки меньше 2 или больше 3 живых соседей и клетка сама жива она умирает
        space[i][j] = 0;

    return space[i][j];
}

void Life::printSpace() // вывод поля
{
    for (int i = 1; i < a - 1; i++) {
        for (int j = 1; j < b - 1; j++)
            if (space[i][j] == 1)
                cout << "O";  // обозначает живую клетку
            else
                cout << " "; // обозначает мертвую клетку
        cout << endl;
    }
}

void Life::generateLife() // заполняет поле случайными значениями (0 или 1) это определяет, будет ли клетка мертвой или живой в начале игры
{
    for (int i = 1; i < a - 1; i++)
        for (int j = 1; j < b - 1; j++)
            space[i][j] = rand() % 2; 
}

void Life::runLife() // генерирует начальное состояние игрового поля выводит его на экран и затем в каждой итерации обновляет состояние клеток
{
    generateLife();
    printSpace();
    Sleep(1000); // задержка перед началом циклов
    system("cls");
    while (1) {
        for (int i = 1; i < a - 1; i++)
            for (int j = 1; j < b - 1; j++)
                checkRule(i,j);
        printSpace();
        Sleep(100); // скорость циклов
        system("cls");
    }
}
