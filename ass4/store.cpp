#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>
#include "customer.h"
#include "inventory.h"
#include "movie.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "customerhash.h"

// borrow movie command will subtract from inventory and add to customer
// need userId and movieId along with the inventory and customer list
bool borrowMovie(int userID, string movieID, 
	Inventory* inventory, CustomerHash* customerList) {
	if (customerList->findCustomer(userID) == nullptr) {
		// check if customer exists
		std::cout << "Customer does not exist" << std::endl;
		return false;
	}
	if (!inventory->borrow(movieID)) {  // try to borrow, and check conditon
		// borrow failed
		std::cout << movieID + " not in inventory" << std::endl;
		return false;
	}
	else {  // borrow successful
		// adds movie to customer current check out list
		customerList->findCustomer(userID)->checkOut(movieID, 1);
		return true;
	}
}

// return movie command will subtract from customer and add to inventory
// need userId and movieId along with the inventory and customer list
bool returnMovie(int userID, string movieID, 
	Inventory* inventory, CustomerHash* customerList) {
	if (customerList->findCustomer(userID) == nullptr) {
		// check if customer exists
		std::cout << "Customer does not exist" << std::endl;
		return false;
	}
	if (customerList->findCustomer(userID)->returnMovie(movieID, 1)) {
		// return successful, add to inventory
		inventory->returnMovie(movieID);
		return true;
	}
	else {   // failed to return movie
		std::cout << "Could not return movie" << std::endl;
		return false;
	}
}

// calls print from inventory object to print all movies in inventory
void printInventory(const Inventory* inventory) {
	inventory->printMovieList();
}

// given the customerList and customer Id, prints the customers
// borrow and return history
void customerHistory(int id, CustomerHash* customerList) {
	Customer* temp = customerList->findCustomer(id);
	if (temp != nullptr) { // customer found
		temp->printHistory();  // prints their history
	}
	else {  // customer not found
		std::cout << "Customer does not exist" << std::endl;
	}
	temp = nullptr;
}

// reads in each line from "data4movies.txt" file and adds them to
// inventory assuming format is correct, only adds comedies, classics
// and dramas, each line is one movie with stock num
void readData4Movies(Inventory* inventory) {
	ifstream movieFile;  // creates and opens stream for txt file
	movieFile.open("data4movies.txt");
	string line = "";
	char movieType;

	while (!movieFile.eof()) {  // go through all lines
		getline(movieFile, line);  // gets the current line of txt
		string temp = "";
		queue<char> movie;
		auto it = line.begin();
		while (it != line.end())  // creates queue with read line
		{
			movie.push(*it);
			++it;
		}

		movieType = movie.front(); // finds out movie type
		movie.pop();

		// ignores spaces and commas
		while (movie.front() == ' ' || movie.front() == ',') { movie.pop(); }

		while (movie.front() != ' ' && movie.front() != ',') {  // get stock
			temp += movie.front();
			movie.pop();
		}
		int stock = stoi(temp); temp = ""; // temp is reset after every use

		while (movie.front() == ' ' || movie.front() == ',') { movie.pop(); }

		while (movie.front() != ',') { // get director
			temp += movie.front();
			movie.pop();
		}
		string director = temp; temp = "";

		while (movie.front() == ' ' || movie.front() == ',') { movie.pop(); }

		while (movie.front() != ',') { // get title
			temp += movie.front();
			movie.pop();
		}
		string title = temp; temp = "";

		while (movie.front() == ' ' || movie.front() == ',') { movie.pop(); }

		// switch statement for different types of movies
		switch (movieType) {
		case 'C': {  // adds classic movie
			while (movie.front() != ' ') { // get name
				temp += movie.front();
				movie.pop();
			}
			temp += movie.front(); movie.pop(); // space between name
			while (movie.front() != ' ') { // get name
				temp += movie.front();
				movie.pop();
			}
			string name = temp; temp = "";

			while (movie.front() == ' ') { movie.pop(); }

			int month, year;

			while (movie.front() != ' ') { // get month
				temp += movie.front();
				movie.pop();
			}
			month = stoi(temp); temp = "";

			// ignore spaces
			while (movie.front() == ' ') { movie.pop(); } 

			while (!movie.empty()) { // get year
				temp += movie.front();
				movie.pop();
			}
			year = stoi(temp); temp = "";
			string release = to_string(month) + " " + to_string(year);

			// add movie after all parameters are gathered
			inventory->addMovie(string(1,movieType), title,
				director, name, release, stock,year,month);
		}
				  break;
		case 'D':  // dramas and comedies are the same structure
		case 'F': {
			while (!movie.empty()) { // get year
				temp += movie.front();
				movie.pop();
			}
			string release = temp; temp = "";

			// add movie after all parameters are gathered
			inventory->addMovie(string(1, movieType), 
				title, director, release, stock);
		}
				  break;
		default:
			std::cout << string(1,movieType) + 
				" is an invalid movie type" << std::endl;
			break;
		}

	}
	movieFile.close();
}

