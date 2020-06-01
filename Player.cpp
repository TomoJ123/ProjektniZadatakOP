#include "Player.h"

Player::Player(string name)
{
	this->name = name;
	height = 10;
	width = 10;
	points = 0;
	char arr[] = "0123456789";
	myBoard = new char* [height];
	targetBoard = new char* [height];
	for (int i = 0; i < height; ++i)
	{
		myBoard[i] = new char[width];
		targetBoard[i] = new char[width];
	}
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (i == 0)
			{
				myBoard[i][j] = arr[j];
				targetBoard[i][j] = arr[j];
			}
			if (i != 0)
			{
				if (j == 0)
				{
					myBoard[i][j] = arr[i];
					targetBoard[i][j] = arr[i];
				}
				else if (j == width - 1 || (i==height-1 && j>0))
				{
					myBoard[i][j] = '*';
					targetBoard[i][j] = '*';
				}
				else
				{
					myBoard[i][j] = ' ';
					targetBoard[i][j] = ' ';
				}
			}
		}
	}
}



Player::~Player()
{
	for (int i = 0; i < 10; ++i) {
		delete[] myBoard[i];
		delete[] targetBoard[i];
	}
	cout << "destructor called!";
	delete[] myBoard;
	delete[] targetBoard;
}

void Player::showMyBoards()
{
	cout << "Tvoji brodovi!" << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << myBoard[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "ploca za ciljanje!" << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << targetBoard[i][j] << " ";
		}
		cout << endl;
	}

}

void Player::setMyBoats()
{
	int counter = 0;
	int count = 0;
	int boats = 0;
	int check = 0;
	int ycheck = 0;
	int istrue = 1;
	int x, y;
	char arr[] = { '<','-','-', '-', '>', '<', '-', '-', '>', '<', '-', '-', '>', '<', '-', '>' };
	while (true)
	{
		while (true) {
			if (boats == 4)
			{
				break;
			}
			cout << "upisite koordinatu gdje zelite staviti svoj brod." << endl;
			cin >> x;
			cin >> y;
			if (x < height && x>0 && y < width && y>0)
			{
				break;
			}
		}

		if (boats == 0 )
		{
			if (y + 4 >= width-1)
			{
				cout << "tu ga ne mozete staviti,izaslo bi iz boarda " << endl;
			}
			else
			{
				while (count != 5) {
					myBoard[x][y] = arr[counter];
					counter++;
					count++;
					y++; 
 				}
				boats++;
			}
		}
		else if (boats == 1 || boats==2)
		{
			if (y + 3 >= width-1)
			{
				cout << "tu ga ne mozete staviti,izaslo bi iz boarda " << endl;
			}
			else
			{
				istrue = 1;
				check = 0;
				ycheck = y;
				while (check != 4)
				{
					if (myBoard[x][ycheck] != ' ')
					{
						cout << "pregazili bi jedan od brodova,unesite drugu koordinatu!" << endl;
						istrue = 0;
					}
					ycheck++;
					check++;
				}
				if (istrue == 1) {
					count = 0;
					while (count != 4) {
						myBoard[x][y] = arr[counter];
						counter++;
						count++;
						y++; 
					}
					boats++;
				}
				
			}
		}
		else if (boats == 3 )
		{
			if (y + 2 >= width-1)
			{
				cout << "tu ga ne mozete staviti,izaslo bi iz boarda " << endl;
			}
			else
			{
				istrue = 1;
				check = 0;
				ycheck = y;
				while (check != 3)
				{
					if (myBoard[x][ycheck] != ' ')
					{
						cout << "pregazili bi jedan od brodova,unesite drugu koordinatu!" << endl;
						istrue = 0;
					}
					ycheck++;
					check++;
				}
				if (istrue == 1) {
					count = 0;
					while (count != 3) {
						myBoard[x][y] = arr[counter];
						counter++;
						count++;
						y++; 
					}
					boats++;
				}
			}
		}
		else
		{
			cout << "postavili ste sve brodove!" << endl;
			break;
		}

	}
}

void Player::shoot(int x,int y)
{
	int istrue = 0;
	while (istrue != 1) {
		if ((x < height && x>0 && y < width && y>0) && targetBoard[x][y] == ' ')
		{
			targetBoard[x][y] = 'x';
			istrue = 1;
		}
		else
		{
			cout << "you already shoot there or its out of the board,change coordinates!" << endl;
			cin >> x;
			cin >> y;
		}
	}
	
	


}

int Player::checkBoats(int x, int y)
{
	if (myBoard[x][y] != ' ')
	{
		myBoard[x][y] = 'x';
		cout << "you shoot the part of the boat!" << endl;
		return 1;
	}
	myBoard[x][y] = 'x';
	cout << "missed" << endl;
	return 0;
}

void Player::setscore(int n)
{
	this->points = n;
}


string Player::getname()
{
	return this->name;
}

int Player::getscore()
{
	return this->points;
}