#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"

class Customer {
private:
	// the name of the customer, full
	// included, keeping it in one string
	string customerName;

	// the unique id of the customer, 4 numbers
	int customerID;

	// map of all the movies currently checked out
	map<string, int,less<string>> current;

	// vector of all the movies that have been 
	// checked out at any point in time in order
	std::vector<string> history;
	
	// append something to history
	// Adds a string to their history based on whether 
	// they borrow or return an item
	void addToHistory(string action, string movie, int copies);

	// erase entry from current checkout Map
	void removeFromCurrent(string movieID);

	//find method to see if movie is currently checked out
	bool isCheckedOut(string uniqueMovieID);

public:
	// Declare new customer and set name and id
	Customer(int Id, string name);

	// destructor should clear map and vector of items
	~Customer();
		
	// returns the vector ¡°history¡±
	void printHistory();

	// prints what the customer checked out
	void printCurrent();

	// returns the customerID
	int getCustomerID();

	//returns customer name
	string getCustomerName();

	// if in stock, checks out the intended
	// number of movie selected
	bool checkOut(string movieId, int numberOf);

	// returns the intended number of movie 
	// chosen up to the total
	// copies checked out by this customer
	bool returnMovie(string movieId, int numberOf);


};

#endif