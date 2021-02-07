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

//
void LL::insertInOrder(int r, string c){
	if (size == 0) {
		addFirst(r, c);
	} else if ((r < first->rating) && (size != 0)) {
		addAtFront(r, c);
	} else if ((r > last->rating) && (size != 0)) {
		push(r, c);
	} else {
		SNodeL *tmp;
		tmp = first;
		int p = 0;
		for (int i = 0; i <= size; i++){
			if ((tmp->next->rating > r) && (p == 0)) {
				SNodeL *n = new SNodeL(r, c);
				n->next = tmp->next;
				tmp->next = n;
				p++;
			} else {
				tmp = tmp->next;
			}
		}
		size++;
	}
}

//pushes a new Node with rating r and comments c onto the end of the SLL
void LL::push(int r, string c){
	SNodeL *n = new SNodeL(r, c);
	last->next = n;
	n -> next = NULL;
	last = n;
	size++;
}

//adds a new node made from r and c to the beginning of the list
void LL::addAtFront(int r, string c){
	SNodeL *n = new SNodeL(r,c);
	n -> next = first;
	first = n;
	size++;
}

//adds the very first node to the made from r and c to an empty list
void LL::addFirst(int r, string c){
	SNodeL *n = new SNodeL(r,c);
	first = n;
	last = n;
	n -> next = NULL;
	size++;
}

//removes the last node from the LL and returns the rating
int LL::pop(){
	SNodeL *tmp = first;
	for (int i = 0; i < size - 2; i++){
		tmp = tmp -> next;
	}
	int x = last->rating;
	string y = last->comments;
	delete last;
	last = tmp;
	last->next = NULL;
	size--;
	return x;
}


// calculates the average rating (by traversing the list) and then returns
// the average rating.
double LL::getAve() {
	SNodeL *tmp;
	tmp = first;
	double sum = 0;
	int count = 0;
	for (int i = 0; i < size; i++){
			sum += tmp->rating;
			tmp = tmp -> next;
			count++;
		}
	double ave = sum / count;
	return ave;
}

void LL::getScore() {

}

