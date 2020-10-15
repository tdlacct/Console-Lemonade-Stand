#pragma once
#ifndef RandomEvents_H
#define RandomEvents_H

#include <ctime>
#include <iostream>
#include "user.h"

using namespace std;
//Use this command to utilize
/*RandomEvent randomEvent;
	randomEvent.EventSelection(randomEvent.randomNumber);
	*/
class RandomEvent {
public:
	RandomEvent(Player UserTransfer) {
		User = UserTransfer;
	}
public:
	 Player User;

	int randomNumber = Generator();
	int Generator() {
		srand(time(0));
		return (rand() % 5);

	}
	float EventSelection(int randomNumber) {
		
		float Multiplier = 1;
		//cout << "\n\nSomething is happening...\n\n" << endl;
		switch (randomNumber) {
		case 0: {
			std::cout << "Wow! The Math Cru wants lemonade! However, they will only buy your lemonade if you can solve this problem!\n";
			int Number1 = rand() % 100;
			int Number2 = rand() % 100;
			cout << "What is " << Number1 << " multiplied by " << Number2 << "?" << endl;
			int mathans;
			cin >> mathans;
			if (mathans == Number1 * Number2) {
				cout << "That is correct! The Math Cru is impressed by your super math skills!" << endl;
				Multiplier = 1.5;
			}

			else {
				cout << "Oh no! That is wrong! The correct answer was " << Number1 * Number2 << ". \nThey now refuse to buy your lemonade!" << endl;
				Multiplier = 0.5;
			}
			break; }
		case 1: {
			Multiplier = Dog();
			break; }
		case 2: {
			Multiplier = Driver();
			break; }
		case 3: {
			Multiplier = Robber();
			break; }
		case 4: {
			Multiplier = Duck();
			break; }
		}
		return Multiplier;
	}
	float Dog() {
		int answer = 0;
		int SecondProbablity = 0;
		SecondProbablity = rand() % 5;
		do {
			cout << "A dog has approached your stand. It is cute and fluffy, but you can't see that because this is a Command Prompt. \nWould you like to: \n1. Pet the dog \n2.Shoo the dog away \n3. Ignore the dog" << endl;
			cin >> answer;

			if (answer > 3 || answer < 1) {
				cout << "Please enter a valid option: 1, 2, or 3." << endl;
			}
		} while (answer > 3 && answer < 1);

		if (answer == 1) {
			if (SecondProbablity > 2) {
				cout << "The dog is friendly and likes you. Your reputation has increased!" << endl;
				User.IncreaseReputation(0.1);
				system("pause");
				return 1.2;
			}

			else {
				cout << "The dog is mean and bit you! Ouch! " << endl;
				cout << "You now have to close up your lemonade stand early to go get a bandage. You only managed to sell a few cups." << endl;
				
				system("pause");
				return 0.6;
			}
		}

		if (answer == 2) {
			cout << "People saw you shooing the dog away and thought that was mean. Your reputation has decreased." << endl;
			User.DecreaseReputation(0.1);
			system("pause");
			return 0.8;
		}

		if (answer == 3) {
			if (SecondProbablity > 3) {
				cout << "The dog has left. No harm done." << endl;
				return 1;
			}

			else {
				cout << "Gross! The dog got on the table and started drinking out of the pitcher! Now nobody wants your lemonade!" << endl;
				User.DecreaseReputation(0.2);
				system("pause");
				return 0.1;
			}
		}
		//subtract from money
		//money -= someAmount;
	};

