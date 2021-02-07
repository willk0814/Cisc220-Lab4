#include "BSTY.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

BSTY::BSTY() {
	root = NULL;
}

// You write:  insert a new node with data x (a string) into the 
// binary search tree
// This method should return true if a new node is inserted and 
// false if the data x is already in the tree
// Remember to check whether the new node will be the root
// (meaning the root is currently NULL) and if so, set the root
// to be the new node.
// Note: Make sure you make the new node point to its parent!!! 
// Note2: after you've inserted a new node, you should call the 
// adjustHeights method that will update the heights of all the 
// ancestors of the node that was just inserted.
bool BSTY:: insertit(string x){
	cout << "inserting " << x << endl;
	return insertitRecursive(x, root);
}

bool BSTY:: insertitRecursive(string x, NodeT *n) {
	if (root == NULL) {
		root = new NodeT(x);
		cout << x << endl;
		return true;
	} else if (x < n->data) {
		if (n->left == NULL) {
			n->left = new NodeT(x);
			n->left->parent = n;
			adjustHeights(n);
			return true;
		} else {
			return insertitRecursive(x, n->left);
		}
	} else if (x > n->data) {
		if (n->right == NULL) {
			n->right = new NodeT(x);
			n->right->parent = n;
			adjustHeights(n);
			return true;
		} else {
			return insertitRecursive(x, n->right);
		}
	} else {
		return false;
	}
}

// the adjustHeights method updates the heights of every ancestor of the node n.
// This method will be massively useful with our next lab, so make sure you have 
// this working now.  It should be called whenever you change the height of a 
// a particular node.  So, for instance, when a new node is inserted as a leaf, 
// its height is 1.  The adjustHeights method should then check the parent to see
// if the height of the parent changes (the height of each node is the maximum of 
// the height of the left child and the height of the right child, plus 1).  If 
// the parent's height changes, then the grandparent's height should be checked and,
// if necessary, adjusted.  If the grandparent's height is updated, then the great-
// grandparent's height should be adjusted, etc.  The checking stops when either 
// the loop has worked its way up to the root, or until the currently being checked
// ancestor is not changed.  
void BSTY::adjustHeights(NodeT *n) {
	int notChanged = 0;
	if (n != NULL && notChanged == 0) {
		if (n->left != NULL && n->right != NULL) {
			if (n->left->height > n->right->height) {
				if (n->height != (n->left->height + 1)) {
					n->height = (n->left->height + 1);
					if (findBalance(n) == -2) { //first rotation is a left
						cout << n->data << " must rotate left (" << findBalance(n) << ")" << endl;
						if (findBalance(n->right) == -1) { //Left-Left
							n = rotateLeft(n);
						} else if (findBalance(n->right) == 1) { //Left-Right
							n->right = rotateRight(n->right);
							n = rotateLeft(n);
						}
					} else if (findBalance(n) == 2) { //first rotation is a right
						cout << n->data << " must rotate right (" << findBalance(n) << ")" << endl;
						if (findBalance(n->left) == -1) { //Right-Left
							n->left = rotateLeft(n->left);
							n = rotateRight(n);
						} else if (findBalance(n->left) == 1) { //Right-Right
							n = rotateRight(n);
						}
					}
					adjustHeights(n->parent);
				} else {
					notChanged = 1;
				}
			} else if (n->left->height < n->right->height) {
				if (n->height != (n->right->height + 1)) {
					n->height = (n->right->height + 1);
					if (findBalance(n) == -2) { //first rotation is a left
						cout << n->data << " must rotate left (" << findBalance(n) << ")" << endl;
						if (findBalance(n->right) == -1) { //Left-Left
							n = rotateLeft(n);
						} else if (findBalance(n->right) == 1) { //Left-Right
							n->right = rotateRight(n->right);
							n = rotateLeft(n);
						}
					} else if (findBalance(n) == 2) { //first rotation is a right
						cout << n->data << " must rotate right (" << findBalance(n) << ")" << endl;
						if (findBalance(n->left) == -1) { //Right-Left
							n->left = rotateLeft(n->left);
							n = rotateRight(n);
						} else if (findBalance(n->left) == 1) { //Right-Right
							n = rotateRight(n);
						}
					}
					adjustHeights(n->parent);
				} else {
					notChanged = 1;
				}
			}
		} else if (n->left == NULL && n->right != NULL) {
			if (n->height != (n->right->height + 1)) {
				n->height = (n->right->height + 1);
				if (findBalance(n) == -2) { //first rotation is a left
					cout << n->data << " must rotate left (" << findBalance(n) << ")" << endl;
					if (findBalance(n->right) == -1) { //Left-Left
						n = rotateLeft(n);
					} else if (findBalance(n->right) == 1) { //Left-Right
						n->right = rotateRight(n->right);
						n = rotateLeft(n);
					}
				} else if (findBalance(n) == 2) { //first rotation is a right
					cout << n->data << " must rotate right (" << findBalance(n) << ")" << endl;
					if (findBalance(n->left) == -1) { //Right-Left
						n->left = rotateLeft(n->left);
						n = rotateRight(n);
					} else if (findBalance(n->left) == 1) { //Right-Right
						n = rotateRight(n);
					}
				}
				adjustHeights(n->parent);
			} else {
				notChanged = 1;
			}
		} else if (n->left != NULL && n->right == NULL) {
			if (n->height != (n->left->height + 1)) {
				n->height = (n->left->height + 1);
				if (findBalance(n) == -2) { //first rotation is a left
					cout << n->data << " must rotate left (" << findBalance(n) << ")" << endl;
					if (findBalance(n->right) == -1) { //Left-Left
						n = rotateLeft(n);
					} else if (findBalance(n->right) == 1) { //Left-Right
						n->right = rotateRight(n->right);
						n = rotateLeft(n);
					}
				} else if (findBalance(n) == 2) { //first rotation is a right
					cout << n->data << " must rotate right (" << findBalance(n) << ")" << endl;
					if (findBalance(n->left) == -1) { //Right-Left
						n->left = rotateLeft(n->left);
						n = rotateRight(n);
					} else if (findBalance(n->left) == 1) { //Right-Right
						n = rotateRight(n);
					}
				}
				adjustHeights(n->parent);
			} else {
				notChanged = 1;
			}
		}
	}
}

