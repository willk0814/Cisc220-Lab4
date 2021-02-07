/*
 * SNodeL.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: lukegrippa
 */

#include "SNodeL.hpp"

SNodeL::SNodeL() {
	rating = NULL;
	comments = " ";
	cin >> rating;
	cin >> comments;
	next = NULL;
}

SNodeL::SNodeL(int r, string c) {
	rating = r;
	comments = c;
	next = NULL;
}

SNodeL::~SNodeL() {
	cout << "removing " << rating << ", " << comments << endl;
	cout << "deleting " << rating << ", " << comments << endl;
}

void SNodeL::printNode() {
	cout << "Rating: " << rating << ", Comments: " << comments << endl;
}


