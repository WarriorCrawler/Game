int main()
{
	int Choice;//declare variable
	SetConsoleTextAttribute(hConsole, WHITE);

	

	string sqliteFile = "Game.db"; //set database name

	try
	{
		sqlite::sqlite db(sqliteFile); //connect to the database
		
		auto cur = db.get_statement(); // create query to load character table in the game
		cur->set_sql("select * from Character "
					"where ID = " + to_string(1));
		cur->prepare(); // run query

		while (cur->step())// loop over results
		{
			//save all field data to the coresponding variables
			PLAYER_NAME = cur->get_text(1);
			PLAYER_LEVEL = cur->get_int(2);
			PLAYER_EXP = cur->get_int(3);
			PLAYER_EXP_MAX = cur->get_int(4);
			PLAYER_HP = cur->get_int(5);
			PLAYER_HP_MAX = cur->get_int(6);
			PLAYER_DEFENCE = cur->get_int(7);
			PLAYER_ATTACK_MIN = cur->get_int(8);
			PLAYER_ATTACK_MAX = cur->get_int(9);
			PLAYER_STAMINA = cur->get_int(10);
			PLAYER_STAMINA_MAX = cur->get_int(11);
			PLAYER_GOLD = cur->get_int(12);
			PLAYER_HP_POTIONS = cur->get_int(13);
			PLAYER_LUCK = cur->get_int(14);
			PLAYER_UID = cur->get_int(15);
			PLAYER_ENHANCEMENT_STONES = cur->get_int(16);

		}
		//call bellow two functions to load items equiped
		F_LOAD_ARMOR();
		F_LOAD_WEAPON();

		//declare bools initial state
		StartMenu = true;
		Playing = false;
		InCombat = false;
		InShop = false;
		InDialog = false;
		Reseting = false;
		InInventory = false;
		InInstructionsMenu = false;

		while (StartMenu && !InInstructionsMenu) //repeat menu while player is in it
		{

			//Display ASCI art of game name
			SetConsoleTextAttribute(hConsole, LIGHTCYAN);
		
			cout << R"(
 _    _                 _              _____                    _           
| |  | |               (_)            /  __ \                  | |          
| |  | | __ _ _ __ _ __ _  ___  _ __  | /  \/_ __ __ ___      _| | ___ _ __ 
| |/\| |/ _` | '__| '__| |/ _ \| '__| | |   | '__/ _` \ \ /\ / | |/ _ | '__|
\  /\  | (_| | |  | |  | | (_) | |    | \__/| | | (_| |\ V  V /| |  __| |   
 \/  \/ \__,_|_|  |_|  |_|\___/|_|     \____|_|  \__,_| \_/\_/ |_|\___|_|   
                                                                              
 )"<< endl;


			SetConsoleTextAttribute(hConsole, WHITE);

			//dicplay choices
			cout << "0: Play" << endl;
			cout << "1: ScoreBoard" << endl;
			cout << "2: Instructions" << endl;
			cout << "3: Exit" << endl;
			cout << endl;

			//get choice by player
			cout << "Choice: ";
			cin >> Choice;
			cout << endl;
			system("cls");//clear screen

			switch (Choice)//carry action by chosen choice
			{
			case 0 ://if player chose to play
				StartMenu = false;//set bool state to false to exit this menu
				system("cls");//clear screen
				Playing = true;//set bool state to true to initiate game menus
				break;
			case 1 ://if player chose to view scores
				system("cls");//clear screen

				//display menu heading in light cyan colour
				SetConsoleTextAttribute(hConsole, LIGHTCYAN);
				cout << "========= SCORE BOARD =========" << endl << endl;
				SetConsoleTextAttribute(hConsole, WHITE);
				F_LOAD_SCORES(); //call function to list scores
				break;
			case 2://if player chose to view instructions
				system("cls");//clear screen 
				F_INSTRUCTION_MENU();//open instruction menu
				break;
			case 3 ://if player chose to exit
				StartMenu = false;//set bool to false to terminate game
				break;
			}
		}

		//repeat while game is initianed
		while (Playing && !InCombat && !InShop && !InDialog && !Reseting && !InInventory && !InLoot )
		{
			//if character name is empty call the name creation function
			if (PLAYER_NAME == "NONE")
			{
				F_NAME_CREATION();
			}
			else //if it is not call the town menu function

			{

				F_TOWN_MENU();
			}
			

		}
	}
	catch (sqlite::exception e)      // catch all sql errors
	{
		std::cerr << e.what() << std::endl; //print errors
	}

}