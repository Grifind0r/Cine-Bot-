#pragma once
#include "Libraries.h"
using namespace std;

class Seat
{
private:
	int row;
	int seatNum;
	bool seatStatus;
public:
	Seat()
	{
		this->seatStatus = 0;
	}

	/// Setter

	void setRow(int row)
	{
		this->row = row;
	}

	void setSeatnum(int seatNum)
	{
		this->seatNum = seatNum;
	}

	void setStatus(bool status)
	{
		this->seatStatus = status;
	}

	/// Getters

	bool getStatus()
	{
		return seatStatus;
	}

/// Methods

	void reserveSeat()
	{
		this->seatStatus = 1;
	}
	void cancelSeat()
	{
		this->seatStatus = 0;
	}
};

