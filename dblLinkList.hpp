/********************
** Author: Kelvin Lu
** Date: 10/31/2017
** Description: This is the specification file for the dblLinkList class, which contains the methods used to construct a double linked list.
********************/

#ifndef DBLLINKLIST_HPP
#define DBLLINKLIST_HPP

#include "Node.hpp"
#include <iostream>
#include <string>
#include <fstream>

class dblLinkList
{
private:
	Node * front;
	Node * back;
public:
	//Constructor
	dblLinkList();

	//Check if the list is empty
	bool isEmpty();

	//Add node to the head of the list
	void addFront(Character * input);

	//Add node to the back of the list
	void addBack(Character * input);

	//Delete the first node in the list
	void deleteFront();

	//Delete the last node in the list
	void deleteBack();

	//Traverse the list and print each node's value
	void traverseFront();

	//Traverse the list in the reverse direction and print each node's value
	void traverseBack();

	//Get the front node's value
	Character * getFront();

	//Get the back node's value
	Character * getBack();

	//Delete a list
	void deleteList();

	//Destructor
	~dblLinkList();
};

#endif