void BSTY::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreeIO(root);
	}
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is 
// traversed in order
void BSTY::printTreeIO(NodeT *n) {
	if (n->left != NULL) {
		printTreeIO(n->left);
	}
	n->printNode();
	if (n->right != NULL) {
		printTreeIO(n->right);
	}
}

void BSTY::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePre(root);
	}
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void BSTY::printTreePre(NodeT *n) {
	n->printNode();
	if (n->left != NULL) {
		printTreePre(n->left);
	}
	if (n->right != NULL) {
		printTreePre(n->right);
	}
}

void BSTY::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		printTreePost(root);
		cout << endl;
	}
}

// Prints the tree using post-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void BSTY::printTreePost(NodeT *n) {
	if (n->left != NULL) {
		printTreePost(n->left);
	}
	if (n->right != NULL) {
		printTreePost(n->right);
	}
	n->printNode();
}
void BSTY::myPrint() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrint(root);
		cout << endl;
	}
}
void BSTY::myPrint(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrint(n->left);
		cout << n->data.length()-1;
		if (mine) {
			cout <<".";
			mine = false;
		}
		myPrint(n->right);
	}
}

// the find method takes as input a string, and finds whether that string is already
// in the tree or not.  If it is in the tree, that node is returned from the tree.
// If it isn't, NULL is returned.  
// NOTE: If the node can't be found, this method prints out that x can't be found.
// if it is found, the printNode method is called for the node.  
NodeT *BSTY::find(string x) {
	int *comp = comp;
	findRecursive(x, root, comp);

}

