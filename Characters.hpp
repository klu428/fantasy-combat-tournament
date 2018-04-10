/********************
** Author: Kelvin Lu
** Date: 10/26/2017
** Description: This is the class specification file for the abstract Character class and each character's class that inherits from the base Character class.
********************/


#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP

#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>

class Character
{
protected:
	std::string name;
	int armor;
	int strength;
	std::string characteristic;

public:
	//Armor getter function
	int getArmor() { return armor; }

	//Strength getter function
	int getStrength() { return strength; }

	//Name getter function
	std::string getName() { return name; }

	//Strength setter function
	void setStrength(int str) { strength = str; }

	//Name setter function
	void setName(std::string userName) { name = userName; }

	//Recovery function
	void recovery();

	//Roll for attack
	virtual int attack() = 0;

	//Roll for defense
	virtual void defense(int atk) = 0;



	//Virtual destructor
	virtual ~Character() {}
};


class Vampire : public Character
{
public:
	//Constructor
	Vampire();

	//1-Parameter Constructor for setting name
	Vampire(std::string userName);

	//Roll for attack
	virtual int attack();

	//Roll for defense
	virtual void defense(int atk);

	//Virtual destructor
	virtual ~Vampire() {}
};


class Barbarian : public Character
{
public:
	//Constructor
	Barbarian();

	//1-Parameter Constructor for setting name
	Barbarian(std::string userName);

	//Roll for attack
	virtual int attack();

	//Roll for defense
	virtual void defense(int atk);

	//Virtual destructor
	virtual ~Barbarian() {}
};


class Blue_Men : public Character
{
public:
	//Constructor
	Blue_Men();

	//1-Parameter Constructor for setting name
	Blue_Men(std::string userName);

	//Roll for attack
	virtual int attack();

	//Roll for defense
	virtual void defense(int atk);

	//Virtual destructor
	virtual ~Blue_Men() {}
};

class Medusa : public Character
{
public:
	//Constructor
	Medusa();

	//1-Parameter Constructor for setting name
	Medusa(std::string userName);

	//Roll for attack
	virtual int attack();

	//Roll for defense
	virtual void defense(int atk);

	//Virtual destructor
	virtual ~Medusa() {}
};

class Harry_Potter : public Character
{
private:
	bool lifeUsed;
public:
	//Constructor
	Harry_Potter();

	//1-Parameter Constructor for setting name
	Harry_Potter(std::string userName);

	//Roll for attack
	virtual int attack();

	//Roll for defense
	virtual void defense(int atk);

	//Virtual destructor
	virtual ~Harry_Potter() {}
};
#endif