#ifndef BSTY_HPP_
#define BSTY_HPP_

#include "NodeT.hpp"
#include <string>
using namespace std;

class BSTY {
	NodeT *root;
	bool mine = true;
	string alpha[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

public:
	BSTY() ;
	bool insertit(string x);
	bool insertitRecursive(string x, NodeT *n);
	void adjustHeights(NodeT *n);
	void printTreeIO();
	void printTreeIO(NodeT *n);
	void printTreePre();
	void printTreePre(NodeT *n);
	void printTreePost();
	void printTreePost(NodeT *n);
	void myPrint();
	void myPrint(NodeT *n);
	NodeT *find(string x);
	NodeT *findRecursive(string x, NodeT *n);

// For Extra Credit
	void myPrintEC();
	void myPrintEC(NodeT *n);
	bool remove(string s);
	bool removeRecursive(string s, NodeT *n);
	void remove1(NodeT *n);
	void remove2(NodeT *n);
	void remove3(NodeT *n);
	NodeT *findMin(NodeT *n);
	NodeT *findMinRecursive(NodeT *n);

// For Part 2: AVL Tree
	NodeT *rotateRight(NodeT *n);
	NodeT *rotateLeft(NodeT *n);
	int findBalance(NodeT *n);
};







#endif /* BSTY_HPP_ */