NodeT *BSTY::findRecursive(string x, NodeT *n, int *C) {

	if (n->data == x) {
		n->printNode();
		C ++;
		cout << C << endl;
		return n;
	} else if (n->data != x && (n->left == NULL && n->right == NULL)) {
		cout << x << " not found" << endl;
		return NULL;
	} else if (n->data < x) {
		C++;
		findRecursive(x, n->right, C);
	} else if (n->data > x) {
		C++;
		findRecursive(x, n->left, C);
	}
}

/*************************************************************************************/
/* Extra Credit Methods                                                              */
/* Challenging: worth 35 EC pts to go towards labs                                   */
/* NOTE: IF YOU CHOOSE NOT TO IMPLEMENT THESE METHODS, YOU ARE STILL RESPONSIBLE FOR */
/* UNDERSTANDING HOW THEY WORK!!                                                     */
/*************************************************************************************/
/* When removing a node from a binary search tree, the resulting tree MUST BE a binary
/* search tree.  
/*
/* When removing a node, there are 3 conditions:
/* 1: when the node being removed has no children, in which case the node is deleted,
/* the node's parent is set to NULL, and the node's parent's height is adjusted (if
/* necessary) and heights on up are adjusted.
/* 2: when the node being removed has one child, in which case the node's parent points
/* to the node's child, and the node's child points to the node's parent, and the node
/* is deleted (and the height of the parent on up as necessary is adjusted)
/* 3: when the node has 2 children, in which case the left-most child of the node's 
/* right child replaces the node.  
/* A couple of notes about this one: you are replacing a node with a node that is lower
/* down in the tree.  That means that you are, in essence, removing the node from that
/* lower position and moving it up to the old node's location.  Thus the replacing node
/* must be removed using 1 or 2 above (why not 3?).  The heights must be adjusted after 
/* the replacing node is removed from its old location but before it is inserted into its 
/* new location.  Equally, the replacing node's height must be adjusted to be the larger of
/* its two children's heights before you adjust heights above that.  
/*****************************************************************************************/
/* remove(): takes as input a string, uses the find method to find the node in the tree that
/* holds that string, and then calls replace1, replace2, or replace3 depending on what type
/* of replacing should be done.  It adjusts the heights, deletes the node, and returns
/* true if the removal was successful.
*/
bool BSTY::remove(string s) {
	removeRecursive(s, find(s));
}

bool BSTY::removeRecursive(string s, NodeT *n) {
	cout << "removeRecursive() is called" << endl;
	if (n->left == NULL && n->right == NULL) {
		cout << "1 hello darkness my old friend" << endl;
		remove1(n);
		cout << "11 hello darkness my old friend" << endl;
//		adjustHeights(n->parent);
		return true;
	} else if ((n->left != NULL && n->right == NULL) || (n->left == NULL && n->right != NULL)) {
		cout << "2 hello darkness my old friend" << endl;
		remove2(n);
		cout << "22 hello darkness my old friend" << endl;
//		adjustHeights(n->parent);
		return true;
	} else if (n->left != NULL && n->right != NULL) {
		cout << "3 hello darkness my old friend" << endl;
		remove3(n);
		cout << "33 hello darkness my old friend" << endl;
//		adjustHeights(n->parent);
		return true;
	}
	return find(s) == NULL;
}


/* remove1(): called when the node to be removed has no children. Takes as input the 
/* node to be removed, and sets the parent of the node to point to NULL.
/* helpful hint: if (n->parent->left == n) is true, then n is its parent's left child.
/* Make sure you check to whether n is the root or not.
*/
void BSTY::remove1(NodeT *n) {
	cout << "remove1 is running" << endl;
	if (n != root) {
		if (n->parent->left == n) {
			n->parent->left = NULL;
			delete n;
		} else if (n->parent->right == n) {
			n->parent->right = NULL;
			delete n;
		}
	} else {
		root = NULL;
		delete n;
	}
}

