/*
 * SNodeL.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: lukegrippa
 */

#include "SNodeL.hpp"

SNodeL::SNodeL() {
	word = " ";
	cin >> word;
	next = NULL;
	wscore = 0;
}

SNodeL::SNodeL(string s) {
	word = s;
	next = NULL;
	wscore = 0;
}

SNodeL::~SNodeL() {
	cout << "removing " << word << endl;
	cout << "deleting " << word << endl;
}

void SNodeL::printNode() {
	cout << "Word" << "(" << wscore << ")" << endl;
}


