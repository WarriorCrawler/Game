void F_USE_POTION()
{




	if (PLAYER_HP_POTIONS < 1) //If the character has 0 potions then print the bellow message
	{
		SetConsoleTextAttribute(hConsole, LIGHTRED);
		cout << "You are out of Potions" << endl << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	else
	{
		if (PLAYER_HP == PLAYER_HP_MAX + ARMOR_HP) //If the character's Hp is at max print the following bellow
		{
			SetConsoleTextAttribute(hConsole, LIGHTRED);
			cout << "Your Health is already at its max" << endl << endl;;
			SetConsoleTextAttribute(hConsole, WHITE);
		}
		else //If character's Hp is less than the Max Hp
		{
			//IF when potion used results in creater hp than allowed set it back to the Max Allowed
			if ((PLAYER_HP + (PLAYER_HP_MAX * 20 / 100)) >= PLAYER_HP_MAX + ARMOR_HP) 
			{
				PLAYER_HP = PLAYER_HP_MAX + ARMOR_HP;
			}
			//Increase current character's Hp by 20%
			else
			{
				PLAYER_HP = (PLAYER_HP + ((PLAYER_HP_MAX + ARMOR_HP) * 20 / 100));
			}
			PLAYER_HP_POTIONS--; //Decrease Potion count
			SetConsoleTextAttribute(hConsole, LIGHTGREEN);
			cout << "You have used a potion your Hp is now : " << PLAYER_HP << "/" << PLAYER_HP_MAX + ARMOR_HP << endl << endl; //Display Message to allert Hp Increase
			SetConsoleTextAttribute(hConsole, WHITE);
			F_SAVE();//Call Save Function to apply changes

		}
	}
}