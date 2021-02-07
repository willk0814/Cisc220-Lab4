/*
 * SNodeL.hpp
 *
 *  Created on: Apr 28, 2019
 *      Author: lukegrippa
 */

#ifndef SNODEL_HPP_
#define SNODEL_HPP_

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
class SNodeL {
	friend class LL;
	public:
	int wscore;
	string word; 	// instead of int data, now the data is both the rating
						// and the accompanying comments – think of when you rate
						// a book or a song, and then are asked to share comments
						//about the book. Both are the data in this node.
	SNodeL *next;

	SNodeL(); 			// this constructor takes no input. It and asks the user to input a
						// rating, then reads the rating into the rating field, and
						// then asks the user to input their comments, and reads in the
						// comments into the comments field.
	SNodeL(string s);
						// this constructor takes as input an integer and a string, and
						// initializes the rating field to the integer, and the comment
						// field to the string.
	~SNodeL();
	void printNode();

};



#endif /* SNODEL_HPP_ */
