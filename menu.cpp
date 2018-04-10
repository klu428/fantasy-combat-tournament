/********************
** Author: Kelvin Lu
** Date: 11/13/2017
** Description: This is the implementation file for the menu functions for project 4.
********************/

#include "menu.hpp"

int main()
{
	Player p1;
	Player p2;
	dblLinkList losers;
	int again;
	int firstChoice;
	int round = 1;

	srand(time(NULL));

	firstChoice = twoOptionMenu("Play", "Exit");

	//If user wants to quit, return immediately
	if (firstChoice == 2)
	{
		return 0;
	}

	do {

		//Set points to 0
		p1.points = 0;
		p2.points = 0;

		//Choose number of characters in team A
		std::cout << "How many characters in team A? ";
		int teamNumber = validatePositive();

		for (int i = 1; i <= teamNumber; i++)
		{
			std::cout << "Choose character " << i << ": " << std::endl;
			p1.characters.addBack(characterMenu());
		}

		//Choose number of characters in team B
		std::cout << std::endl << "How many characters in team B? ";
		teamNumber = validatePositive();

		for (int j = 1; j <= teamNumber; j++)
		{
			std::cout << "Choose character " << j << ": " << std::endl;
			p2.characters.addBack(characterMenu());
		}

		std::cout << std::endl;

		std::cout << "Game Start!" << std::endl << std::endl;

		while (!p1.characters.isEmpty() && !p2.characters.isEmpty()) {

			//Introduce fighters
			std::cout << "Round " << round << ": Team A ";
			introduceFighter(&p1);
			std::cout << " vs. Team B ";
			introduceFighter(&p2);
			std::cout << std::endl << std::endl;

			//Combat
			while (p1.characters.getFront()->getStrength() > 0 && p2.characters.getFront()->getStrength() > 0)
			{
				std::cout << "Team A attack: " << std::endl;
				p1.atk = p1.characters.getFront()->attack();
				std::cout << std::endl << "Team B defense: " << std::endl;
				p2.characters.getFront()->defense(p1.atk);

				std::cout << std::endl;

				if (p2.characters.getFront()->getStrength() > 0)
				{
					std::cout << "Team B attack: " << std::endl;
					p2.atk = p2.characters.getFront()->attack();
					std::cout << std::endl << "Team A defense: " << std::endl;
					p1.characters.getFront()->defense(p2.atk);
				}

				std::cout << std::endl;
			}

			//Determine the winner
			if (p1.characters.getFront()->getStrength() > 0)
			{
				std::cout << "Team A ";
				introduceFighter(&p1);
				losers.addFront(p2.characters.getFront());
				p2.characters.deleteFront();
				p1.characters.addBack(p1.characters.getFront());
				p1.characters.deleteFront();
				p1.characters.getBack()->recovery();
				p1.points++;
			}
			else
			{
				std::cout << "Team B ";
				introduceFighter(&p2);
				losers.addFront(p1.characters.getFront());
				p1.characters.deleteFront();
				p2.characters.addBack(p2.characters.getFront());
				p2.characters.deleteFront();
				p2.characters.getBack()->recovery();
				p2.points++;

			}

			std::cout << " wins!" << std::endl << std::endl;

			round++;

		}

		std::cout << "Team A points: " << p1.points << std::endl;
		std::cout << "Team B points: " << p2.points << std::endl;

		//Determine winner
		if (p1.points > p2.points)
		{
			std::cout << "Team A wins!" << std::endl;
		}
		else if (p2.points > p1.points)
		{
			std::cout << "Team B wins!" << std::endl;
		}
		else
		{
			std::cout << "Draw Game!" << std::endl;
		}

		std::cout << std::endl;

		//Display loser's pile depending on user's input
		std::cout << "Display Losers pile?" << std::endl;
		if (twoOptionMenu("Yes", "No") == 1)
		{
			std::cout << std::endl << "Loser's Pile:" << std::endl;
			losers.traverseFront();
		}

		std::cout << std::endl;

		//Deallocate memory
		p1.characters.deleteList();
		p2.characters.deleteList();
		losers.deleteList();

		//Ask to play again
		again = twoOptionMenu("Play again", "Exit");

	} while (again == 1);

}