/* remove2(): called when the node to be removed has 1 child only.  Takes as input
/* the node to be removed and bypasses it by making the parent point to the node's
/* one child, and makes the node's one child point to the node's parent.  
/* This one needs a bunch of checking - you need to see if the node is the parent's
/* left or right child, and you need to see if the node's child is its left or its
/* right child.
/* Also, make sure you check that if the node to be removed is the root, then the 
/* one child becomes the root.
*/ 
void BSTY::remove2(NodeT *n) {
	cout << "remove2 is running" << endl;
	if (n != root) {
		if (n->parent->left == n) {
			if (n->left != NULL) {
				n->parent->left = n->left;
				n->left->parent = n->parent;
				delete n;
			} else {
				n->parent->left = n->right;
				n->right->parent = n->parent;
				delete n;
			}
		} else if (n->parent->right == n) {
			if (n->left != NULL) {
				n->parent->right = n->left;
				n->left->parent = n->parent;
				delete n;
			} else {
				n->parent->right = n->right;
				n->right->parent = n->parent;
				delete n;
			}
		}
	} else {
		if (n->left != NULL) {
			root = n->left;
			delete n;
		} else if (n->right != NULL) {
			root = n->right;
			delete n;
		}
	}
}

/* remove3(): called when the node to be removed has 2 children.  Takes as input the
/* node to be removed.  The node to replace the node to be removed should be the 
/* left-most descendent of the node's right child.  That way the binary search tree
/* properties are guaranteed to be maintained.
/* When replacing the node to be removed with the replacing node, the replacing node
/* is, in essence, being removed from its place in the tree, and thus replace1 or 
/* replace2 methods should be used.
/* The new node's parent must be set to the removed node's parent, the removed node's
/* parent must point to the new node, the new node's left child must point to the 
/* removed node's left child (and the child must point to the new node as a parent), 
/* and the same for teh right child.
/* Remember to take into account that the node being removed might be the root.
*/
void BSTY::remove3(NodeT *n) {
	cout << "remove3 is running" << endl;
	if (n != root) {
		if (n->parent->left == n) {
			NodeT *m;
			m = findMin(n);
			n->parent->left = m;
			m->parent = n->parent;
			m->left = n->left;
			m->right = n->right;
			n->left->parent = m;
			n->right->parent = m;
			delete n;
		} else if (n->parent->right == n) {
			NodeT *m;
			m = findMin(n);
			n->parent->right = m;
			m->parent = n->parent;
			m->left = n->left;
			m->right = n->right;
			n->left->parent = m;
			n->right->parent = m;
			delete n;
		}
	} else {
		NodeT *m;
		m = findMin(n);
		m = root;
		m->left = n->left;
		m->right = n->right;
		n->left->parent = m;
		n->right->parent = m;
		delete n;
	}
}

/* findMin(): takes as input a node, and finds the left-most descendant of its 
/* right child.  The left-most descendent is returned.
*/
NodeT *BSTY::findMin(NodeT *n) {
	n = n->right;
	return findMinRecursive(n);
}
NodeT *BSTY::findMinRecursive(NodeT *n) {
	if (n->left != NULL) {
		findMinRecursive(n->left);
	} else {
		return n;
	}
}

void BSTY::myPrintEC() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		myPrintEC(root);
		cout << endl;
	}
}
void BSTY::myPrintEC(NodeT *n) {
	if (n == NULL) {
		return;
	}
	else {
		myPrintEC(n->left);
		cout << alpha[n->data.length()-2];
		myPrintEC(n->right);
	}
}


/************************************************************************/

