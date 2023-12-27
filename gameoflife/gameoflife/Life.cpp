#include "Life.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Life::Life()
{
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            space[i][j] = 0;
}

Life::~Life()
{
}

int Life::checkRule(int i, int j)
{
    return 0;
}

void Life::printSpace()
{
    for (int i = 1; i < a - 1; i++) {
        for (int j = 1; j < b - 1; j++)
            if (space[i][j] == 1)
                cout << "X";
            else
                cout << " ";
        cout << endl;
    }
}

void Life::generateLife()
{
    for (int i = 1; i < a - 1; i++)
        for (int j = 1; j < b - 1; j++)
            space[i][j] = rand() % 2;
}

void Life::runLife()
{
    generateLife();
    printSpace();
}
