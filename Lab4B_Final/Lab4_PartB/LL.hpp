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
	public:
	SNodeL *first;
	SNodeL *last;
	int size;
	int score;
	LL();
	~LL();
	void printLL();
	// (4 pts for working) write a method that prints out the linked list

	void push(string s);
	// (4 pts for working)
	// pushes a new node (with rating r and c comments) onto the end of the linked
	// list
	// (remember to reset the last pointer) – I called this from the
	// insertInOrder() method.

	void addFirst(string s);
	//(3 pts for working)
	//adds the very first node (made from r and c) to an empty list
	// I called this from insertInOrder


	void getScore();
};



#endif /* LL_HPP_ */
