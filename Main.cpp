#include <iostream>
#include <vector>
#include <string>
using namespace std;


#include "Player.h"

int main()
{
	int x, y, n, score1 = 0, score2 = 0, winner = 0;
	Player one("tomo");
	Player two("ante");
	one.setMyBoats();
	two.setMyBoats();

	while (!winner)
	{
		cout << "which coordinates you want to shoot  " << one.getname() << "?" << endl;
		cin >> x;
		cin >> y;
		one.shoot(x, y);
		n=two.checkBoats(x, y);
		if (n == 1)
		{
			score1++;
			one.setscore(score1);
		}
		cout << "which coordinates you want to shoot  " << two.getname() << "?" << endl;
		cin >> x;
		cin >> y;
		two.shoot(x, y);
		n = one.checkBoats(x, y);
		if (n == 1)
		{
			score2++;
			two.setscore(score2);
		}

		if (one.getscore() == 16)
		{
			winner =1;
			cout << "VICTORY! Player: " << one.getname() << "is a winner! Game over for:" << two.getname() << "." << endl;
		}
		if (two.getscore() == 16)
		{
			winner = 1;
			cout << "VICTORY! Player: " << two.getname() << "is a winner! Game over for:" << one.getname() << "." << endl;
		}
		one.showMyBoards();
		two.showMyBoards();
	}
	

	
	return 0;
}