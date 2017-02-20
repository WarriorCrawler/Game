void F_LEVEL_CHECK()//Called to see if character must level up
{
	
	if (PLAYER_LEVEL < 20)//If character is at max level dont increase level
	{ 
		if (PLAYER_EXP >= PLAYER_EXP_MAX)//if character has reached the exp required to level up then do the following
		{
			PLAYER_LEVEL++;//increase characters level to the next one
			if (PLAYER_EXP > PLAYER_EXP_MAX) //to curry any above exp to next level
			{
				PLAYER_EXP = PLAYER_EXP - PLAYER_EXP_MAX;
			}
			else//if no above exp then set exp to 0
			{
				PLAYER_EXP = 0;
			}
			try
			{
				//Get level stats from Levels table
				sqlite::sqlite db("Game.db"); //open the database
				auto cur = db.get_statement();  // create query
				cur->set_sql("select * from Levels "
					"where Level = " + to_string(PLAYER_LEVEL));
				cur->prepare(); // run query
														   

				while (cur->step())// loop over results
				{

					//Get results
					int ExpToNext = cur->get_int(1);
					int AttackMinUp = cur->get_int(2);
					int AttackMaxUp = cur->get_int(3);
					int DefenceUp = cur->get_int(4);
					int StaminaUp = cur->get_int(5);
					int HpUp = cur->get_int(6);

					//make changes based on new level
					PLAYER_EXP_MAX = ExpToNext;
					PLAYER_ATTACK_MAX += AttackMaxUp;
					PLAYER_ATTACK_MIN += AttackMinUp;
					PLAYER_DEFENCE += DefenceUp;
					PLAYER_STAMINA_MAX += StaminaUp;
					PLAYER_HP_MAX += HpUp;
					PLAYER_HP = PLAYER_HP_MAX;

				}

			}
			catch (sqlite::exception e) // catch all sql issues
			{
				std::cerr << e.what() << std::endl;
			}

			F_SAVE();//call save function to save changes to database
			
			SetConsoleTextAttribute(hConsole, LIGHTGREEN);
			cout << "You are now Level " << PLAYER_LEVEL << endl << endl;//output message to allert level increase
			SetConsoleTextAttribute(hConsole, WHITE);
			MONSTER_LIST.clear();
			if (PLAYER_LEVEL == 20) //if character has reached level cap to be notified
			{
				SetConsoleTextAttribute(hConsole, LIGHTGREEN);
				cout << "You are now Max Level " << endl << endl;
				SetConsoleTextAttribute(hConsole, WHITE);
			}

		}
	}
	
} //Done