#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Player {
	string name;
	int height;
	int width;
	int points;
	char** myBoard;
	char** targetBoard;
public:
	Player(string);
	~Player();
	void showMyBoards();
	void setMyBoats();
	void shoot(int&,int&);
	int checkBoats(int, int);
	void setscore(int);
	string getname();
	int getscore();


};