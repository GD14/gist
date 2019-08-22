#include <iostream>
#include <string>
#include "movie.h"

// constructor for the movie object
// initialize movie object according to its type
//mainActor will be empty unless movie type is classic
Movie::Movie(string title1, string director1, 
	string majorActor1, string release1, int stock1){
	title = title1;

	director = director1;

	release = release1;

	stock = stock1;

	majorActor = majorActor1;
}

// destructor empty since no dynamic variables
Movie::~Movie(){}

// getting the title of the movie
std::string Movie::getTitle(){ return title; }


// return movie title as a string
// getting the name of the director
std::string  Movie::getDirector() { return director; }


// getting the release date of the movie, month if available, then movie
// returns int value of release date
string  Movie::getRelease() { return release; }

// gets name of major actor
string Movie::getActor() { return majorActor; }

// gets stock left of the movie
string Movie::getStock() { return to_string(stock); }

//-1 stock of the movie
bool  Movie::borrowAMovie(){
	if (stock > 0) {  // only borrow if there is still stock left
		--stock;
		return true;
	}
	else return false;
}

//+1 stock of the movie
void  Movie::returnAMovie(){
	++stock;
}