#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "recipe.h"
#include "user.h"
#include "Events.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Day {
public:
	Day(int indexnumber, Player UserTransfer[]) {
		index = indexnumber;
		UserTransfer = Users;
		Generate();
	}

public:
	string weather;
	int index;
	int seed;
	float seedpercent;
	int chanceofrain = 0;
	int actualrain = 0;
	bool isRaining;
	Player Users[];

	void Generate() {
		chanceofrain = 0;
		actualrain = 0;
		isRaining = false;

		++index;
		srand(time(0));
		seed = rand() % 40 + 60;
		seedpercent = seed * 0.01;
		if (seed > 90) {
			weather = "hot and dry";
		}
		else if (seed < 90 && seed > 80) {
			weather = "sunny";
		}

		else if (seed < 80 && seed > 70) {
			weather = "cloudy";
			chanceofrain = rand() % 20 + 80;
			chanceofrain /= 2;
		}
		else if (seed < 70) {
			weather = "windy and cold";
			chanceofrain = rand() % 20 + 80;
		}
	}

	void Display() {
		cout << "\n\n DAY " << index << " WEATHER REPORT:" << endl;
		cout << "_______________________________________\n" << endl;
		cout << "The weather is " << weather << endl;
		cout << "Today's temperature is " << seed << endl;
		cout << "There is a " << chanceofrain << " percent chance of rain today." << endl;
		cout << endl;
	}

	float EndOfDay(Player &UserTransfer) {
		
		actualrain = rand() % 1 + 99;
		
		if (actualrain > 100 - chanceofrain) {
			isRaining = true;
		}
		int CupsSold = 0;
		cout << "\n_______________________________________" << endl;
		cout << "STARTING DAY FOR " << UserTransfer.name << endl;
		RandomEvent Event(UserTransfer);
		WeatherEvent WEvent(UserTransfer, seed, isRaining);
		
		
		
		
		CupsSold = ((UserTransfer.PlayerRecipe.CupsToMake * 16) * UserTransfer.GetReputation() * seedpercent);
		CupsSold *= Event.EventSelection(Event.Generator());

		CupsSold *= WEvent.WeatherEventSelection(WEvent.Generator());

		if (CupsSold > UserTransfer.PlayerRecipe.CupsToMake * 16) {

			CupsSold = UserTransfer.PlayerRecipe.CupsToMake * 16;

		}

		if (CupsSold < 0) {

			CupsSold = 0;

		}
		

		cout << "Cups sold: " << CupsSold << endl;

		if (UserTransfer.PlayerRecipe.Lemon > 30 && UserTransfer.PlayerRecipe.Lemon > UserTransfer.PlayerRecipe.Sugar) {
			cout << "The customers do not like your recipe. It is too sour. Your reputation has decreased." << endl;
			UserTransfer.DecreaseReputation(0.1);
		}

		if (UserTransfer.PlayerRecipe.Sugar > 30 && UserTransfer.PlayerRecipe.Sugar > UserTransfer.PlayerRecipe.Lemon) {
			cout << "The customers do not like your recipe. It is too sugary and now hyperactive children are running around yelling. Your reputation has decreased." << endl;
			UserTransfer.DecreaseReputation(0.1);
		}

		else if (UserTransfer.PlayerRecipe.Sugar == 0 || UserTransfer.PlayerRecipe.Sugar == 0) {
			cout << "It seems like you forgot an ingredient in the recipe. Your reputation is suffering because customers feel scammed." << endl;
			UserTransfer.DecreaseReputation(0.1);
		}
		else if (UserTransfer.PlayerRecipe.Sugar < 30 && UserTransfer.PlayerRecipe.Sugar < 30 && UserTransfer.PlayerRecipe.Sugar > 15 && UserTransfer.PlayerRecipe.Sugar > 15) {
			cout << "You have a good recipe! Your reputation has increased!" << endl;
			UserTransfer.IncreaseReputation(0.1);
		}

		if (UserTransfer.PlayerRecipe.SellCost > (UserTransfer.PlayerRecipe.TotalCost() / 16) * 3) {
			cout << "Customers do not like the price of your lemonade. Your reputation has decreased." << endl;
			UserTransfer.DecreaseReputation(0.3);
		}
		system("pause");
		cout << "\n\n" << endl;
		return (int) CupsSold;
	}


};