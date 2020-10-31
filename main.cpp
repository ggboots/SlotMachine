#include <iostream>
#include <string> 
#include <cstdlib> //System,rand Functions
#include <ctime>  //time func
#include <conio.h> //more system functions
//#include <termcolor.h> //color in Program
using namespace std;

// Constants for menu choices and limit
enum MenuChoice {
	PLAY = 1,
	EXIT = 2,
	CREDITS = 3,
	CHOICES_END
};
//Random Func
int randInRange(int rangeMax)
{
	int ranged = (rand() % rangeMax) + 2; //Random number between 2 and 7
	return ranged;
}


// Display main menu screen, shows current cash left.
// Returns choice (valid checked againt MenuChoice)
int displayMenuScreen(int cash)
{
	bool validChoice = false;
	int choice = 0;
	string error = "";

	while (!validChoice)
	{
		cout << "\t" << " | | | | | | | | | | | | | | | " << endl;
		cout << "\n\t\t" << "   LUCKY 38 " << endl;
		cout << "\t\t" << "You have $" << cash << endl;
		cout << "\t" << " | | | | | | | | | | | | | | | " << endl<< endl;
		cout << "\n\t\t" << "1: Play" << endl;
		cout << "\t\t" << "2: Exit" << endl;
		cout << "\t\t" << "3: Credits\n" << endl << endl;

		if (!error.empty()) // If Player enters invalid number or character
		{
			cout << "\t" << "ERROR, try again" << endl;
		}

		cout << "\t" << "Enter your choice > ";
		cin >> choice;


		if (choice > 0 && choice < MenuChoice::CHOICES_END)
		{
			validChoice = true;
		}
		else
		{
			error = 1; // Display Error message
			system("cls"); 
		}

	}
	return choice;
}


// Play Slots Screen
// Requires the Player's cash amount to begin play.
// Returns cash left after their bet, based on win/loss
int playSlots(int playerCash)
{
	int rand1;
	int rand2;
	int rand3;
	int bet;
	cout << "\n\t ----- Lucky 38 ----- " << endl;
	cout << "\tMaximum bets: $100" << endl;
	
	// Bet placed by user, also checks that bet is legal
	bet = 0;
	do 
	{
		cout << "\t\t$"; cin >> bet;
		if (bet > 101) {
			cout << "\n Invalid Amount, try again" << endl;
		}
		else {

		}
	} while (bet > 101);


	// Slot machine spins
	cout << "\n\tPress any key to spin \n" << endl;
	_getch();
	rand1 = randInRange(6); //Has to be one more up, as modulous would round up
	rand2 = randInRange(6);
	rand3 = randInRange(6);

	cout << "\t\t" << rand1 << " " << rand2 << " " << rand3 << "\n" << endl;

	if (rand1 + rand2 + rand3 == 21) {  //10x if all numbers are 7
		bet = bet * 10;
		cout << "\n\tVery nice, that's $" << bet <<" In the bank"<< endl;
		playerCash = playerCash + bet;
		cout << "\n\t Your Total is $" + playerCash << endl;
	}
	// 5x bet
	else if ((rand1 == rand2)&&(rand1==rand3)) { //5x if all numbers are same 
		bet = bet * 5;
		cout << "\n\tHIGH 5, You made $"<< bet << endl;
		playerCash = playerCash + bet;
		cout << "\n\n\tYour Total: $" << playerCash << endl;
	} 
	// 3X bet
	else if ((rand1 == rand2) && (rand1 != rand3)) { // 3x two are same out of three
		bet = bet * 3;
		cout << "\n\twow wow wee wow $" << bet << endl;
		playerCash = playerCash + bet;
		cout << "\tYour Total: $" << playerCash << endl;
	}
	else if ((rand1 == rand3) && (rand1 != rand2)) {
		bet = bet * 3;
		cout << "\n\tWOW WOW WEE WOW $" << bet << endl;
		playerCash = playerCash + bet;
		cout << "\tYour Total: $" << playerCash << endl;
	}
	else if ((rand2 == rand3) && (rand2 != rand1)) {
		bet = bet * 3;
		cout << "\n\tWoW WoW Wee WoW $" << bet << endl;
		playerCash = playerCash + bet;
		cout << "\tYour Total: $" << playerCash << endl;
	}
	else { // lose bet
		cout << "\n\tYou lose $" << bet << endl;
		playerCash = playerCash - bet;
		cout << "\tYour Total: $" << playerCash << endl;
	}
	_getch();
	return playerCash;
}




// Display Credits Screen
// 
void displayCreditsScreen()
{
	cout << "\n --- Made by George Boots" << endl;
	cout << "\n\n\n Press any key to return" << endl;
	_getch();
	system("cls");
	return;
}
// Display Exit Screen
//
void displayExitScreen()
{
	cout << "\n See you next time at the Lucky 38"<< endl << endl;
	cout << "\n Thank you for Playing :) " << endl << endl;
	return;
}


// Main Program
//
int main()
{
	// declaring var
	const int STARTING_CASH = 2000;
	int cashLeft = STARTING_CASH;
	int choice = 0;
	
	// seeding rand func
	int seed = time(NULL);
	srand(seed);

	do
	{
		// Main Menu
		system("cls");
		choice = displayMenuScreen(cashLeft);

		//Play Slots
		if (choice == 1) 
		{
			system("cls");
			cashLeft = playSlots(cashLeft);
		}
		// Credits Screen
		else if (choice == 3) 
		{
			system("cls");
			displayCreditsScreen();
		}

	} while (choice != 2);

	// Exit Screen
	system("cls");
	displayExitScreen();
	return 0;
}