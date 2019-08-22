#ifndef DRAMA_H
#define DRAMA_H
#include <string>
#include <iostream>
#include "movie.h"
using namespace std;

class Drama : public Movie {
private:
	// Director, Title
	string movieID;
public:
	// constructor creates moveID for drama 
	// using director and title, then calls
	// parent class to store title, director, release date and stock
	Drama(string title, string director, string release, int stock);

	// destructor empty since no dynamic variables
	~Drama();

	// Director, Title
	string getMovieID() { return movieID; }

};

#endif
