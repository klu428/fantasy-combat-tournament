/********************
** Author: Kelvin Lu
** Date: 10/26/2017
** Description: This is the class implementation file for the abstract Character class and each character's class that inherits from the base Character class.
********************/

#include "Characters.hpp"


/********************
** Description: This is the class implementation for the Character class.
********************/

//Recovery Function
void Character::recovery()
{
	strength *= 1.2;
}

/********************
** Description: This is the class implementation for the Vampire class.
********************/

//Constructor
Vampire::Vampire()
{
	name = "Vampire";
	armor = 1;
	strength = 18;
	characteristic = "Suave, debonair, but vicious and surprisingly risilient";
}

//1-Parameter Constructor for setting name
Vampire::Vampire(std::string userName)
{
	name = userName;
	armor = 1;
	strength = 18;
	characteristic = "Suave, debonair, but vicious and surprisingly risilient";
}


//Roll for attack
int Vampire::attack()
{
	int atk = rand() % 12 + 1;
	std::cout << "Vampire " << getName() << " rolled a " << atk << " for attack!" << std::endl;
	return atk;
}

//Roll for defense
void Vampire::defense(int atk)
{
	std::cout << "Vampire " << getName() << " has " << getArmor() << " armor and " << getStrength() << " strength points" << std::endl;
	if (rand() % 2)
	{
		std::cout << "Vampire " << getName() << " charmed the foe, causing the foe to stop their attack!" << std::endl;
	}
	else if (atk == -1)
	{
		setStrength(0);
		std::cout << "Vampire " << getName() <<"'s strength points instantly becomes " << strength << std::endl;
	}
	else
	{
		int def = rand() % 6 + 1;
		int damage = atk - def - armor;
		std::cout << "Vampire " << getName() << " rolled a " << def << " for defense!" << std::endl;
		std::cout << "Vampire " << getName() <<" takes " << atk << " attack - " << def << " defense - " << armor << " armor for a total of " << damage << " damage!" << std::endl;
		if (damage <= 0)
		{
			std::cout << "The attack was ineffective and Vampire " << getName() << " did not take any damage" << std::endl;
		}
		else
		{
			strength -= damage;
			std::cout << "Vampire " << getName() << "'s strength points has been reduced to " << strength << std::endl;
		}
	}
}


/********************
** Description: This is the class implementation for the Barbarian class.
********************/

//Constructor
Barbarian::Barbarian()
{
	name = "Barbarian";
	armor = 0;
	strength = 12;
	characteristic = "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.";
}

//1-Parameter Constructor
Barbarian::Barbarian(std::string userName)
{
	name = userName;
	armor = 0;
	strength = 12;
	characteristic = "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.";
}

//Roll for attack
int Barbarian::attack()
{
	int atk1 = rand() % 6 + 1;
	int atk2 = rand() % 6 + 1;
	std::cout << "Barbarian " << getName() << " rolled a " << atk1 << " and " << atk2 << " for a total of " << atk1 + atk2 << " attack!" << std::endl;
	return atk1 + atk2;
}

//Roll for defense
void Barbarian::defense(int atk)
{
	std::cout << "Barbarian " << getName() << " has " << getArmor() << " armor and " << getStrength() << " strength points" << std::endl;
	if (atk == -1)
	{
		setStrength(0);
		std::cout << "Barbarian " << getName() << "'s strength points instantly becomes " << strength << std::endl;
	}
	else
	{
		int def1 = rand() % 6 + 1;
		int def2 = rand() % 6 + 1;
		int totaldef = def1 + def2;
		int damage = atk - totaldef - armor;
		std::cout << "Barbarian " << getName() << " rolled a " << def1 << " and " << def2 << " for a total of " << totaldef << " defense!" << std::endl;
		std::cout << "Barbarian " << getName() << " takes " << atk << " attack - " << totaldef << " defense - " << armor << " armor for a total of " << damage << " damage!" << std::endl;
		if (damage <= 0)
		{
			std::cout << "The attack was ineffective and Barbarian " << getName() << " did not take any damage" << std::endl;
		}
		else
		{
			strength -= damage;
			std::cout << "Barbarian " << getName() << "'s strength points has been reduced to " << strength << std::endl;
		}
	}
}


/********************
** Description: This is the class implementation for the Blue Men class.
********************/

//Constructor
Blue_Men::Blue_Men()
{
	name = "Blue Men";
	armor = 3;
	strength = 12;
	characteristic = "They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies’ armor or clothing.";
}

//1-Parameter Constructor
Blue_Men::Blue_Men(std::string userName)
{
	name = userName;
	armor = 3;
	strength = 12;
	characteristic = "They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies’ armor or clothing.";
}

//Roll for attack
int Blue_Men::attack()
{
	int atk1 = rand() % 10 + 1;
	int atk2 = rand() % 10 + 1;
	std::cout << "Blue Men " << getName() << " rolled a " << atk1 << " and " << atk2 << " for a total of " << atk1 + atk2 << " attack!" << std::endl;
	return atk1 + atk2;
}

