#pragma once
#include <iostream>
#include <string>

using namespace std;

class LemonadeRecipe {


public:
	string user;
	int Sugar;
	int Water;
	int Lemon;
	int Percentage = 100;
	int CupsToMake;

	float SugarCost = 0.05;
	float WaterCost = 0.01;
	float LemonCost = 0.04;
	float SellCost = 0;

	void BuildRecipe() {
		
		cout << "You need to determine what the ratio of sugar, lemon juice, and water is for one gallon of your recipe." << endl;
		do {
			cout << "What percentage of the recipe is lemon juice? (0-40) \n" << "The cost of lemon juice is $" << LemonCost << " times the percentage" << endl;

			cin >> Lemon;

			if (Lemon > 40 || Lemon < 0) {
				cout << "This is not a valid amount." << endl;
			}
		} while (Lemon > 40 || Lemon < 0);

		do {
			cout << "What percentage of the recipe is sugar? (0-40) \n" << "The cost of sugar is $" << SugarCost << " times the percentage" << endl;
			cin >> Sugar;

			if (Sugar > 40 || Sugar < 0) {
				cout << "This is not a valid amount." << endl;
			}
		} while (Sugar > 40 || Sugar < 0);

		Water = 100 - Lemon - Sugar;

		cout << "The recipe is " << Water << " percent water, " << Sugar << " percent sugar, and " << Lemon << " percent lemon juice. The cost is $" << TotalCost() << endl;



		char Answer = 'A';

		do {
			cout << "Is this okay? (y / n)" << endl;
			cin >> Answer;
			if (Answer != 'y' && Answer != 'n') {
				cout << "Invalid response. Try again." << endl;
			}
		} while (Answer != 'y' && Answer != 'n');

		if (Answer == 'n') {
			BuildRecipe();
		}

		cout << "Your recipe has been constructed." << endl;

	}

	float TotalCost() {
		float total = SugarCostCalc() + LemonCostCalc() + WaterCostCalc();
		return total;
	}


private:
	float SugarCostCalc() {
		return (Sugar * SugarCost);
	}

	float LemonCostCalc() {
		return (Lemon * LemonCost);
	}

	float WaterCostCalc() {
		return (Water * WaterCost);
	}
};