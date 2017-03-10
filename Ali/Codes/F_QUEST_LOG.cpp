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
			system("cls");//clear screen
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

				}
				break;
			case 2://if player chose to leave
				system("cls"); //clear CLI
				InQuest = false; //exit quest menu
				break;
			}
			break;
		case 1://list 2nd quest
			   //list the quest
			system("cls");//clear screen
			if (PLAYER_LEVEL >= 3)
			{
				cout << "Well hello there " << PLAYER_NAME << " what brings you here? I need to ask you a favour " << endl;
				cout << "as I was walking from the far lands to come to this town I dropped my scrolls all over the place" << endl;
				cout << "sadly I did not manage to pick them all up in time and the monsters have them now" << endl << endl;
				cout << "could you kill them for me and get my Scrolls back ?" << endl;

				//display options
				cout << "0: Yes, I will collect each and every last one of them" << endl;
				cout << "1: I have them here" << endl;
				cout << "2: No, leave me alone" << endl;

				//get choice by player input
				cout << endl;
				cout << "Choice: ";
				cin >> Choice;

				switch (Choice)//carry action on players choice
				{
				case 0://if player chose to help
					system("cls");//clear screen
					questing = true; //active questing
					QUEST_MODE = COLLECT_MODE; //set quest mode
					QUEST_OBJECTIVE = 0; //reset quest objective
					MOB_COUNT = 15; //set the number of minimum trys to be atleast 15
					InQuest = false; //close the quest menu
					InCombat = true; //change bool state to true to open the combat menu
					F_SELECT_MONSTER_ID(PLAYER_LEVEL); //call to select a monster based on the players level
					F_COMBAT_MENU(); //call the combat menu
					break;
				case 1://if player has the map
					if (questing && QUEST_OBJECTIVE == MOB_COUNT)
					{
						system("cls");// clear screen
						PLAYER_EXP += 50; //reward player with exp
						PLAYER_GOLD += 300; //reward player with 300 gold
						F_UPDATE_SCORE(20); //reward 20 score points
						SetConsoleTextAttribute(hConsole, LIGHTGREEN);
						cout << "You completed the quest and earned 50 exp, 300 gold." << endl << endl;
						SetConsoleTextAttribute(hConsole, WHITE);
						F_LEVEL_CHECK();//call the level check to see if player leved after quest reward
						QUEST_STAGE++;//progress to the next quest
						F_SAVE();//save all changes to the character table

								 //reset quest stats
						questing = false;
						QUEST_MODE = NO_MODE;
						QUEST_OBJECTIVE = 0;
						InQuest = false;//exit the menu

					}
					break;
				case 2://if player chose to leave
					system("cls"); //clear CLI
					InQuest = false; //exit quest menu
					break;
				}
			}
			else
			{
				cout << "Your level is too low come back when you level 3 or above" << endl;

				//display options
				cout << "0: Ok i will train more" << endl;

				//get choice by player input
				cout << endl;
				cout << "Choice: ";
				cin >> Choice;

				switch (Choice)//carry action on players choice
				{
				case 0://if the choice was ok i will train more
					system("cls"); //clear CLI
					InQuest = false; //exit quest menu
					break;
				}
			}

			break;
		}
	}

}
