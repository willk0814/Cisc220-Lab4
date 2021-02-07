/*
 * LL.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: lukegrippa
 */

#include "LL.hpp"
#include "SNodeL.hpp"

LL::LL(){
	first = NULL;
	last = NULL;
	size = 0;
	score = 0;
}

LL::~LL(){
	cout << "deleted each node in ll" << endl;
}

void LL::printLL(){
	SNodeL *tmp;
	tmp = first;
	for (int i = 0; i < size; i++){
		tmp->printNode();
		tmp = tmp -> next;
	}
	cout << endl;
}

//pushes a new Node with rating r and comments c onto the end of the SLL
void LL::push(string s){
	SNodeL *n = new SNodeL(s);
	last->next = n;
	n -> next = NULL;
	last = n;
	size++;
}

//adds the very first node to the made from r and c to an empty list
void LL::addFirst(string s){
	SNodeL *n = new SNodeL(s);
	first = n;
	last = n;
	n -> next = NULL;
	size++;
}

void LL::getScore() {
	SNodeL* tmp;
	tmp = first;
	for (int i = 0; i < size; tmp = tmp->next){
		score += tmp->wscore;
		tmp = tmp -> next;
	}
}

