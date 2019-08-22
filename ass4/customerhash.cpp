#include <iostream>
#include "customerhash.h"

// nothing to initiate, empty constuctor
CustomerHash::CustomerHash(){}

// destructor goes through the array of vectors deleting all customer
// objects
CustomerHash::~CustomerHash(){
	for (int i = 0; i < 10; i++) {  // iterate through the array
		auto it = customers[i].begin();

		while (it != customers[i].end()) {  // iterate through buckets
			delete it->second;
			++it;
		}
		customers[i].clear();
	}
}

// adds customer to the hash table as a pair object with customer Id
// and pointer to the customer object
bool CustomerHash::addCustomer(int id, Customer* cus){
	if (findCustomer(id) == nullptr) {  // customer has not been added
		// uses the last digit of customer Id to hash
		customers[id % 10].push_back(pair<int, Customer*>(id, cus));
		return true;
	}
	else {  // customer exists
		std::cout << "Customer already exists" << std::endl;
		return false;
	}
	
}

// finds customer by id, returns pointer if found, if customer does
// not exist nullptr is returned
Customer* CustomerHash::findCustomer(int id){
	// hashes Id to find vector customer should be stored in
	auto it = customers[id % 10].begin();

	while (it != customers[id % 10].end()) {
		// iterate through vector to find it
		if (it->first == id) {
			return it->second;
		}

		++it;
	}
	return nullptr; // does not exist at this point
}

// finds and removes intended customer with input Id
bool CustomerHash::removeCustomer(int id){
	auto it = customers[id % 10].begin(); // finds bucket it should be in

	while (it != customers[id % 10].end()) {

		if (it->first == id) {  // looks into the vector
			delete it->second;
			customers[id % 10].erase(it);
			return true;
		}

		++it;
	}
	return false;  // customer not found, can't remove
}