//Roll for defense
void Blue_Men::defense(int atk)
{
	std::cout << "Blue Men " << getName() << " have " << getArmor() << " armor and " << getStrength() << " strength points" << std::endl;
	if (atk == -1)
	{
		setStrength(0);
		std::cout << "Blue Men " << getName() << "'s strength points instantly becomes " << strength << std::endl;
	}
	else
	{
		int def1 = rand() % 6 + 1;
		int def2 = rand() % 6 + 1;
		int def3 = rand() % 6 + 1;
		int totaldef;
		int damage;

		if (getStrength() > 8)
		{
			totaldef = def1 + def2 + def3;
			damage = atk - totaldef - armor;
			std::cout << "Blue Men " << getName() << " rolled a " << def1 << ", " << def2 << ", and " << def3 << " for a total of " << totaldef << " defense!" << std::endl;
		}
		else if (getStrength() > 4)
		{
			totaldef = def1 + def2;
			damage = atk - totaldef - armor;
			std::cout << "Blue Men " << getName() << " rolled a " << def1 << " and " << def2 << " for a total of " << totaldef << " defense!" << std::endl;
		}
		else
		{
			totaldef = def1;
			damage = atk - totaldef - armor;
			std::cout << "Blue Men " << getName() << " rolled a " << def1 << " for a total of " << totaldef << " defense!" << std::endl;
		}

		std::cout << "Blue Men " << getName() << " takes " << atk << " attack - " << totaldef << " defense - " << armor << " armor for a total of " << damage << " damage!" << std::endl;
		if (damage <= 0)
		{
			std::cout << "The attack was ineffective and Blue Men " << getName() << " did not take any damage" << std::endl;
		}
		else
		{
			strength -= damage;
			std::cout << "Blue Men " << getName() << "'s strength points has been reduced to " << strength << std::endl;
		}
	}
}


/********************
** Description: This is the class implementation for the Medusa class.
********************/

//Constructor
Medusa::Medusa()
{
	name = "Medusa";
	armor = 3;
	strength = 8;
	characteristic = "Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!";
}

//1-Parameter Constructor
Medusa::Medusa(std::string userName)
{
	name = userName;
	armor = 3;
	strength = 8;
	characteristic = "Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!";
}

//Roll for attack
int Medusa::attack()
{
	int atk1 = rand() % 6 + 1;
	int atk2 = rand() % 6 + 1;
	int totalatk = atk1 + atk2;
	if (totalatk == 12)
	{
		std::cout << "Medusa " << getName() << " rolled a " << totalatk << " , so she uses her special ability, Glare, to turn the foe to stone!" << std::endl;
		return -1;
	}
	std::cout << "Medusa " << getName() << " rolled a " << atk1 << " and " << atk2 << " for a total of " << atk1 + atk2 << " attack!" << std::endl;
	return totalatk;
}

//Roll for defense
void Medusa::defense(int atk)
{
	std::cout << "Medusa " << getName() << " has " << getArmor() << " armor and " << getStrength() << " strength points" << std::endl;
	if (atk == -1)
	{
		setStrength(0);
		std::cout << "Medusa " << getName() << "'s strength points instantly becomes " << strength << std::endl;
	}
	else
	{
		int def = rand() % 6 + 1;
		int damage = atk - def - armor;
		std::cout << "Medusa " << getName() << " rolled a " << def << " for defense!" << std::endl;
		std::cout << "Medusa " << getName() << " takes " << atk << " attack - " << def << " defense - " << armor << " armor for a total of " << damage << " damage!" << std::endl;
		if (damage <= 0)
		{
			std::cout << "The attack was ineffective and Medusa " << getName() << " did not take any damage" << std::endl;
		}
		else
		{
			strength -= damage;
			std::cout << "Medusa " << getName() << "'s strength points has been reduced to " << strength << std::endl;
		}
	}
}


/********************
** Description: This is the class implementation for the Harry Potter class.
********************/

//Constructor
Harry_Potter::Harry_Potter()
{
	name = "Harry Potter";
	armor = 0;
	strength = 10;
	lifeUsed = false;
	characteristic = "Harry Potter is a wizard.";
}

//1-ParameterConstructor
Harry_Potter::Harry_Potter(std::string userName)
{
	name = userName;
	armor = 0;
	strength = 10;
	lifeUsed = false;
	characteristic = "Harry Potter is a wizard.";
}

//Roll for attack
int Harry_Potter::attack()
{
	int atk1 = rand() % 6 + 1;
	int atk2 = rand() % 6 + 1;
	std::cout << "Harry Potter " << getName() << " rolled a " << atk1 << " and " << atk2 << " for a total of " << atk1 + atk2 << " attack!" << std::endl;
	return atk1 + atk2;
}

//Roll for defense
void Harry_Potter::defense(int atk)
{
	std::cout << "Harry Potter " << getName() << " has " << getArmor() << " armor and " << getStrength() << " strength points" << std::endl;
	if (atk == -1)
	{
		setStrength(0);
		std::cout << "Harry Potter " << getName() << "'s strength points instantly becomes " << strength << std::endl;
	}
	else
	{
		int def1 = rand() % 6 + 1;
		int def2 = rand() % 6 + 1;
		int totaldef = def1 + def2;
		int damage = atk - totaldef - armor;
		std::cout << "Harry Potter " << getName() << " rolled a " << def1 << " and " << def2 << " for a total of " << totaldef << " defense!" << std::endl;
		std::cout << "Harry Potter " << getName() << " takes " << atk << " attack - " << totaldef << " defense - " << armor << " armor for a total of " << damage << " damage!" << std::endl;
		if (damage <= 0)
		{
			std::cout << "The attack was ineffective and Harry Potter " << getName() << " did not take any damage" << std::endl;
		}
		else
		{
			strength -= damage;
			std::cout << "Harry Potter " << getName() << "'s strength points has been reduced to " << strength << std::endl;
		}
	}

	if (strength <= 0 && !lifeUsed)
	{
		strength = 20;
		std::cout << "Harry Potter " << getName() << " uses Hogwarts to come back to life with " << strength << " strength points!" << std::endl;
		lifeUsed = true;
	}
}

