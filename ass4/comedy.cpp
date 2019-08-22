#include <iostream>
#include "comedy.h"

// constructor 
Comedy::Comedy(string title, string director, string release, int stock) :
	Movie(title, director,"", release, stock) {
	movieID = title + ", " + release;
}

// destructor empty since no dynamic variables
Comedy::~Comedy() {}
