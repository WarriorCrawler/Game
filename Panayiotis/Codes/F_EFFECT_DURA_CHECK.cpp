void F_EFFECT_DURA_CHECK()
{
	int POISON_DAMAGE; //Declaring the variable
	if (CURRENT_EFFECT != NONE)//Check that the player has an effect active
	{
		if (EFFECT_DURATION != 0) //Check that the duration is not 0
		{
			
			if (CURRENT_EFFECT == POISONED) // Do this only when the player is poisoned
			{
				srand(time(NULL)); //Used to not get same results as previous time
				POISON_DAMAGE = (rand() % (PLAYER_HP / 2)); //Generate a random number betweer 0 and the half of
															// the players HP
				if (PLAYER_HP - POISONED <= 5) //If the damage done is putting the players hp to to less or equal to
												// 5 then change the damage to 0
				{
					POISON_DAMAGE = 0;
				}
				PLAYER_HP -= POISON_DAMAGE;//Deal the damage to the player

				if (POISON_DAMAGE != 0) //Display message only if the player took damage
				{
					SetConsoleTextAttribute(hConsole, LIGHTRED);
					cout << "You are cursed and so lost health" << endl << endl;
					SetConsoleTextAttribute(hConsole, WHITE);
				}
				F_SAVE();//Calling the save function to update the changes to the database
			}
			EFFECT_DURATION -= 1; //Decrease the duration by 1
			if (EFFECT_DURATION == 0)//If the effect is now 0
			{
				CURRENT_EFFECT = NONE; //Clear the effect
				EFFECT_DAMAGE_INCREASE = 0; //Clear the additional damage

				//Alert user that the effect has ended
				SetConsoleTextAttribute(hConsole, LIGHTGREEN);
				cout << "The effect has ended" << endl << endl;
				SetConsoleTextAttribute(hConsole, WHITE);

			}
		}
	}
}