// reads in each line from "data4customers.txt" and adds to a hash table
// to store customers, assume correct formatting, ID, last, first
void readData4Customers(CustomerHash* customerList) {
	string line = "", last = "", first = "";
	int id;
	ifstream customerFile;  // stream created and opened
	customerFile.open("data4customers.txt");

	// goes through all the lines
	while (!customerFile.eof()) {
		customerFile >> id;
		customerFile >> last;
		customerFile >> first;
		line = last + " " + first;

		// create new customer 
		Customer* newCustomer = new Customer(id, line);
		// if statement tries to add to hash table and returns bool
		// on whether successful
		if (!customerList->addCustomer(id, newCustomer)) {
			// deletes customer if they already exists
			delete newCustomer;  
		}
	}

	customerFile.close();
}

// reads in each line from "data4commands.txt" and executes them accordingly
void readData4Commands(CustomerHash* customerList, Inventory* inventory) {
	ifstream commandFile; // stream created and opened
	commandFile.open("data4commands.txt");
	string line = "";
	char commandType;
	string commandSeperation =
		"-------------Command Seperation Line--------------";
	// each command will be printed out and seperated for clarity

	while (!commandFile.eof()) {  // go through all commands
		getline(commandFile, line);
		std::cout << line << std::endl; // prints command for clarity

		queue<char> command;
		auto it = line.begin();
		while (it != line.end())  // creates queue with read in line
		{
			command.push(*it);
			++it;
		}

		commandType = command.front(); // finds out command type
		command.pop();

		string temp = "";

		// switch statement for each type of command
		switch (commandType) {
		case 'B': {  // borrow a movie
			// ignore spaces
			while (command.front() == ' ') { command.pop(); } 
			while (command.front() != ' ') {  // get id
				temp += command.front();
				command.pop();
			}
			int id = stoi(temp); temp = "";

			while (command.front() == ' ') { command.pop(); }
			command.pop(); // skip D for dvd
			while (command.front() == ' ') { command.pop(); }
			char type = command.front(); command.pop();  // get movie type
			while (command.front() == ' ') { command.pop(); }

			if (type == 'C') {  // classics
				int month, year;

				while (command.front() != ' ') { // get month
					temp += command.front();
					command.pop();
				}
				while (command.front() == ' ') { command.pop(); }
				month = stoi(temp); temp = "";

				while (command.front() != ' ') { // get year
					temp += command.front();
					command.pop();
				}
				while (command.front() == ' ') { command.pop(); }
				year = stoi(temp); temp = "";

				string release = to_string(month) + " " + to_string(year);

				while (command.front() != ' ') { // get name
					temp += command.front();
					command.pop();
				}
				// space between name
				temp += command.front(); command.pop(); 
				while (!command.empty()) { // get name
					temp += command.front();
					command.pop();
				}
				string name = temp; temp = "";
				string movieId = release + ", " + name;

				// borrows movie after all parameters obtained
				borrowMovie(id, movieId, inventory, customerList);
			}
			else if (type == 'D') { // dramas

				while (command.front() != ',') { // get director
					temp += command.front();
					command.pop();
				}
				string director = temp; temp = "";

				while (command.front() == ' ' || command.front() == ',') {
					command.pop(); 
				}

				while (command.front() != ',') { // get title
					temp += command.front();
					command.pop();
				}
				string title = temp; temp = "";
				string movieId = director + ", " + title;

				// borrows movie after all parameters obtained
				borrowMovie(id, movieId, inventory, customerList);
			}
			else if (type == 'F') {  // comedies
				while (command.front() != ',') { // get title
					temp += command.front();
					command.pop();
				}
				string title = temp; temp = "";

				while (command.front() == ' ' || command.front() == ',') {
					command.pop();
				}

				while (!command.empty()) { // get year
					temp += command.front();
					command.pop();
				}
				string release = temp; temp = "";
				string movieId = title + ", " + release;

				// borrows movie after all parameters obtained
				borrowMovie(id, movieId, inventory, customerList);
			}
			else {
				std::cout << "Movie type incorrect" << std::endl;
			}
		}
				  break;
		case 'R': {  // return a movie
			// ignore spaces
			while (command.front() == ' ') { command.pop(); } 
			while (command.front() != ' ') {  // get id
				temp += command.front();
				command.pop();
			}
			int id = stoi(temp); temp = "";

			while (command.front() == ' ') { command.pop(); } 
			command.pop(); // skip D for dvd
			while (command.front() == ' ') { command.pop(); } 
			char type = command.front(); command.pop();
			while (command.front() == ' ') { command.pop(); } 

			if (type == 'C') {  // classics
				int month, year;

				while (command.front() != ' ') { // get month
					temp += command.front();
					command.pop();
				}
				while (command.front() == ' ') { command.pop(); } 
				month = stoi(temp); temp = "";

				while (command.front() != ' ') { // get year
					temp += command.front();
					command.pop();
				}
				while (command.front() == ' ') { command.pop(); }
				year = stoi(temp); temp = "";

				string release = to_string(month) + " " + to_string(year);

				while (command.front() != ' ') { // get name
					temp += command.front();
					command.pop();
				}
				// space between name
				temp += command.front(); command.pop(); 
				while (!command.empty()) { // get name
					temp += command.front();
					command.pop();
				}
				string name = temp; temp = "";
				string movieId = release + ", " + name;

				// borrows movie after all parameters obtained
				returnMovie(id, movieId, inventory, customerList);
			}
			else if (type == 'D') {  // dramas
				while (command.front() != ',') { // get director
					temp += command.front();
					command.pop();
				}
				string director = temp; temp = "";

				while (command.front() == ' ' || command.front() == ',') {
					command.pop(); 
				}

				while (command.front() != ',') { // get title
					temp += command.front();
					command.pop();
				}
				string title = temp; temp = "";
				string movieId = director + ", " + title;

				// borrows movie after all parameters obtained
				returnMovie(id, movieId, inventory, customerList);
			}
			else if (type == 'F') {  // comedies
				while (command.front() != ',') { // get title
					temp += command.front();
					command.pop();
				}
				string title = temp; temp = "";

				while (command.front() == ' ' || command.front() == ',') { 
					command.pop(); 
				}

				while (!command.empty()) { // get year
					temp += command.front();
					command.pop();
				}
				string release = temp; temp = "";
				string movieId = title + ", " + release;

				// borrows movie after all parameters obtained
				returnMovie(id, movieId, inventory, customerList);
			}
			else {
				std::cout << "Movie type incorrect" << std::endl;
			}
		}
			break;
		case 'I': {  // print inventory
			printInventory(inventory);
		}
			break;
		case 'H': {  // print customer history
			while (command.front() == ' ') { command.pop(); }
			while (!command.empty()) {  // get id
				temp += command.front();
				command.pop();
			}
			int id = stoi(temp); temp = "";

			customerHistory(id, customerList);
		}
			break;
		default:
			std::cout << string(1,commandType) + 
				" is a invalid Command" << std::endl;
		}

		std::cout << commandSeperation << std::endl;
	}
	commandFile.close();
}

int main() {
	Inventory* inventory = new Inventory();
	CustomerHash* customerList = new CustomerHash();

	readData4Movies(inventory);
	readData4Customers(customerList);
	readData4Commands(customerList,inventory);

	delete inventory;
	delete customerList;
	return 0;
}
