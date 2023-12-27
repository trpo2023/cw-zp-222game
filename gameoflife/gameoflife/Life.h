#pragma once
#define spaceX 10
#define spaceY 10

const int a = spaceX + 2;
const int b = spaceY + 2;

class Life
{

	int space[a][b];

	int checkRule(int i, int j);
	void printSpace();
	void generateLife();

public:
	Life();
	~Life();

	void runLife();

};

