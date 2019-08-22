#include <iostream>
#include "drama.h"

// constructor creates moveID for drama using director and title, then calls
// parent class to store title, director, release date and stock
Drama::Drama(string title, string director, string release, int stock)
	: Movie(title, director, "", release, stock) {
	movieID = director + ", " + title;
}

// destructor empty since no dynamic variables
Drama::~Drama() {}