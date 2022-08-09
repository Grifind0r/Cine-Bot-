#pragma once
#include "Libraries.h"
using namespace std;

class Customer
{

private:
	string name;
	string phoneNumber;
	int movieCount;
	int customerID;
	string username;
	string password;
public:
/// Constructors
	Customer() {}
	Customer(string name, string phoneNumber, int movieCount)
	{
		this->name = name;
		this->phoneNumber = phoneNumber;
		this->movieCount = movieCount;
	}

/// Setters
	void setName(string name)
	{
		this->name = name;
	}

	void setPhoneNumber(string phoneNumber)
	{
		this->phoneNumber = phoneNumber;
	}

	void setMovieCount(int movieCount)
	{
		this->movieCount = movieCount;
	}

	void increment()
	{
		this->movieCount += 1;
	}

	void setUsername(string username)
	{
		this->username = username;
	}

	void setPassword(string password)
	{
		this->password = password; 
	}

	void setID(int id)
	{
		this->customerID = id;
	}

/// Getters
	string getName() { return name; }
	string getPhoneNumber() { return phoneNumber; }
	int getMovieCount() { return movieCount; }
	int getID() { return customerID; }
	string getUsername() { return username; }
	string getPassword() { return password; }

/// MEMBER FUCTIONS
	int customerLoginMenu()
	{
		system("CLS");
		int option;
		cout << "===== CUSTOMER LOGIN =====" << endl;
		cout << "1. SIGN IN" << endl;
		cout << "2. REGISTER" << endl;
		cout << "-->";
		cin >> option;
		return option;
	}

	bool customerLogin()
	{
		string username;
		string password;
		
	}
	
	void registerCustomer()
	{
		system("CLS");
		//int id;
		string username;
		string password;
		string name;
		string phoneNumber;
		cout << "===== REGISTRATION =====" << endl;
		cout << "Enter name -> ";
		cin >> name;
		cout << "Enter phone number -> ";
		cin >> phoneNumber;
		cout << "Enter username -> ";
		cin >> username;
		cout << "Enter password -> ";
		cin >> password;
		fstream customers;
		customers.open("customers.txt", ios::app);
		customers <<rand() % 899 +100 << " " << name << " " << phoneNumber <<" " << username<<" "<<password<<" " << 0 << endl;
		cout << "\nRegistered successfully\n" << endl;
		customers.close();
	}

	int customerMenu()
	{
		int chose;
		cout << "===== CUSTOMER MENU =====" << endl;
		cout << "1. VIEW MOVIES" << endl;
		cout << "2. SEE MOVIE DETAILS" << endl;
		cout << "3. BOOK SEAT" << endl;
		cout << "4. SEE TICKET DETAILS" << endl;
		cout << "5. EXIT" << endl;
		cout << "--> ";
		cin >> chose;
		return chose;
	}

	void incrementMovieCount()
	{
		int id;
		string name;
		string phoneNum;
		string username;
		string password;
		int count;
		string line;
		ifstream ini_file{ "customers.txt" };
		fstream out_file{ "copy.txt" };
		if (ini_file && out_file) {
			while (ini_file >> id >> name >> phoneNum >> username >> password >> count) {
				if (id == this-> getID())
				{
					out_file<< id << " " << name << " " << phoneNum << " " << username << " " << password << " " << (count+1) << endl;
				}
				else
				{
					getline(ini_file, line);
					out_file << line << "\n";
				}
			}
		}
		ini_file.close();
		out_file.close();
	}
	
};

