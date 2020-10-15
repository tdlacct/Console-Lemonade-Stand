#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "recipe.h"

class Player {
public:

	

public:

	int index;
	LemonadeRecipe PlayerRecipe;
	string name;
	int rank;
	bool bankrupt = false;
	

	void IncreaseReputation(float Increase) {
		Reputation += Increase;

		if (Reputation > 0.9) {
			Reputation == 1;
		}
	}

	void AdjustReputation(float Increase) {
		Reputation == Increase;
	}

	void DecreaseReputation(float Decrease) {
		Reputation -= Decrease;

		if (Reputation < 0.1) {
			Reputation == 0;
		}
	}

	float GetReputation() {
		if (Reputation < 0.01) {
			Reputation == 0;
		}

		if (Reputation > 1) {
			Reputation == 1;
		}

		return Reputation;
	}

	void AddMoney(float amount) {
		money += amount;

		if (money > 0) {
			if (bankrupt == true) {
				cout << "\nYou have been saved from bankruptcy!" << endl;
			}
			bankrupt = false;
		}

		//cout << "\nNew balance: " << GetBalance();
	}

	void WithdrawMoney(float amount) {
		money -= amount;

		if (money < 0) {
			money == 0;
			cout << "\nOh no! You've gone bankrupt!" << endl;
			bankrupt = true;
		}

		//cout << "\nNew balance: $" << GetBalance();
	}

	void SellCups() {

	}

	float GetBalance() {
		return money;
	}



private:

	float money = 0;
	float Reputation = 0.9;

};