	float Driver() {
		int answer = 0;
		int SecondProbablity = 0;
		SecondProbablity = rand() % 5;

		std::cout << "Oh no! Your roommate is pulling out of the parking lot in her car. She is about to hit your lemonade stand! \n";
		do {
			cout << "\nWould you like to: \n1. Try to call your roommate's cell phone \n2.Try to move your stand out of their way \n3. Run!" << endl;
			cin >> answer;

			if (answer > 3 || answer < 1) {
				cout << "Please enter a valid option: 1, 2, or 3." << endl;
			}
		} while (answer > 3 && answer < 1);

		if (answer == 1) {
			if (SecondProbablity > 3) {
				cout << "You called your roommate's phone. 'Hi,' she answers cheerfully, 'Just on my way to the pizza parlor.' \n-SPLAT-\n You couldn't stop her in time. \nShe ran over your table and now you'll have to pay $3.00 to replace your family's pitcher." << endl;
				User.WithdrawMoney(3.00);
				system("pause");
				return 0.3;
			}

			else {
				cout << "You called your roommate's phone. 'Hi,' she answers cheerfully, 'What's that? I'm about to hit your lemonade stand? Well hang on!' \n-SCREEECH-\nShe managed to turn her car just in time. Your stand is saved." << endl;
				system("pause");
				return 1;
			}
		}

		if (answer == 2) {
			if(SecondProbablity > 3) {
				cout << "You try to pull the table away, but it does no good. \nShe still ran over your table and now you'll have to pay $3.00 to replace your family's pitcher." << endl;
				User.WithdrawMoney(3.00);
				User.PlayerRecipe.CupsToMake / 3;
				system("pause");
				return 0.3;
			}
			else {
				cout << "You manage to pull the table away just in time!\nYou watch as your roommate accidently backs into a brick wall, smashing into the apartment building but not your lemonade stand. Thankfully, she's not hurt either." << endl;
				system("pause");
				return 1;
			}
		}

		if (answer == 3) {
			if (SecondProbablity > 3) {
				cout << "You run.\nYou run Faster than you've ever ran before, knowing that your roommate is accelerating towards your table.\nWhen you get back, you find that the table is fine and you were overreacting." << endl;
				system("pause");
				return 0.8;
			}

			else {
				cout << "You run, but a few seconds later you hear a loud crash sound and then see your roommate's car zooming past you. \nYour table can be fixed, but the pitcher that has been in your family for generations is cracked. \nTime to replace it with a $3.00 plastic pitcher from WalMart."<< endl;
				User.WithdrawMoney(3.00);
				User.PlayerRecipe.CupsToMake / 3;
				system("pause");
				return 0.3;
			}
		}
		//subtract from money
		//money -= someAmount;
	};

	float Robber() {

		std::cout << "Oh no! It's a robber! You can tell because he has his black and white robber outfit on! \n";
		int answer = 0;
		int SecondProbablity = 0;
		SecondProbablity = rand() % 5;

		
		do {
			cout << "\nWould you like to: \n1. Give the robber lemonade \n2. Fight the robber \n3. Let the robber take what he wants" << endl;
			cin >> answer;

			if (answer > 3 || answer < 1) {
				cout << "Please enter a valid option: 1, 2, or 3." << endl;
			}
		} while (answer > 3 && answer < 1);
		

		if (answer == 1) {
			if (SecondProbablity > 3) {
				cout << "The robber took your lemonade AND your money! How rude! You lost six dollars!" << endl;
				User.WithdrawMoney(6.00);
				system("pause");
				return 0.3;
			}

			else {
				cout << "It turns out the robber was just somebody cosplaying as the McDonalds Hamburglar. Their amazing costume attracted more people to your stand!" << endl;
				system("pause");
				return 1.3;
			}
		}

			if (answer == 2) {
				int fightanswer = 0;
				cout << "Likely randomizer error" << endl;
				int RobberHealth = 10;
				int YourHealth = 10;

				if (SecondProbablity > 1) {
					cout << "It's time to fight! " << endl;

					do {
						cout << "Your health: " << YourHealth << endl;
						cout << "Robber health: " << RobberHealth << endl;
						do {
							cout << "\nWhat will you do? \n1. Kick \n2. Throw sour lemons \n3. Give up" << endl;
							cin >> fightanswer;

							if (fightanswer > 3 || fightanswer < 1) {
								cout << "Please enter a valid option: 1, 2, or 3." << endl;
							}
						} while (fightanswer > 3 && fightanswer < 1);
						
						int ThirdProbablity = 0;
						ThirdProbablity = rand() % 5;

						int FourthProbablity = 0;
						FourthProbablity = rand() % 5;

						if (fightanswer == 1) {
							if (ThirdProbablity > 2) {
								cout << "SMACK! You kicked the robber! +3 damage!\n" << endl;
								RobberHealth -= 3;
							}

							else {
								cout << "The robber dodged your kick!\n'Do you actually think you can defeat me?' he mocks\n" << endl;
							}
						}

						if (fightanswer == 2) {
							if (ThirdProbablity > 1) {
								cout << "WHACK! You threw a lemon at the robber's face! It's gross and sour! +2 damage!\n" << endl;
								RobberHealth -= 2;
							}

							else {
								cout << "The robber dodged your lemons!\n'When life gives you lemons,' he mocks, 'You dodge them all! Ha ha!'" << endl;
							}
						}


						if (SecondProbablity > 3) {
							cout << "\nThe robber kicked you!\n" << endl;

							if (FourthProbablity > 1) {
								cout << "+2 damage to you!\n" << endl;
								YourHealth -= 2;
							}

							else {
								cout << "The robber missed!\n" << endl;
							}
						}

						else {
							cout << "\nThe robber punched you!" << endl;

							if (FourthProbablity > 2) {
								cout << "+3 damage to you!\n" << endl;
								YourHealth -= 3;
							}

							else {
								cout << "The robber missed!\n" << endl;
							}
						}

						if (fightanswer == 3) {
						cout << "You gave up!" << endl;
						break;
							
						}

					} while (RobberHealth > 1 && YourHealth > 1);

					if (RobberHealth < 1) {
						cout << "'I can't believe I lost,' the robber exclaims, 'You are the true lemonade fighting champion!'\nYour customers were amazed by your RPG-like fighting skills!" << endl;
						return 2;
					}

					else  {
						cout << "The robber won the fight! -KA CHING!- He is now taking almost all of your money!\n'Ha ha ha,' he laughs, 'I can put this money towards my student loans!'\nThe robber runs off" << endl;
						User.WithdrawMoney(User.GetBalance() / 4);
						return 0.2;
					}
				}
				else {
					cout << "It turns out the robber was just somebody cosplaying as the McDonalds Hamburglar, and you just punched them in the face! That's not nice at all! \nYour reputation has dropped considerably!" << endl;
					system("pause");
					User.DecreaseReputation(0.4);
					return 0.4;
				}
			}

			if (answer == 3) {
				if (SecondProbablity > 3) {
					cout << "The robber is stealing money from you! 'This is so easy!' he laughs as he pulls money out of the register.\nThe robber runs off!" << endl;
					User.WithdrawMoney(User.GetBalance() / 3);
					return 0.2;
				}

				else {
					cout << "The robber is drinking all your lemonade!\nGlug... glug... glug\nHe drank nearly a whole gallon!" << endl;
					return 0.8;
				}
			}
		}


