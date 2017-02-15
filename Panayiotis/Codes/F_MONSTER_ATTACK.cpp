void F_MONSTER_ATTACK()
{
	int DealDamage; //Declare variable
	if (rand() % 100 < 60) // 60% chance for player to dodge attack 
	{
		
		srand(time(NULL));//avoids dublicated results

		//calculate the damage to do by selecting a random number between attack max and attack min then 
		//subtract players total defence
		DealDamage = ((rand() % ((MONSTER_ATTACK_MAX + 1) - MONSTER_ATTACK_MIN)) + MONSTER_ATTACK_MIN)
			- (PLAYER_DEFENCE + ARMOR_DEFENCE);
		if (PLAYER_HP - DealDamage <= 0)// check to see if player died from attack
		{
			PLAYER_HP = PLAYER_HP_MAX + ARMOR_HP; //restore players hp

			if ((PLAYER_GOLD - MONSTER_GOLD_REWARD) < 0) //check to make sure we wont have negative gold values
			{
				PLAYER_GOLD = 0; // set gold to 0 if negative value
			}
			else//if not negative number reduce players gold by the 
				//reward gold amount
			{
				PLAYER_GOLD -= MONSTER_GOLD_REWARD; 
			}

			if ((PLAYER_EXP - MONSTER_EXP_REWARD) < 0) //check to make sure we wont have negative exp values
			{
				PLAYER_EXP = 0; // set exp to 0 if negative value
			}
			else//if not negative number reduce players exp by the 
				//reward exp amount
			{
				PLAYER_EXP -= MONSTER_EXP_REWARD;
			}

			F_SAVE(); // call save function to save changes made to the character
			F_UPDATE_SCORE(-5); //call updade score to reduce score by 5 points

			//alert player that he was killed
			SetConsoleTextAttribute(hConsole, LIGHTRED);
			cout << "You were killed by " << MONSTER_NAME << " and lost " << MONSTER_EXP_REWARD << " exp, " << MONSTER_GOLD_REWARD << " gold." << endl << endl;
			SetConsoleTextAttribute(hConsole, WHITE);

			InCombat = false;//change bool state to false to exit this menu and go to town menu
			F_TOWN_MENU();


		}
		else // if the damage will not kill the player do the following
		{
			if (DealDamage < 0) // if the damage calculated is a negative number subtract 1 HP from player
								// so not to add hp to player
			{
				PLAYER_HP -= 1;
			}
			else// if damage calculated is not negative deal the damage calculated to the player
			{
				PLAYER_HP -= DealDamage;
			}
			
			//alert player that he got attacked
			SetConsoleTextAttribute(hConsole, LIGHTRED);
			cout << "You were attacked by" << MONSTER_NAME << " your Hp is : " << PLAYER_HP << "/" << PLAYER_HP_MAX + ARMOR_HP << endl << endl;
			SetConsoleTextAttribute(hConsole, WHITE);
			F_SAVE(); // call save function to save current hp in database
		}
	}
	else// if player dodges attack then alert him/her
	{
		SetConsoleTextAttribute(hConsole, LIGHTGREEN);
		cout << "You got lucky and dodged the attack" << endl << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	
}