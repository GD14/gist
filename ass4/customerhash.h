#ifndef CUSTOMERHASH_H
#define CUSTOMERHASH_H
#include <iostream>
#include <vector>
#include <array>
#include "customer.h"

using namespace std;

class CustomerHash {
private:
	// array of vectors to store pairs containing pairs with
	// customer Id and pointers to their object
	// array is the hash table, vector is the buckets
	vector<pair<int,Customer*>> customers[10];
public:
	// empty constructor
	CustomerHash();

	// destructor clears customers
	~CustomerHash();

	// adds customer to the hash vector
	bool addCustomer(int id, Customer* cus);

	// finds the customer in the array of vectors
	Customer* findCustomer(int id);

	// removes the customer from list
	bool removeCustomer(int id);
};

#endif
