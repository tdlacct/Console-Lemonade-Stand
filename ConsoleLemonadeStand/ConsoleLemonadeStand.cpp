// ConsoleLemonadeStand.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "recipe.h"
#include "user.h"
#include "Day.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iomanip> 
#include "Events.h"


using namespace std;

int main()
{
	cout << setprecision(4) << endl;
	cout << "LEMONDOS: THE LEMONADE STAND SIMULATOR" << endl;
	cout << "_______________________________________\n" << endl;

	cout << "Welcome to LEMONDOS, a Command Prompt based simulation program written in C++. \nThe goal of this game is to sell more lemonade than your Math Cru competitors." << endl;
	cout << "Of course, you'll have to make smart business decisions to win. Don't worry, it's easy enough to do." << endl;
	cout << "" << endl;
	cout << "GAME SETUP" << endl;
	cout << "_______________________________________\n" << endl;

	cout << "How many days would like to play for?" << endl;

	int days;
	cin >> days;

	cout << "How many teams?" << endl;
	int Players = 0;
	
	int Value = Players;

	cin >> Players;

	
	
	Player* User = new Player[Players];

	

	for (int i = 0; i < Players; i++) {
		string name;
		cout << "What is your name team " << i + 1 << "?" << endl;
		cin >> name;
		cout << endl;
		User[i].name = name;
		srand(time(0));
		User[i].AddMoney(rand() % 6 + 14);
		cout << User[i].name << ", you have been given $" << User[i].GetBalance() << " by your parents. Spend it wisely. \n" << endl;
	}
	
	

	for (int i = 0; i < Players; i++) {
		system("cls");
		cout << endl;
		cout << User[i].name << " please build your recipe." << endl;
		User[i].PlayerRecipe.BuildRecipe();

		char Answer = 'A';
		
		
		
		cout << "Your lemonade stand has been set up for the day \n\n\n" << endl;
		system("pause");
		
		
		

		

	}



	Day TimeSystem(0, User);


	while (TimeSystem.index <= days) {
		

		for (int i = 0; i < Players; i++) {
			if (User[i].GetBalance() < 0.01) {
				User[i].bankrupt = true;
			}

			if (User[i].bankrupt == true) {
				cout << User[i].name << " is bankrupt. They can not sell lemonade." << endl;
				system("pause");
				continue;
		}

		char Answer = 'A';
		system("cls");
		do {

			cout << User[i].name << "'s Turn" << endl;
			cout << "_______________________________________\n\n" << endl;
			TimeSystem.Display();

	
			if (User[i].GetReputation() > 0.9) {
				cout << "Current reputation is good!" << endl;
			}

			else if (User[i].GetReputation() < 0.2) {
				cout << "Current reputation is horrible! Something needs to be done quickly!" << endl;
			}

			else {
				cout << "Current reputation is average. Try adjusting your recipe or doing something unexpected." << endl;
			}

			//cout << "Current reputation: " << User[i].GetReputation() * 100 << " percent positive, " << 100 - (User[i].GetReputation() * 100) << " percent negative." << endl;
			cout << "Would you like to edit your recipe, " << User[i].name << "? (y/n)" << endl;
			cin >> Answer;

			if (Answer == 'y') {
				User[i].PlayerRecipe.BuildRecipe();
				break;
			}
			
		} while (Answer != 'n');

		do {

			do {
				cout << "You have $" << User[i].GetBalance() << " to spend." << endl;
				cout << "How many gallons of lemonade would you like to make (1 gallon is sixteen cups)?" << endl;
				cin >> User[i].PlayerRecipe.CupsToMake;

				if (User[i].PlayerRecipe.CupsToMake * User[i].PlayerRecipe.TotalCost() > User[i].GetBalance()) {
					cout << "You do not have enough money for that many gallons!" << endl;
				}
			} while (User[i].PlayerRecipe.CupsToMake * User[i].PlayerRecipe.TotalCost() > User[i].GetBalance());

			cout << User[i].name << ", the total cost of your lemonade is $" << User[i].PlayerRecipe.CupsToMake * User[i].PlayerRecipe.TotalCost() << endl;
			cout << "The number of cups you are selling is " << User[i].PlayerRecipe.CupsToMake * 16 << " cups from " << User[i].PlayerRecipe.CupsToMake << " gallons." << endl;
			cout << "You will have $" << User[i].GetBalance() - (User[i].PlayerRecipe.CupsToMake * User[i].PlayerRecipe.TotalCost()) << " after making lemonade." << endl;

			cout << "Is this okay? (y / n)" << endl;
			cin >> Answer;
			if (Answer != 'y' && Answer != 'n') {
				cout << "Invalid response. Try again." << endl;
			}

		} while (Answer != 'y');

		

		do {
			
			cout << "\nWhat price would you like to charge for a cup of lemonade? Currently each cup sold will cost you $" << User[i].PlayerRecipe.TotalCost() / 16 << endl;
			cout << "\n$";
			cin >> User[i].PlayerRecipe.SellCost;

			if (User[i].PlayerRecipe.SellCost > 1.00) {
				cout << "You can't charge that much for a cup!" << endl;
			}

		} while (User[i].PlayerRecipe.SellCost > 1.00);

		User[i].WithdrawMoney(User[i].PlayerRecipe.CupsToMake * User[i].PlayerRecipe.TotalCost());

		User[i].AddMoney(TimeSystem.EndOfDay(User[i]) * User[i].PlayerRecipe.SellCost);
		
		
			
		}

	
		TimeSystem.Generate();

	}
	
	
	
	
	cout << "\nIt is time to shut down your lemonade stands! A report will now be generated and the winner will be declared!" << endl;
	system("pause");
	cout << "NAME \t BALANCE" << endl;
	cout << "________________________________________" << endl;

	for (int i = 0; i < Players; i++) {
		cout << setprecision(2) << endl;
		cout << User[i].name << "\t " << User[i].GetBalance() <<endl;


	}

	int previous = User[0].GetBalance();
	int winnerindex = 0;
	for (int i = 0; i < Players; i++) {
		if (User[i].GetBalance() > previous) {
			winnerindex = i;
		}

		previous = User[i].GetBalance();
	}

	cout << "\nThe winner is " << User[winnerindex].name << "! Good job! You are the lemonade champion!" << endl;

	return 0;
}

