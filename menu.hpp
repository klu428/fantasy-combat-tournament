/********************
** Author: Kelvin Lu
** Date: 11/13/2017
** Description: This is the specification file for the menu functions for project 4.
********************/

#ifndef MENU_HPP
#define MENU_HPP

#include "dblLinkList.hpp"
#include <typeinfo>

struct Player
{
	dblLinkList characters;
	int atk;
	int points;
};

//Choosing a character menu
Character * characterMenu();

//Introduce Fighters
void introduceFighter(Player * team);

//Two option menu with input validation
int twoOptionMenu(std::string a, std::string b);

//Get a user's input and check if it is a positive integer.
int validatePositive();

/*Function to get a user's input and check that it is >=lower and <=upper.
*It will return the integer if valid.
*Precondition: Lower < Upper
*/
int validatePositiveRange(int lower, int upper);

#endif