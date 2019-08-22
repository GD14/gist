#include <iostream>
#include "classic.h"

// constructor creates moveID for classic using
// release date and title, then calls
// parent class to store title, director, release date, actor and stock
Classic::Classic(string title, string director, 
	string mainActor, string release, int stock) 
	: Movie(title,director,mainActor, release, stock) {
	movieID = release + ", " + mainActor;
}

// destructor empty since no dynamic variables
Classic::~Classic() {}
