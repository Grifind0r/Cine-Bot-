#pragma once
#include "Libraries.h"
#include "Customer.h"
using namespace std;

class Customerrepo
{
private:
	int numCustomers;
	Customer* c;
public:
	Customerrepo()
	{
		string line;   // To read each line from code
		int count = 0;    // Variable to keep count of each line
		ifstream mFile("customers.txt");
		if (mFile.is_open())
		{
			while (mFile.peek() != EOF)
			{
				getline(mFile, line);
				count++;
			}
			mFile.close();
			this->numCustomers = count;
			c = new Customer[numCustomers];
		}
	}

	/// 
	void fill()
	{
		for (size_t i = 0; i < numCustomers; i++)
		{
			int id;
			string name;
			string phoneNum;
			string username;
			string password;
			int count;
			fstream customers;
			customers.open("customers.txt", ios::in);
			if (customers.is_open())
			{
				while (customers >> id >> name >> phoneNum >> username >> password >> count)
				{
					c[i].setID(id);
					c[i].setName(name);
					c[i].setPhoneNumber(phoneNum);
					c[i].setUsername(username);
					c[i].setPassword(password);
					c[i].setMovieCount(count);
					i++;
				}
			}
			customers.close();
		}
	}

	void show()
	{
		for (int i = 0; i < numCustomers; i++)
		{
			cout << c[i].getID() << ": " << c[i].getName() << endl;
		}
	}

	bool login(string username, string password)
	{
		system("CLS");

		for (int i = 0; i < numCustomers; i++)
		{
			if (c[i].getUsername() == username && c[i].getPassword() == password)
			{
				return 1;
			}
		}
		return 0;
	}

	int getMoviecount(string username)
	{
		for (int i = 0; i < numCustomers; i++)
		{
			if (c[i].getUsername() == username)
			{
				return c[i].getMovieCount();
			}
		}
	}

	Customer setCustomer(string username, string password)
	{
		for (int i = 0; i < numCustomers; i++)
		{
			if (c[i].getUsername() == username && c[i].getPassword() == password)
			{
				return c[i];
			}
		}
	}

	void savedata()
	{
		fstream newdata;
		newdata.open("newdata.txt", ios::out);
		for (int i = 0; i < numCustomers; i++)
		{
			newdata << c[i].getID() << " " << c[i].getName() << " " << c[i].getPhoneNumber() << " " << c[i].getUsername() << " " << c[i].getPassword() << " " << c[i].getMovieCount() << endl;
		}
		newdata.close();
		remove("customers.txt");
		rename("newdata.txt", "customers.txt");
	}
	
	void customerIncrease(string username)
	{
		int newcount;
		for (int i = 0; i < numCustomers; i++)
		{
			if (c[i].getUsername() == username)
			{
				newcount = c[i].getMovieCount() + 1;
				c[i].setMovieCount(newcount);
			}
		}
	}
};

