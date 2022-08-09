#pragma once
#include "Libraries.h"
using namespace std;

class Movie
{
private:
	string name;
	string genre;
	int watchTime;
	char movieIndustry;
	bool three_d;
	bool four_k;
	int id;
public:
	Movie() {}
	Movie(string name, string genre, int watchTime, char movieIndustry, bool three_d, bool four_k)
	{
		this->name = name;
		this->genre = genre;
		this->watchTime = watchTime;
		this->movieIndustry = movieIndustry;
		this->three_d = three_d;
		this->four_k = four_k;
	}

/// Setters
	void setMoviename(string name)
	{
		this->name = name;
	}

	void setGenre(string genre)
	{
		this->genre = genre;
	}

	void setWatchtime(int watchtime)
	{
		this->watchTime = watchtime;
	}

	void setMovieindustry(char movieIndustry)
	{
		this->movieIndustry = movieIndustry;
	}

	void set3d(bool threeD)
	{
		this->three_d = threeD;
	}

	void set4k(bool fourK)
	{
		this->four_k = fourK;
	}

	void setID(int id)
	{
		this->id = id;
	}

/// Getters
	string getName()
	{
		return name;
	}

	int getID()
	{
		return id;
	}

	string getGenre()
	{
		return genre;
	}

	int getWT() //// WT = watch time
	{
		return watchTime;
	}

	char getMI() //// MI = movie industry
	{
		return movieIndustry;
	}

	bool get3d()
	{
		return three_d;
	}

	bool get4k()
	{
		return four_k;
	}
};

