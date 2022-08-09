#pragma once
#include "Libraries.h"
#include "Seats.h"
#include "Movie.h"
using namespace std;

class Hall :protected Movie
{
private:
	int hallID;
	Seat seats[4][10];
public:
	Hall()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				seats[i][j].setRow(i);
				seats[i][j].setSeatnum(j);
				seats[i][j].setStatus(0);
			}
		}
		int temp = rand() % 89 + 10;
		this->hallID = temp;
	}

/// Getter
	int getHallID()
	{
		return hallID;
	}

	void bookseat(int numseats)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (seats[i][j].getStatus())
				{
					cout << " [R]  ";
				}
				else
				{
					cout << " [" << i << j << "] ";
				}
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < numseats; i++)
		{
			again:
			int tempseat,c,r;
			cout << "Seat " << i + 1 << " -> ";
			cin >> tempseat;
			r = tempseat / 10;
			c = tempseat % 10;
			if (seats[r][c].getStatus())
			{
				cout << "This seat is already reserved\nSelect another seat\n" << endl;
				goto again;
			}
			else
			{
				seats[r][c].reserveSeat();
			}
		}
	}

};

