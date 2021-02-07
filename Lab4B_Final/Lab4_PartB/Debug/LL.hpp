/*
 * LL.hpp
 *
 *  Created on: Apr 28, 2019
 *      Author: lukegrippa
 */

#ifndef LL_HPP_
#define LL_HPP_

#include "SNodeL.hpp"
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class LL {
	SNodeL *first;
	SNodeL *last;
	int size;
	int score;
public:
	LL();
	~LL();
	void printLL();
	// (4 pts for working) write a method that prints out the linked list
	void insertInOrder(int r, string c);
	//(6 pts for working)
	//This method creates an ordered linked list (ordered by the rating). If the
	//linked list is empty, it calls addFirst with r and c. If the rating is less
	//than the first node’s rating in the list, it calls addAtFirst. If the
	//rating is greater than the last node’s rating, it calls the push method.
	//Otherwise it creates a new node using r and c, and inserts that node in
	//order into the linked list.
	void push(int r, string c);
	// (4 pts for working)
	// pushes a new node (with rating r and c comments) onto the end of the linked
	// list
	// (remember to reset the last pointer) – I called this from the
	// insertInOrder() method.
	void addAtFront(int r, string c);
	// (5 pts for working)
	// adds a new node (made from r and c) to the beginning of the
	// list (remember to reset the first pointer) – I called this from
	// insertInOrder
	void addFirst(int r, string c);
	//(3 pts for working)
	//adds the very first node (made from r and c) to an empty list
	// I called this from insertInOrder
	int pop();
	// (5 pts for working)
	// removes the last node from the linked list, and returns the rating from the
	// node removed.
	double getAve();
	// (4 pts for working)
	// calculates the average rating (by traversing the list) and then returns
	// the average rating.
	void getScore();
};



#endif /* LL_HPP_ */
