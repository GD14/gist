#include <iostream>
#include <string>
#include "inventory.h"


//no args constructor
Inventory::Inventory() {}

// destructor goes through all maps and deletes the movies
// stored in each category
Inventory::~Inventory() {
	auto cit = classics.begin();  // deletes all classics
	while (cit != classics.end()) {
		delete cit->second;
		++cit;
	}
	classics.clear();		// clears map
	classicsPrint.clear(); // classics already gone

	auto dit = dramas.begin();  // deletes all dramas
	while (dit != dramas.end()) {
		delete dit->second;
		++dit;
	}
	dramas.clear();

	auto fit = comedies.begin(); // deletes all comedies
	while (fit != comedies.end()) {
		delete fit->second;
		++fit;
	}
	comedies.clear();
}

//Searches map for the movie and decrement stock
bool Inventory::borrow(string movieID){
	if (comedies.find(movieID) != comedies.end()) {  
		// movie exist in comedies

		// get iterator to the movie and try to borrow
		map<string, Comedy*>::iterator temp = comedies.find(movieID);
		if (temp->second->borrowAMovie()) {
			return true;  // enough copies left
		}
		else return false;

	}
	else if (dramas.find(movieID) != dramas.end()) {
		// movie exist in dramas

		// get iterator to the movie and try to borrow
		map<string, Drama*>::iterator temp = dramas.find(movieID);
		if (temp->second->borrowAMovie()) {
			return true;	// enough copies left
		}
		else return false;

	}
	else if (classics.find(movieID) != classics.end()) {
		// movie is found in classics

		// get iterator to the movie and try to borrow
		map<string, Classic*>::iterator temp = classics.find(movieID);
		if (temp->second->borrowAMovie()) {
			return true;	// enough copies left
		}
		else return false;

	}
	else return false;
}

// takes in all parameters in a movie object
// to create and add a movie to the inventory
// this function is only for comedies and dramas
bool Inventory::addMovie(string type, string title, 
	string director, string release, int stock) {
		if (type == "F") {
		Comedy* newMovie = new Comedy(title, director, release, stock);
		
		if (comedies.find(newMovie->getMovieID()) != comedies.end()) {
			// movie already in inventory
			delete newMovie;
			return false;
		}
		// if not add to comedies map
		comedies[newMovie->getMovieID()] = newMovie;
		return true;
	}
	else if (type == "D") {
		Drama* newMovie = new Drama(title, director, release, stock);

		if (dramas.find(newMovie->getMovieID()) != dramas.end()) {
			// movie already in inventory
			delete newMovie;
			return false;
		}
		// if not add to dramas map
		dramas[newMovie->getMovieID()] = newMovie;
		return true;
	}
	else {
		std::cout << "Movie Category does not exist, cannot add to inventory";
		std::cout << std::endl;
		return false;
	}
}

// overloaded function takes in all parameters in a movie 
// object to create and add a movie to the inventory
// for classic movies
bool Inventory::addMovie(string type, string title, string director, 
	string mainActor, string release, int stock, int year, int month) {
	if (type == "C") {
		Classic* newMovie = new Classic(title, director, 
			mainActor, release, stock);
		

		if (classics.find(newMovie->getMovieID()) != classics.end()) {
			// movie already in inventory
			delete newMovie;
			return false;
		}
		// if not add to classics and classics print map

		classics[newMovie->getMovieID()] = newMovie;
		classicsPrint[pair<pair<int,int>,string>
			(pair<int,int>(year,month),mainActor)] = newMovie;
		return true;
	}
	else {
		std::cout << "Movie Category does not exist, cannot add to inventory";
		std::cout << std::endl;
		return false;
	}

}

//Searches map for movie and increments stock
bool Inventory::returnMovie(string movieID){
	if (comedies.find(movieID) != comedies.end()) {
		// movie found in comedies

		auto temp = comedies.find(movieID);  // get pointer
		if (temp != comedies.end()) {  // returns the movie
			temp->second->returnAMovie();
			return true;
		}
		else return false;

	}
	else if (dramas.find(movieID) != dramas.end()) {
		// movie found in dramas

		auto temp = dramas.find(movieID);  // get pointer
		if (temp != dramas.end()) {		// returns movie
			temp->second->returnAMovie();
			return true;
		}
		else return false;

	}
	else if (classics.find(movieID) != classics.end()) {

		auto temp = classics.find(movieID);  // get pointer
		if (temp != classics.end()) {	// returns movie
			temp->second->returnAMovie();
			return true;
		}
		else return false;

	}
	// at this point movie is not in the inventory
	std::cout << "Movie not part of store inventory, cannot return";
	std::cout << std::endl;
	return false;
	
}


//inventory of store
//Runs the three methods for printing each movie type
void Inventory::printMovieList()const{
	std::cout << "Store Inventory" << std::endl;
	printComedy();
	printDrama();
	printClassic();
}

//print the Comedy movieID¡¯s
void Inventory::printComedy()const{
	std::cout << "Comedy Inventory" << std::endl;
	auto temp = comedies.cbegin();
	string output = "";

	// loops through all movies stored in comedies map
	while (temp != comedies.end()) { 
		// get the stock, director, and movie Id for output
		output += temp->second->getStock() + ", ";
		output += temp->second->getDirector() + ", ";
		output += temp->first;
		std::cout << output << std::endl;
		output = "";  // resets output for next line
		++temp;
	}

}


//print the Drama movieID¡¯s
void Inventory::printDrama()const{
	std::cout << "Drama Inventory" << std::endl;
	auto temp = dramas.cbegin();
	string output = "";

	// loops through all movies stored in dramas map
	while (temp != dramas.end()) {
		// get the stock, release date, and movie Id for output
		output += temp->second->getStock() + ", ";
		output += temp->first + ", ";
		output += temp->second->getRelease();
		std::cout << output << std::endl;
		output = "";   // resets output for next line
		++temp;
	}
}


//print the Classic movieID¡¯s 
void Inventory::printClassic()const{
	std::cout << "Classic Inventory" << std::endl;
	auto temp = classicsPrint.cbegin();
	string output = "";

	// loops through all movies stored in classics map
	while (temp != classicsPrint.end()) {
		// get the stock,direcctor, release date
		// actors for output
		output += temp->second->getStock() + ", ";
		output += temp->second->getDirector() + ", ";
		output += temp->second->getActor() + " ";
		output += temp->second->getRelease();
		std::cout << output << std::endl;
		output = "";    // resets output for next line
		++temp;
	}
}