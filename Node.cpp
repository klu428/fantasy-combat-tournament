/********************
** Author: Kelvin Lu
** Date: 10/31/2017
** Description: This is the implementation file for the node class.
********************/

#include "Node.hpp"

//Constructor
Node::Node()
{
	val = nullptr;
	next = nullptr;
	prev = nullptr;
}

//3-Parameter Constructor
Node::Node(Character * input, Node * prevNode, Node * nextNode)
{
	setVal(input);
	prev = prevNode;
	next = nextNode;
	
}