//Choose a character
Character * characterMenu()
{
	Character * character;
	std::string name;

	//Have user choose a character
	std::cout << "1. Vampire" << std::endl;
	std::cout << "2. Barbarian" << std::endl;
	std::cout << "3. Blue Men" << std::endl;
	std::cout << "4. Medusa" << std::endl;
	std::cout << "5. Harry Potter" << std::endl;
	std::cout << "Please enter your choice: ";
	int charChoice = validatePositiveRange(1, 5);

	std::cout << "Please enter the character's name: ";
	getline(std::cin, name);

	//Allocate memory for the character
	switch (charChoice)
	{
	case 1:
		character = new Vampire(name);
		break;
	case 2:
		character = new Barbarian(name);
		break;
	case 3:
		character = new Blue_Men(name);
		break;
	case 4:
		character = new Medusa(name);
		break;
	case 5:
		character = new Harry_Potter(name);
	}

	//Return the chosen character as a pointer
	return character;
}


//Introduce Fighters
void introduceFighter(Player * team)
{
	if (typeid(Vampire) == typeid(*team->characters.getFront()))
	{
		std::cout << "Vampire ";
	}
	else if (typeid(Barbarian) == typeid(*team->characters.getFront()))
	{
		std::cout << "Barbarian ";
	}
	else if (typeid(Blue_Men) == typeid(*team->characters.getFront()))
	{
		std::cout << "Blue Men ";
	}
	else if (typeid(Medusa) == typeid(*team->characters.getFront()))
	{
		std::cout << "Medusa ";
	}
	else if (typeid(Harry_Potter) == typeid(*team->characters.getFront()))
	{
		std::cout << "Harry Potter ";
	}

	std::cout << team->characters.getFront()->getName();
}


//Two option menu with input validation
int twoOptionMenu(std::string a, std::string b)
{
	std::cout << "1. " << a << std::endl;
	std::cout << "2. " << b << std::endl;
	std::cout << "Please enter your choice: ";
	return validatePositiveRange(1, 2);
}

//Function to get a user's input and check if it is a positive integer. It will return the integer if valid.
int validatePositive()
{
	std::string input;
	bool again;

	//Loop endlessly until user provides a valid input
	do
	{
		getline(std::cin, input);
		again = false;
		//If first character is 0 or the string is null, print error and have user re-enter input
		if (input.length() == 0 || input[0] == '0')
		{
			again = true;
		}

		//If any character is non-numerical, print error and have user re-enter input
		if (!again)
		{
			for (int i = 0; i < static_cast<int>(input.length()); i++)
			{
				if (!isdigit(input[i]))
				{
					again = true;
				}
			}
		}

		//If input passes all of the tests, return the input as an integer
		if (!again)
		{
			return stoi(input);
		}

		//If input did not pass all the tests, have user try again
		std::cout << "Invalid format- Please enter a positive integer: ";
	} while (again);

	//function should never reach here, but if it does restart
	return validatePositive();
}

//Validates an input is a positve integer within the specified range
int validatePositiveRange(int lower, int upper)
{
	int input;
	bool rangeAgain = true;

	//Loop endlessly until user provides a valid input
	do
	{
		//validate input is a positive integer
		input = validatePositive();

		//Return input if input is within range
		if (input >= lower && input <= upper)
		{
			return input;
		}

		//If not, display this error message and prompt the user to try again
		std::cout << "Not in range- Please enter an integer between " << lower << " and " << upper << ": ";
	} while (rangeAgain);

	//function should never reach here, but if it does restart
	return validatePositiveRange(lower, upper);
}