// Part 2: AVL Tree (65 Points)
NodeT *BSTY::rotateRight(NodeT *n) {
	NodeT *x = n->left;
	NodeT *tmp;
	if (x->right == NULL) {
		tmp = x->left;
	} else {
		tmp = x->right;
	}
	// Perform rotation
	if (tmp == x->left) {
		x->right = n;
		if (n == root) {
			n->parent = x;
			n->left = NULL;
			root = x;
		} else {
			x->parent = n->parent;
			if (n->parent->right == n) {
				n->parent->right = x;
			} else {
				n->parent->left = x;
			}
			n->parent = x;
			n->left = NULL;
		}
	} else {
		n->left = tmp;
		tmp->parent = n;
		x->right = n;
		if (n == root) {
			n->parent = x;
			root = x;
		} else {
			x->parent = n->parent;
			if (n->parent->right == n) {
				n->parent->right = x;
			} else {
				n->parent->left = x;
			}
			n->parent = x;
		}
	}
	// Update heights
	if ((n->left == NULL) && (n->right == NULL)) {
		n->height = 1;
	} else if (n->left == NULL) {
		n->height = n->right->height + 1;
	} else if (n->right == NULL) {
		n->height = n->left->height + 1;
	} else if ((n->left != NULL) && (n->right != NULL)) {
		if (n->left->height > n->right->height) {  //why did we look at n first?
			n->height = n->left->height + 1;
		}
		else {
			n->height = n->right->height + 1;
		}
	}
	if (x->right == NULL) {
		x->height = x->left->height + 1;
	} else if (x->left == NULL) {
		x->height = x->right->height + 1;
	} else if ((x->left != NULL) && (x->right != NULL)) {

		if (x->left->height > x->right->height) {
			x->height = x->left->height + 1;
		}
		else {
			x->height = x->right->height+1;
		}
	}
	return x; // Return new root

}

NodeT *BSTY::rotateLeft(NodeT *n) {
	NodeT *x = n->right;
	NodeT *tmp;
	if (x->left == NULL) {
		tmp = x->right;
	} else {
		tmp = x->left;
	}
	// Perform rotation
	if (tmp == x->right) {
		x->left = n;
		if (n == root) {
			n->parent = x;
			n->right = NULL;
			root = x;
		} else {
			x->parent = n->parent;
			if (n->parent->right == n) {
				n->parent->right = x;
			} else {
				n->parent->left = x;
			}
			n->parent = x;
			n->right = NULL;
		}
	} else {
		n->right = tmp;
		tmp->parent = n;
		x->left = n;
		if (n == root) {
			n->parent = x;
			root = x;
		} else {
			x->parent = n->parent;
			if (n->parent->right == n) {
				n->parent->right = x;
			} else {
				n->parent->left = x;
			}
			n->parent = x;
		}
	}
	// Update heights
	if ((n->left == NULL) && (n->right == NULL)) {
		n->height = 1;
	} else if (n->right == NULL) {
		n->height = n->left->height + 1;
	} else if (n->left == NULL) {
		n->height = n->right->height + 1;
	} else if ((n->left != NULL) && (n->right != NULL)) {
		if (n->right->height > n->left->height) {  //why did we look at y first?
			n->height = n->right->height + 1;
		}
		else {
			n->height = n->left->height + 1;
		}
	}
	if (x->right == NULL) {
		x->height = x->left->height + 1;
	} else if (x->left == NULL) {
		x->height = x->right->height + 1;
	} else if ((x->left != NULL) && (x->right != NULL)) {
		if (x->right->height > x->left->height) {
			x->height = x->right->height + 1;
		}
		else {
			x->height = x->left->height+1;
		}
	}
	return x; // Return new root
}

int BSTY::findBalance(NodeT *n) {
	int balance;
	if ((n->left != NULL) && (n->right != NULL)) {
		balance = (n->left->height - n->right->height);
	} else if ((n->left != NULL) && (n->right == NULL)) {
		balance = (n->left->height - 0);
	} else if ((n->left == NULL) && (n->right != NULL)) {
		balance = (0 - n->right->height);
	} else {
		balance = 0;
	}
	return balance;
}
