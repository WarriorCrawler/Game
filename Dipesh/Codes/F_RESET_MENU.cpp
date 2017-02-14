void F_RESET_MENU()
{
	int Resetchoice; //Declare variable as integer
	Reseting = true; // Set the boolean to true
	while (Reseting) //Keep displaying the menu while Resting Boolean is true
	{
		// Display the menu and the choises available
		SetConsoleTextAttribute(hConsole, LIGHTCYAN);
		cout << "== RESET MENU ==" << endl << endl;
		SetConsoleTextAttribute(hConsole, WHITE);

		cout << "Are you sure you want to Reset Your Character?" << endl;

		cout << "0: No" << endl;
		cout << "1: Yes" << endl;
		cout << endl;

		cout << endl << "Choice : ";
		cin >> Resetchoice;
		cout << endl;

		switch (Resetchoice) //Switch Statement to do the corresponding according on the choise choosen
		{
		case 0:  // If the choise is No
			system("cls"); // Clear previous text in the CLI
			Reseting = false; //Set the bool to false to exit the menu
			break;
		case 1: // If the choice is Yes
			system("cls"); //Clear previous text in the CLI

			//Reset everything to the level 1 corresponding attributes
			PLAYER_NAME = "NONE";
			PLAYER_LEVEL = 1;
			PLAYER_HP = 30;
			PLAYER_HP_MAX = 30;
			PLAYER_EXP = 0;
			PLAYER_EXP_MAX = 30;
			PLAYER_DEFENCE = 2;
			PLAYER_ATTACK_MIN = 2;
			PLAYER_ATTACK_MAX = 4;
			PLAYER_STAMINA = 10;
			PLAYER_STAMINA_MAX = 10;
			PLAYER_GOLD = 100;
			PLAYER_HP_POTIONS = 2;
			PLAYER_ENHANCEMENT_STONES = 0;
			PLAYER_LUCK = 0;
			ARMOR_NAME = "Noob Armor";
			WEAPON_NAME = "Noob Sword";
			F_SAVE(); //Call the Save function to save changes to Database
			try
			{
				sqlite::sqlite db("Game.db"); //Opens the Database

				auto cur = db.get_statement(); //declaring cur as an sql Statement

											   //the Sql statement to update everything
				cur->set_sql("delete from ArmorInventory "
					"where ID != 1");
				cur->exec();//Executes the statement
			}
			catch (sqlite::exception e)      // catch all sql issues
			{
				std::cerr << e.what() << std::endl; //print Errors
			}

			try
			{
				sqlite::sqlite db("Game.db"); //Opens the Database

				auto cur = db.get_statement(); //declaring cur as an sql Statement

											   //the Sql statement to update everything
				cur->set_sql("delete from WeaponInventory "
					"where ID != 1");
				cur->exec();//Executes the statement
			}

			catch (sqlite::exception e)      // catch all sql issues
			{
				std::cerr << e.what() << std::endl; //print Errors
			}

			try
			{
				sqlite::sqlite db("Game.db"); //Opens the Database

				auto curTemp = db.get_statement(); //declaring cur as an sql Statement

				curTemp->set_sql("UPDATE ArmorInventory SET Location = 'EQUIPED' WHERE ID = 1");
				curTemp->exec();//Executes the statement

				F_LOAD_ARMOR(); //Call the PopulateArmor function to load armors attributes

				//A check to make sure that the HP the player has is not greater than the MAX allowed
				if (PLAYER_HP > PLAYER_HP_MAX + ARMOR_HP)
				{
					PLAYER_HP = (PLAYER_HP_MAX + ARMOR_HP);
				}

				F_SAVE(); //Call the Save function to save changes to Database


			}
			catch (sqlite::exception e)      // catch all sql issues
			{
				std::cerr << e.what() << std::endl; //print Errors
			}

			try
			{
				sqlite::sqlite db("Game.db"); //Opens the Database

				auto curTemp = db.get_statement(); //declaring cur as an sql Statement

				curTemp->set_sql("UPDATE WeaponInventory SET Location = 'EQUIPED' WHERE ID = 1");
				curTemp->exec();//Executes the statement

				F_LOAD_WEAPON();
			}
			catch (sqlite::exception e)      // catch all sql issues
			{
				std::cerr << e.what() << std::endl; //print Errors
			}

			Reseting = false; //Set the bool to false to exit the menu

			//Allert user that he has reset his character

			SetConsoleTextAttribute(hConsole, LIGHTGREEN);
			cout << "You have Reset you character you start all over again now" << endl << endl;
			SetConsoleTextAttribute(hConsole, WHITE);

			break;

		}

	}
}