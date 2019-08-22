#ifndef CLASSIC_H
#define CLASSIC_H
#include <iostream>
#include <string>
#include "movie.h"

using namespace std;

class Classic : public Movie {
private:
	// Release Date, Major Actor
	string movieID;

public:
	// constructor creates moveID for classic 
	// using release date and title, then calls
	// parent class to store title, director, 
	// release date, actor and stock
	Classic(string title, string director, 
		string mainActor, string release, int stock);

	// destructor empty since no dynamic variables
	~Classic();

	// Release Date, Major Actor
	string getMovieID() { return movieID; }

};

#endif
