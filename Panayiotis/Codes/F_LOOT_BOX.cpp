void F_LOOT_BOX()
{


	InLoot = true; //set bool state to true to stay in menu
	while (InLoot) //repeat untill player is in menu
	{
		int LootChoice;//declare variable

		//displey menu heading with light cyan colour
		SetConsoleTextAttribute(hConsole, LIGHTCYAN);
		cout << "== LOOT BOX ==" << endl << endl;
		SetConsoleTextAttribute(hConsole, WHITE);

		//display message and choices
		cout << "You have found a Loot Box" << endl << endl;
		cout << "0: Open" << endl;
		cout << "1: Leave" << endl;
		cout << endl;

		//get players choice
		cout << endl << "Choice : ";
		cin >> LootChoice;
		cout << endl;

		switch (LootChoice)//carry action based on players choice
		{
		case 0://if playen chose to open the box
			system("cls");//clear screen
			//set CLI text to yellow
			SetConsoleTextAttribute(hConsole, YELLOW);
			cout << endl;

			srand(time(NULL));//avoids dublicated results
			RAND_PERCENTAGE = rand() % 100; //calculate a random percentage

			if (CURRENT_EFFECT == NONE || CURRENT_EFFECT != NONE) //check that the player will be able
				//to get this loot from the box even if he/she is cursed
			{

				
				if (RAND_PERCENTAGE <= 20) //20% chance to get gold
				{
					srand(time(NULL));//avoids dublicated results

					//get random number of 1/4 th of the current players gold and add it to the
					// GOLD_GAINED variable
					int GOLD_GAINED = rand() % (PLAYER_GOLD * 40 / 100);
					PLAYER_GOLD += GOLD_GAINED; //add the random number of gold to the player

					//alert user he looted gold and the ammount
					cout << "You Looted " << GOLD_GAINED << " Gold" << endl;
				}
				else if (RAND_PERCENTAGE > 20 && RAND_PERCENTAGE <= 40)//20% change to loot 3 potions
				{
					PLAYER_HP_POTIONS += 3; //increase potions by 3

					//alert user that he looted potions
					cout << "You Looted 3 Potion" << endl;
				}
				
			}
			if (CURRENT_EFFECT == NONE) //check to add those effect only if one isnt active
			{
				if (RAND_PERCENTAGE > 40 && RAND_PERCENTAGE <= 60) //20% to get poisoned
				{
					//set the effect
					CURRENT_EFFECT = POISONED;
					EFFECT_DURATION = 3; //set effect duration to 3 turns

					//alert user of the effect
					cout << "You now are " << F_RETURN_EFFECT_NAME(POISONED) << endl;
				}
				else if (RAND_PERCENTAGE > 60 && RAND_PERCENTAGE <= 80)//20% to get no potion effect
				{
					//set the effect
					CURRENT_EFFECT = NO_POTIONS;
					EFFECT_DURATION = 4;//set effect duration to 4 turns

					//alert user of the effect
					cout << "You now have the effect of " << F_RETURN_EFFECT_NAME(NO_POTIONS) << endl;

				}
				else if (RAND_PERCENTAGE > 80 && RAND_PERCENTAGE <= 100)//20% to get additional damage effect
				{
					//set the effect
					CURRENT_EFFECT = DAMAGE_INCREASE;
					EFFECT_DURATION = 3;//set effect duration to 3 turns

					//alert user of the effect
					cout << "You now have the effect of " << F_RETURN_EFFECT_NAME(DAMAGE_INCREASE) << endl;
				}

			}
			//set CLI text to white
			SetConsoleTextAttribute(hConsole, WHITE);
			cout << endl;
			InLoot = false; //change bool state to false to exit menu
			F_SELECT_MONSTER_ID(PLAYER_LEVEL); //call select monster function to get new monster
			break;
		case 1:
			system("cls"); //clear screen
			InLoot = false; //change bool state to false to exit menu
			F_SELECT_MONSTER_ID(PLAYER_LEVEL); //call select monster function to get new monster
			break;
		}
	}


}