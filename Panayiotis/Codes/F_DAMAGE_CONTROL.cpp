void F_DAMAGE_CONTROL()
{
	if ((MONSTER_HP - DEAL_DAMAGE) <= 0) //check to see if the damage will kill the monster
	{
		MONSTER_HP = 0;//set monster hp to 0
	}
	else// if it will not kill it then do the following
	{
		if (DEAL_DAMAGE <= 0) //if the damage is negative then subtract only 1 hp from player
		{
			MONSTER_HP -= 1;
		}
		else//if the damage is not negative reduce players hp by the calculated damage
		{
			MONSTER_HP -= DEAL_DAMAGE;
		}

		F_EFFECT_DURA_CHECK();//call function to check for any active effects
		F_MONSTER_ATTACK();//call function for the monster to attack
	}

	if (MONSTER_HP <= 0) // if monster is dead then do the following
	{
		//declare variables
		int GoldLuck;
		int ExpLuck;

		if (PLAYER_LUCK > 0) // if the players luck is greater than 0 
		{
			if ((MONSTER_EXP_REWARD * PLAYER_LUCK / 100) == 0)//if percentage calculated is 0 then just aword 1 exp
			{
				ExpLuck = 1;
			}
			else//award additional exp based on the
			//LUCK percentage
			{
				ExpLuck = (MONSTER_EXP_REWARD * PLAYER_LUCK / 100);
			}

			if ((MONSTER_GOLD_REWARD * PLAYER_LUCK / 100) == 0)//if percentage calculated is 0 then just aword 1 gold 
			{
				GoldLuck = 1;
			}
			else//award additional gold based on the
			//LUCK percentage
			{
				GoldLuck = (MONSTER_GOLD_REWARD * PLAYER_LUCK / 100);
			}
		}
		else
		{
			//set variables to 0 if the luck is 0
			ExpLuck = 0;
			GoldLuck = 0;
		}

		//award additional exp,gold
		PLAYER_EXP += MONSTER_EXP_REWARD + ExpLuck;
		PLAYER_GOLD += MONSTER_GOLD_REWARD + GoldLuck;


		F_SAVE(); // call save function to save players gold,exp to database
		F_UPDATE_SCORE(5); //call update score to increase players score by 5

		// alert user he killed the monster
		SetConsoleTextAttribute(hConsole, LIGHTGREEN);
		cout << "You have slaign the " << MONSTER_NAME << " and gained " << MONSTER_EXP_REWARD + ExpLuck << " exp, " << MONSTER_GOLD_REWARD + GoldLuck << " gold";
		SetConsoleTextAttribute(hConsole, WHITE);

		if (rand() % 100 < 25) // 25 % change to award enhancement stone
		{
			PLAYER_ENHANCEMENT_STONES += 1;

			//alert user he found an enhancement stone
			SetConsoleTextAttribute(hConsole, LIGHTMAGENTA);
			cout << " and 1 Enhancement Stone."<< endl << endl;
			SetConsoleTextAttribute(hConsole, WHITE);

		}
		else
		{
			//if he has not found a stone just add a full stop to the alert
			SetConsoleTextAttribute(hConsole, LIGHTGREEN);
			cout << "." << endl << endl;
			SetConsoleTextAttribute(hConsole, WHITE);
		}

		F_LEVEL_CHECK();//call level check to check if the player can progress to level 2
		InCombat = false;//change the bool to false to exit combat menu

		if (rand() % 100 < 10) // 10% change to find loot box
		{
			F_LOOT_BOX();
		}
		else//if not go back to the hunt menu
		{
			F_HUNT_MENU();
		}

	}
}