void F_HUNT_MENU()
{
	
	F_SELECT_MONSTER_ID(PLAYER_LEVEL);  //call select monster function to get new monster

	while (InDialog) //repeat untill player is in this menu
	{
		if (MONSTER_HP > 0) //check to make sure that the monster spwaned hasnt got 0 hp
		{
			int DialogChoice; //declare variable

			//display menu heading in light cyan colour
			SetConsoleTextAttribute(hConsole, LIGHTCYAN);
			cout << "== BATTLE ==" << endl << endl;
			SetConsoleTextAttribute(hConsole, WHITE);

			//display monster attributes and choices
			cout << "A " << MONSTER_NAME << " with HP: " << MONSTER_HP << " has appeared" << endl << endl;
			cout << "0: Battle" << endl;
			cout << "1: Flee" << endl;
			cout << "2: Go to Town" << endl;
			cout << endl;

			//get players choice
			cout << endl << "Choice : ";
			cin >> DialogChoice;
			cout << endl;

			switch (DialogChoice)//carry action based on choice
			{
			case 0://if player chose fight
				system("cls"); //clear screen
				InDialog = false; //change bool state to false to exit the hunting menu
				InCombat = true; //change bool state to true to open the combat menu
				F_COMBAT_MENU(); //call the combat menu
				break;
			case 1://if playser chose to flee
				system("cls"); //clear screen
				F_SELECT_MONSTER_ID(PLAYER_LEVEL);  //call select monster function to get new monster
				break;
			case 2://if player chose to go to town
				system("cls"); //clear screen
				InDialog = false;//change bool state to false to exit the hunting menu
				break;


			}
		}
		else
		{
			F_SELECT_MONSTER_ID(PLAYER_LEVEL);  //call select monster function to get new monster
		}
	}
}