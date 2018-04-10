/********************
** Author: Kelvin Lu
** Date: 10/31/2017
** Description: This is the specification file for the node class. It also contains the implementations for the menu functions.
********************/

#ifndef NODE_HPP
#define NODE_HPP

#include "Characters.hpp"

class Node
{
private:
	Character * val;
	Node * next;
	Node * prev;
public:
	//Default Constructor
	Node();

	//3-Parameter Constructor for setting values
	Node(Character * input, Node * prevNode, Node * nextNode);

	//Setter function for val
	void setVal(Character * input) { val = input; }

	//Setter function for next
	void setNext(Node * nextNode) { next = nextNode; }

	//Setter function for prev
	void setPrev(Node * prevNode) { prev = prevNode; }

	//Getter function for val
	Character * getVal() { return val; }

	//Getter function for next
	Node * getNext() { return next; }

	//Getter function for prev
	Node * getPrev() { return prev; }

};

#endif