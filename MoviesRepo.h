#pragma once
#include "Movie.h"
#include "Libraries.h"
using namespace std;

class MoviesRepo
{
private:
	int numMovies;
	Movie *movies;
public:
	MoviesRepo()
	{
		string line;   // To read each line from code
		int count = 0;    // Variable to keep count of each line
		ifstream mFile("Movies.txt");
		if (mFile.is_open())
		{
			while (mFile.peek() != EOF)
			{
				getline(mFile, line);
				count++;
			}
			mFile.close();
			this->numMovies = count;
			movies = new Movie[count];
		}
	}
		int totalMovies()
		{
			return numMovies;
		}

		void fillMovies()
		{
			for (int i = 0; i < numMovies; i++)
			{
				int id;
				string name;
				string genre;
				int watchTime;
				char movieIndustry;
				bool three_d = 0;
				bool four_k = 0;
				fstream Filemovies;
				Filemovies.open("Movies.txt", ios::in);
				if (Filemovies.is_open())
				{
					while (Filemovies >>id >>name >> genre >> watchTime >> movieIndustry >> three_d >> four_k)
					{
						movies[i].setID(id);
						movies[i].setMoviename(name);
						movies[i].setGenre(genre);
						movies[i].setWatchtime(watchTime);
						movies[i].setMovieindustry(movieIndustry);
						movies[i].set3d(three_d);
						movies[i].set4k(four_k);
						i++;
					}
				}
				Filemovies.close();
			}
		}

		void showMovies()
		{
			for (int i = 0; i < numMovies; i++)
			{
				cout <<movies[i].getID() << " -> " << movies[i].getName() << endl;
			}
			cout << endl;
			cout << "Press Enter to go back to previous menu";
		}

		void showdetails()
		{
			showMovies();
			int id;
			cout << "Enter movie id -> ";
			cin >> id;
			system("CLS");
			cout << "===== DETAILS =====" << endl;
			for (int i = 0; i < numMovies; i++)
			{
				if (movies[i].getID() == id)
				{
					int wt = movies[i].getWT();
					
					bool threed = movies[i].get3d();
					bool fourk = movies[i].get4k();
					cout << "Name: " << movies[i].getName() << endl;;
					cout << "Genre: " << movies[i].getGenre() << endl;;
					cout << "Duration: " << wt/60  << " hours and " << wt%60  << " minutes" << endl;
					cout << "3D: ";
					if (threed)
					{
						cout << "Yes"  << endl;;
					}
					cout << "4K: ";
					if (fourk)
						cout << "Yes" << endl;
				}
			}
			cout << endl<<"Press Enter to go back to previous menu" << endl;
		}

		Movie setmovie(int id)
		{
			for (int i = 0; i < numMovies; i++)
			{
				if (movies[i].getID() == id)
				{
					return movies[i];
				}
			}
		}
};