		//subtract from money
		//money -= someAmount;

	float Duck() {
		int answer = 0;
		int SecondProbablity = 0;
		SecondProbablity = rand() % 5;
		cout << "A duck walks up to your lemonade stand,\nand he said to the man running the stand:\nHey (Bum, Bum, Bum), got any grapes?" << endl;
		do {
			cout << "\nWould you like to: \n1. Tell the duck you have grapes \n2.Apologize to the duck for lacking grapes \n3. Offer the duck lemonade" << endl;
			cin >> answer;

			if (answer > 3 || answer < 1) {
				cout << "Please enter a valid option: 1, 2, or 3." << endl;
			}

		} while (answer > 3 && answer < 1);

		if (answer == 1) {
			cout << "The duck knows you have no grapes. Your customers know that you have no grapes. Shame on you for lying.\nYour reputation has decreased." << endl;
			User.DecreaseReputation(0.2);
			system("pause");
			return 0.8;
		}

		if (answer == 2) {
			cout << "The duck accepts your apology. Then he waddles away (waddle waddle) 'till the very next day." << endl;
			User.DecreaseReputation(0.1);


			system("pause");
			return 1;
		}

		if (answer == 3) {
			if (SecondProbablity > 3) {
				cout << "The duck refuses and waddles away (waddle waddle)." << endl;

				system("pause");
				return 0.9;
			}

			else {
				cout << "The duck tries your lemonade and loves it! Your reputation has increased!" << endl;
				User.IncreaseReputation(0.2);
				system("pause");
				return 1.2;
			}
		}
	};
};



class WeatherEvent :public RandomEvent {
public:
	WeatherEvent(Player User, int temperaturetransfer, bool israining) :RandomEvent(User) {
		WeatherUser = User;
		temperature = temperaturetransfer;
		rain = israining;
	}
public:
	int temperature;
	Player WeatherUser;
	bool rain;
	

