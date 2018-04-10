/********************
** Author: Kelvin Lu
** Date: 10/31/2017
** Description: This is the implementation file for the dblLinkList class, which contains the methods used to construct a double linked list.
********************/

#include "dblLinkList.hpp"


//Constructor
dblLinkList::dblLinkList()
{
	//Set front and back to null
	front = nullptr;
	back = nullptr;
}


//Check if the list is empty
bool dblLinkList::isEmpty()
{
	if (front == nullptr)
	{
		return true;
	}

	return false;
}


//Add a node to the front of the list
void dblLinkList::addFront(Character * input)
{
	//Dynamically allocate memory for the node, set the new node's previous to null and next to the node currently in the front of the list
	Node * newNode = new Node(input, nullptr, front);

	//Check if list is empty
	if (front != nullptr)
	{
		//If not empty, set the prev of the node currently in the front of the list to the new node
		front->setPrev(newNode);
	} else
	{
		//If list is empty, set the back to the new node
		back = newNode;
	}

	//Set the front to the new node
	front = newNode;
}

//Add a node to the back of the list
void dblLinkList::addBack(Character * input)
{
	//Dynamically allocate memory for the node, set the new node's next to null and prev to the node currently in the back of the list
	Node * newNode = new Node(input, back, nullptr);

	//Check if list is empty
	if (back != nullptr)
	{
		//If not empty, set the next of the node currently in the back of the list to the new node
		back->setNext(newNode);
	}
	else
	{
		//If list is empty, set the front to the new node
		front = newNode;
	}

	//Set the back to the new node
	back = newNode;
}

//Delete the node at the front of the list
void dblLinkList::deleteFront()
{
	//Create a temporary node that equals the next of the node currently at the front of the list
	Node * temp = front->getNext();

	//Check if the node being removed is the only node in the list
	if (temp != nullptr)
	{
		//If not the only node, set the temporary node's previous to null
		temp->setPrev(nullptr);
	} else
	{
		//If it is the only node, set back to null
		back = nullptr;
	}

	//Delete and free the memory used for the node in the front
	delete front;

	//Set front to temp
	front = temp;
}

//Delete the node at the back of the list
void dblLinkList::deleteBack()
{
	//Create a temporary node that equals the prev of the node currently at the back of the list
	Node * temp = back->getPrev();

	//Check if the node being removed is the only node in the list
	if (temp != nullptr)
	{
		//If not the only node, set the temporary node's next to null
		temp->setNext(nullptr);
	} else
	{
		//If it is the only node, set front to null
		front = nullptr;
	}

	//Delete and free the memory used for the node in the back
	delete back;

	//Set back to temp
	back = temp;
}

//Traverse the list from front to back, printing each value
void dblLinkList::traverseFront()
{
	//Create a node for traversing through the list, setting it first to the front node
	Node * current = front;

	//Check if the list is empty
	if (current != nullptr)
	{
		//While the traversing node is not null, print the value of the current node
		while (current != nullptr)
		{
			std::cout << current->getVal()->getName() << std::endl;

			//Set the traversing node to the next node in the list
			current = current->getNext();
		}
	} else
	{
		std::cout << "The list is empty!";
	}

	std::cout << std::endl;

}

//Traverse the list from back to front, printing each value
void dblLinkList::traverseBack()
{
	//Create a node for traversing through the list, setting it first to the back node
	Node * current = back;

	//Check if the list is empty
	if (current != nullptr)
	{
		//While the traversing node is not null, print the value of the current node
		while (current != nullptr)
		{
			std::cout << current->getVal()->getName() << std::endl;

			//Set the traversing node to the previous node in the list
			current = current->getPrev();
		}
	}
	else
	{
		std::cout << "The list is empty!";
	}

	std::cout << std::endl;

}

//Get the front node
Character * dblLinkList::getFront()
{
	return front->getVal();
}

//Get the back node
Character * dblLinkList::getBack()
{
	return back->getVal();
}


//Delete a list
void dblLinkList::deleteList()
{
	//Delete all nodes remaining in the list
	while (front != nullptr)
	{
		delete front->getVal();
		deleteFront();
	}
}

//Destructor
dblLinkList::~dblLinkList()
{
	//Delete all nodes remaining in the list
	while (front != nullptr)
	{
		delete front->getVal();
		deleteFront();
	}
}