void F_QUEST_PROGRESS()
{
		if (questing) //Check if the player is questing
		{
			switch (QUEST_MODE) //check the quest mode
			{
			case KILL_MODE: //if quest mode is KILL_MODE
				if (MONSTER_NAME == "Map Bandit") //check if correct monster is killed
				{
					if (QUEST_OBJECTIVE == 0) //check to see if he killed the monster
					{
						QUEST_OBJECTIVE++; // increase quest objective by 1

						SetConsoleTextAttribute(hConsole, LIGHTMAGENTA);
						cout << "You have completed the quest go hand it in." << endl << endl;
						SetConsoleTextAttribute(hConsole, WHITE);

					}
					else
					{
						SetConsoleTextAttribute(hConsole, LIGHTMAGENTA);
						cout << "You have already completed the quest hand it in" << endl << endl;
						SetConsoleTextAttribute(hConsole, WHITE);
					}
				}
				break;
			case COLLECT_MODE: //if quest mode is COLLECT_MODE
				if (QUEST_OBJECTIVE != MOB_COUNT) //check to see if he killed the monster
				{
					srand(time(NULL));//avoids dublicated results
					if (rand() % 100 <= 50) // 50% chance to monster drop item
					{
						QUEST_OBJECTIVE++; // increase quest objective by 1
					}


					if (QUEST_OBJECTIVE == MOB_COUNT) //alert user if he completed the quest 
					{
						SetConsoleTextAttribute(hConsole, LIGHTMAGENTA);
						cout << "You have completed the quest go hand it in." << endl << endl;
						SetConsoleTextAttribute(hConsole, WHITE);
					}


				}
				else
				{
					SetConsoleTextAttribute(hConsole, LIGHTMAGENTA);
					cout << "You have already completed the quest hand it in" << endl << endl;
					SetConsoleTextAttribute(hConsole, WHITE);
				}
				break;


		}

	}
}