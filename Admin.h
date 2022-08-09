#pragma once
#include "Libraries.h"

using namespace std;

class Admin
{
private:
	string username;
	string password;
public:
	Admin()  /// Only default constructor
	{
		this->username = "cinebot";
		this->password = "123";
	}

	/// Setters
	void setUsername(string username)
	{
		this->username = username;
	}

	void setPassword(string password)
	{
		this->password = password;
	}

	/// Getters
	string getPassword()
	{
		return password;
	}

	string getUsername()
	{
		return username;
	}

	/// Functions
	bool login()
	{
		string password;
		string username;
		cout << "======= ADMIN LOGIN ======\n" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "==== Attempt " << i + 1 << " ====" << endl;
			cout << "Username -> ";
			cin >> username;
			cout << "Password -> ";
			cin >> password;
			if (this->username == username && this->password == password)
			{
				cout << "\nLogged in Successfully!\n" << endl;
				system("CLS");
				return 1;
			}
			else if (this->username == username && this->password != password)
			{
				cout << "\nIncorrect password\n" << endl;
			}
			else if (this->password == password && this->username != username)
			{
				cout << "\nIncorrect username\n" << endl;
			}
			else
			{
				cout << "\nBoth are incorrect\n" << endl;
			}
		}
		return 0;
	}

	void changeCredentials()
	{
		cout << "===== PASSWORD CHANGE =====\n" << endl;
		string currentpassword;
		cout << "Enter current password -> ";
		cin >> currentpassword;
		if (this->password == currentpassword)
		{
			string temppass;
			do
			{
				cout << "Enter new password -> ";
				cin >> temppass;
				{
					if (this->password == temppass)
					{
						cout << "\nCan not use the old password\nTRY AGAIN!!!!\n" << endl;
					}
				}
			} while (this->password == temppass);
			this->password = temppass;

			cout << "\nPassword changed successfully"<< endl;
			system("CLS");
		}
	}

	void addMovie()
	{
		string name;
		string genre;
		int watchTime;
		char movieIndustry;
		char threed, fourk;
		bool three_d = 0;
		bool four_k = 0;
		cout << "===== MOVIE INPUT =====" << endl;
		cout << "Name -> ";
		cin >> name;
		cout << "Genre -> ";
		cin >> genre;
		cout << "Duration (in minutes) -> ";
		cin >> watchTime;
		cout << "Movie industry (H,B) -> ";
		cin >> movieIndustry;
		cout << "3D (y,n) -> ";
		cin >> threed;
		cout << "4K (y/n) ->";
		cin >> fourk;
		if (threed == 'y')
		{
			three_d = 1;
		}
		if (fourk == 'y')
		{
			four_k = 1;
		}
		fstream movies;
		movies.open("Movies.txt", ios::app);
		movies <<rand() % 899 + 100 <<" " << name << " " << genre << " " << watchTime << " " << movieIndustry << " " << three_d << " " << four_k << endl;
		cout << "\nMovie added successfully\n" << endl;
		movies.close();
	}

	void displayMovies()
	{
		string name;
		string genre;
		int watchTime;
		char movieIndustry;
		bool three_d = 0;
		bool four_k = 0;
		int id;
		fstream movies;
		movies.open("Movies.txt", ios::in);
		if (movies.is_open())
		{
			while (movies >> id >>name >> genre >> watchTime >> movieIndustry >> three_d >> four_k)
			{
				cout << "==========" << endl;
				cout << id<<" " << name << " " << genre << " " << watchTime << " " << movieIndustry << " " << three_d << " " << four_k << endl;
			}
		}
		movies.close();
	}

	void deleteMovie()
	{
		string line;
		int id, delID;

		cout << "\nWhich ID would you like to delete --> ";
		if (!(cin >> delID))
			return;

		ifstream UserData("Movies.txt");
		ofstream NewUserData("tempMovies.txt");

		while (getline(UserData, line))
		{
			if ((UserData >> id) && (id == delID))
				NewUserData << line << endl;
		}

		NewUserData.close();
		UserData.close();

		remove("Movies.txt");
		rename("tempMovies.txt", "Movies.txt");
	}

	int Menu(bool check)
	{
		bool stillWannaGo = true;
		if (check)
		{
			int chose;
			cout << "===== Admin Menu =====" << endl;
			cout << "1. CHANGE PASSWORD " << endl;
			cout << "2. ADD MOVIE" << endl;
			cout << "3. DISPLAY MOVIES" << endl;
			cout << "4. DELETE MOVIE" << endl;
			cout << "5. EXIT" << endl;
			cout << endl;
			cout << "Select (1-5) -> ";
			cin >> chose;
			system("CLS");
			return chose;
		}
	}
};