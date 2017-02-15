void F_QUEST_LOG()
{
	system("cls"); //clear screen
	InQuest = true;//set bool to true to stay in menu
	int Choice;//declare variable
	while (InQuest)//repeat while in menu
	{
		switch (QUEST_STAGE)//display current quest player is at
		{
		case 0://list 1st quest
			//list the quest
			cout << "Welcome to the Fantasy world of Warrior Crawler your first" << endl;
			cout << "quest is to kill the pestering banding that stole my map and thus" << endl;
			cout << "I cannot find my way home will you help me?" << endl << endl;

			//display options
			cout << "0: Yes, Go get map" << endl;
			cout << "1: I have the map here" << endl;
			cout << "2: No leave" << endl;

			//get choice by player input
			cout << endl;
			cout << "Choice: ";
			cin >> Choice;

			switch (Choice)//carry action on players choice
			{
			case 0://if player chose to help
				system("cls");//clear screen
				questing = true; //active questing
				QUEST_MODE = KILL_MODE; //set quest mode
				QUEST_OBJECTIVE = 0; //reset quest objective
				F_LOAD_MONSTER(50); //load the quest mob Map Bandit
				InQuest = false; //close the quest menu
				//InDialog = false; //change bool state to false to exit the hunting menu
				InCombat = true; //change bool state to true to open the combat menu
				F_COMBAT_MENU(); //call the combat menu
				break;
			case 1://if player has the map
				if (questing && QUEST_OBJECTIVE > 0)
				{
					system("cls");// clear screen
					PLAYER_EXP += 20; //reward player with exp
					PLAYER_GOLD += 200; //reward player with 200 gold
					F_UPDATE_SCORE(15); //reward 15 score points
					SetConsoleTextAttribute(hConsole, LIGHTGREEN);
					cout << "You completed the quest and earned 20 exp, 200 gold." << endl << endl;
					SetConsoleTextAttribute(hConsole, WHITE);
					F_LEVEL_CHECK();//call the level check to see if player leved after quest reward
					QUEST_STAGE++;//progress to the next quest
					F_SAVE();//save all changes to the character table

					//reset quest stats
					questing = false;
					QUEST_MODE = NO_MODE;
					QUEST_OBJECTIVE = 0;
					InQuest = false;//exit the menu
					break;
			case 2://if player chose to leave
				system("cls"); //clear CLI
				InQuest = false; //exit quest menu
				break;
				}
			}
		
			break;
		}

	}
	
}