	float WeatherEventSelection(int RandomNumber) {
		
		float Multiplier = 1;
		cout << "\n\nSomething is happening...\n\n" << endl;
		switch (randomNumber) {
		case 0: {
			std::cout << "Normal weather.\n";
			break; }
		case 1: {
			if (rain == true) {
				Multiplier = Rain();
			}

			else if (temperature > 85) {
				Multiplier = Heatwave();
			}
			break; }
		case 2: {
			if (rain == true) {
				Multiplier = Storm();
			}

			else {
				std::cout << "Normal weather.\n";
				Multiplier = 1;
			}
			break; }
		case 3: {
			if (rain == true) {
				Multiplier = Tornado();
			}

			break; }
		case 4: {
			Multiplier = MarketCrash();
			break; }
		}
		return Multiplier;
		
	}

	float Heatwave() {
		cout << "It's hot! Turns out that there is a heatwave today! You're selling more cups than usual!" << endl;
		return 1.5;
	}

	float MarketCrash() {
		int SecondProbablity = 0;
		SecondProbablity = rand() % 5;

		if (SecondProbablity > 2) {
			cout << "Oh no! Because of economic deregulation pushed by corrupt politicians, the market for lemonade has completely crashed!" << endl;
			return 0.2;
		}

		else {

			cout << "Wow! The government is pulling back some of the regulations on the sell of lemonade, allowing you to sell more cups!\n(Although it might only be temporary...)" << endl;
			return 1.4;
		}

	}



	float Rain() {
		cout << "Rain noises..." << endl;
		cout << "OH NO! IT IS RAINING!" << endl;
		cout << "Nobody wants lemonade now!" << endl;
		return 0;
	}

	float Storm() {
		int SecondProbablity = 0;
		SecondProbablity = rand() % 5;
		int answer = 0;
		cout << "\nRUMBLE...\nThe weather is getting really bad...\n" << endl;
		do {
			cout << "\nWould you like to: \n1. Continue selling lemonade \n2. Clean up for the day." << endl;
			cin >> answer;

			if (answer > 3 || answer < 1) {
				cout << "Please enter a valid option: 1, 2, or 3." << endl;
			}
		} while (answer > 2 && answer < 1);

		if (answer == 1) {
			if (SecondProbablity > 3) {
				cout << "Oh no! It is raining! \nKA-BOOOOM!\nOh no! Lightning just struck your table, destroying your lemonade and catching the tablecloth on fire!\nYou'll need to pay $2.00 for a new tablecloth!" << endl;
				WeatherUser.WithdrawMoney(2.00);
				return 0;
			}

			else {
				cout << "You managed to keep your lemonade stand open despite the weather. Be warned, the risk won't always pay off." << endl;
				return 0.7;
			}
		}
		
		if (answer == 2) {
			
				cout << "You packed up your lemonade stand for the day. You only managed to sell half as many cups as you normally would." << endl;
				return 0.4;
		}
	
	}

	float Tornado() {
		int SecondProbablity = 0;
		SecondProbablity = rand() % 5;
		int answer = 0;
		cout << "Oh no! It is getting really humid and the sky is a weird shade. There might be a possibility of... a tornado!" << endl;
		do {
			cout << "\nWould you like to: \n1. Continue selling lemonade \n2. Clean up quickly and take shelter!" << endl;
			cin >> answer;

			if (answer > 3 || answer < 1) {
				cout << "Please enter a valid option: 1 or 2." << endl;
			}
		} while (answer > 2 && answer < 1);

		if (answer == 1) {
			if (SecondProbablity > 2) {
				cout << "Oh no! The tornado is here!\n Run! Everything is being destroyed!\nYour lemonade stand just got sucked up!\n You'll need to pay twelve dollars to buy a new stand!" << endl;
				WeatherUser.WithdrawMoney(12.00);
				return 0;
			}

			else {
				cout << "Wow. Running a lemonade stand during a tornado watch is a serious safety hazard. You're lucky that nothing bad happened.\nSadly, most of your customers took shelter instead of buying your lemonade." << endl;
				return 0.2;
			}
			if (answer == 2) {
				if (SecondProbablity > 3) {
					cout << "It turns out there was a tornado! In a lucky twist, however, your customers took shelter with you!\nYou were able to sell them lemonade while they feared for their life!" << endl;

					return 1.3;
				}

				else {
					cout << "There wasn't a tornado, but better safe than sorry. You still managed to sell a few cups before taking shelter." << endl;
					return 0.4;
				}
			}
		}
		
	}


};

#endif#pragma once
