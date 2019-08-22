#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <iostream>
#include <map>
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
using namespace std;

class Inventory {
private:
	//This map will be used to store Comedy movies
	//they will be sorted by Title and then year released 
	map<string, Comedy*, less<string>> comedies;

	//This map will be used to store Drama movies 
	map<string, Drama*, less<string>> dramas;

	//This map will be used to store Classic movies 
	map<string, Classic*, less<string>> classics;

	// map used to sort classic movies for printing
	// using movie Id will not sort properly
	map<pair<pair<int,int>,string>, Classic*,
		less<pair<pair<int, int>, string>>> classicsPrint;

public:
	//no args constructor
	Inventory();

	// destructor goes through all maps and deletes the movies
	// stored in each category
	~Inventory();

	// takes in all parameters in a movie object
	// to create and add a movie to the inventory
	// this function is only for comedies and dramas
	bool addMovie(string type, string title, 
		string director, string release, int stock);

	// overloaded function takes in all parameters in a movie 
	// object to create and add a movie to the inventory
	// for classic movies
	bool addMovie(string type, string title, string director, 
		string mainActor, string release, int stock,int year,int month);

	//Searches map for the movie and decrement stock
	bool borrow(string movieID);
		

	//Searches map for movie and increments stock
	bool returnMovie(string movieID);
		

	//inventory of store
	//Runs the three methods for printing each movie type
	void printMovieList()const;

	//print the Comedy movieID¡¯s
	void printComedy() const;
	

	//print the Drama movieID¡¯s
	void printDrama()const;


	//print the Classic movieID¡¯s 
	void printClassic()const;


};

#endif
