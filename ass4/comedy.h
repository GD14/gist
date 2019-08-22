#ifndef COMEDY_H
#define COMEDY_H
#include <string>
#include <iostream>
#include "movie.h"
using namespace std;

class Comedy : public Movie {
private:
	// Title, Year
	string movieID;
public:
	// constructor creates moveID for comedy 
	// using title and year, then calls
	// parent class to store title, director, release date and stock
	Comedy(string title, string director, string release, int stock);

	// destructor empty since no dynamic variables
	~Comedy();

	// Title, Year
	string getMovieID() { return movieID; }

};

#endif
