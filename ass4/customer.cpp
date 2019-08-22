#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "customer.h"

//Declare new customer and set name and id
Customer::Customer(int Id, string name){
	customerID = Id;
	customerName = name;
}

// destructor clears the map used to store checked out movies and vector
// of checkout and return history for this customer
Customer::~Customer() {
	current.clear();
	history.clear();
}

//append something to history
//Adds a string to their history based on whether they borrow or return an item
void Customer::addToHistory(string action, string movie, int copies){
	// action for return or borrow, along with copies and movieID
	string addStr = action + " " + to_string(copies) + " of " + movie;
	history.push_back(addStr);
}


//erase entry from current checkout Map
void Customer::removeFromCurrent(string movieID){
	auto it = current.find(movieID); // gets iterator of movie to remove
	if (it != current.end()) {  // movie exists
		it->second = 0;   // num checked out set to 0 and erase
		current.erase(it);
	}
	else {  // movie not currently checked out
		std::cout << "Item not check out by current customer";
		std::cout << std::endl;
	}
	
}

//find method to see if movie is currently checked out
bool Customer::isCheckedOut(string movieID){
	return(current.find(movieID) != current.end());
}


// returns the vector ¡°history¡±
void Customer::printHistory(){
	std::cout << customerName << std::endl;
	auto it = history.begin();     // goes through the vector to print all
	while (it != history.end()) {	// borrows and returns
		std::cout << *it << std::endl;
		++it;
	}
}

// prints what the customer checked out
void Customer::printCurrent(){
	auto it = current.begin();		// iterator to go through map
	while (it != current.end()) {	// adds num of copies for each movie
		std::cout << it->second << " copies of ";
		std::cout << it->first << std::endl;
		++it;
	}
}

// returns the customerID
int Customer::getCustomerID(){ return customerID; }

//returns customer name
string Customer::getCustomerName(){ return customerName; }

// adds movie to current map for items checked out by customer
// inventory should be checked first to make sure there are enough copies
bool Customer::checkOut(string movieId, int numberOf){
	if (!isCheckedOut(movieId)) {  // item not already checked out
		current[movieId] = numberOf;  // add movie to list of current
		addToHistory("Borrowed", movieId, numberOf);  // add action to history
		return true;
	}
	else {  // already checked out before
		int temp = numberOf + current[movieId];  // new num of copies
		current[movieId] = temp;  // adds to num copies already checked out
		addToHistory("Borrowed", movieId, numberOf);
		return true;
	}
}

// return numberOf copies of movie in parameter, if number exceeds
// number checked out by customer, return number checked out
// inventory must be changed seperately
bool Customer::returnMovie(string movieId, int numberOf){
	// will not return movie not checked out of num is 0
	if (!isCheckedOut(movieId) || numberOf == 0) {
		std::cout << "Item not checked out by customer" << std::endl;
		return false;
	}
	if (current[movieId] < numberOf) {  // too many copies checked out
		std::cout << "Amount exceeds number checked out, ";
		std::cout << current[movieId] + " number of copies returned";
		std::cout << std::endl;   // returns all checked out copies
		addToHistory("Returned", movieId, current[movieId]);
		removeFromCurrent(movieId);
		return true;
	}
	else if (current[movieId] == numberOf) {  // returns all copies
		addToHistory("Returned", movieId, current[movieId]);
		removeFromCurrent(movieId);
		return true;
	}
	else {  // did not return all copies
		int temp = current[movieId] - numberOf;  // gets copies still
		addToHistory("return", movieId, numberOf); // checked out
		current[movieId] = temp;
		return true;
	}
}