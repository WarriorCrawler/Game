void F_INVENTORY_MENU()
{
	// set initial state of bools
	ViewingArmors = false;
	InInventory = true;
	ViewingWeapons = false;

	//only run this menu when conditions are met
	while (InInventory && !ViewingArmors && !ViewingWeapons)
	{
		int InventoryChoice; //Declare variable
		//Display heading in light cyan
		SetConsoleTextAttribute(hConsole, LIGHTCYAN);
		cout << "== INVENTORY ==" << endl << endl;
		SetConsoleTextAttribute(hConsole, WHITE);

		//display options
		cout << "0: Exit Inventory" << endl;
		cout << "1: View Armors" << endl;
		cout << "2: View Weapons" << endl;
		cout << endl;

		//get users choice
		cout << endl << "Choice : ";
		cin >> InventoryChoice;
		cout << endl;

		switch (InventoryChoice) //do actions based on the choice
		{
		case 0: // if choice was exit inventory
			system("cls"); //clear screen
			InInventory = false; //change the boo state to false to terminate this menu
			break;
		case 1: // if choise was view Armors
			system("cls"); //clear screen
			//Declare variables
			int ArmorID;
			int ArmorViewingChoice;

			//change the bool state to true to stay within this menu
			ViewingArmors = true;

			//call the function bellow to list all the armors in the inventory
			F_LOAD_ARMOR_INV();

			while (ViewingArmors) //loop over screen while player is in this menu
			{

				//display choices
				cout << endl;
				cout << "0: Exit Viewing" << endl;
				cout << "1: Equip Armor" << endl;
				cout << "2: Enhance Equiped Armor" << endl;
				cout << "3: Sell Armor" << endl;
				cout << endl;

				//get choice from player
				cout << endl << "Choice : ";
				cin >> ArmorViewingChoice;
				cout << endl;

				switch (ArmorViewingChoice) //do the corresponding action based on players choice
				{
				case 0: // if choice was exit viewing
					system("cls"); //clear screen
					ViewingArmors = false; //set bool state to false to exit the viewing armor menu
					break;

				case 1://if case was equip armor

					//get armor ID by user
					cout << endl << "Type Armor ID : ";
					cin >> ArmorID;
					cout << endl;
					try
					{
						sqlite::sqlite db("Game.db"); //Opens the Database

						auto cur = db.get_statement(); //declaring cur as an sql Statement

													   //the Sql statement to un-equip equiped weapon
						cur->set_sql("UPDATE ArmorInventory SET Location = 'INVENTORY' WHERE Location = 'EQUIPED'");
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

						// the sql statement to equip new item by its ID
						curTemp->set_sql("UPDATE ArmorInventory SET Location = 'EQUIPED' WHERE ID = " + to_string(ArmorID));
						curTemp->exec();//Executes the statement

						F_LOAD_ARMOR(); //Load new armor stats into the game

						//check to make sure that the new armor equiped will not result in the HP
						//being greater that the hp allowed
						if (PLAYER_HP > PLAYER_HP_MAX + ARMOR_HP)
						{
							PLAYER_HP = (PLAYER_HP_MAX + ARMOR_HP);
							F_SAVE();//call save function to ammend changes to database
						}
						

						//alert user that the armor has been equiped
						SetConsoleTextAttribute(hConsole, LIGHTGREEN);
						cout << ARMOR_NAME << " has been equiped" << endl;
						SetConsoleTextAttribute(hConsole, WHITE);
					}
					catch (sqlite::exception e)      // catch all sql issues
					{
						std::cerr << e.what() << std::endl; //print Errors
					}


					break;
				case 2: // if choice was to enhance equiped armor
					if (ARMOR_NAME != "Noob Armor") //check to make sure not to ammend starter armor
					{
						F_UPGRADE_ARMOR(); //Call the upgrade funciom
					}
					else
					{

						//Notify user that he cannot enhance starter armor
						SetConsoleTextAttribute(hConsole, LIGHTRED);
						cout << "Can not Enhance Noob Armor" << endl;
						SetConsoleTextAttribute(hConsole, WHITE);
					}
					break;
				case 3: //if choice was to sell armor
					//get armor ID by user
					cout << endl << "Type Armor ID : ";
					cin >> ArmorID;
					cout << endl;
					F_SELL_ARMOR(ArmorID); //call the sell function
					break;
				}

			}



			break;
		case 2: //if choice was view weapons
			system("cls"); //clear screen

			//declare variables
			int WeaponID;
			int WeaponViewingChoice;

			//change bool state to true to stay in menu
			ViewingWeapons = true;
			F_LOAD_WEAPON_INV();//call function to list all weapons

			while (ViewingWeapons) //repeat untill user is in the menu
			{

				// display choices
				cout << endl;
				cout << "0: Exit Viewing" << endl;
				cout << "1: Equip Weapon" << endl;
				cout << "2: Enhance Equiped Wepon" << endl;
				cout << "3: Sell Weapon" << endl;
				cout << endl;

				//get choice by player
				cout << endl << "Choice : ";
				cin >> WeaponViewingChoice;
				cout << endl;

				switch (WeaponViewingChoice) //do corresponding actions based on the choice
				{
				case 0://if choice was to exit the menu
					system("cls"); //clear screen
					ViewingWeapons = false;//set bool state to false to exit the menu
					break;
				case 1://if choise was to eqquip weapon

					//get weapon ID by user
					cout << endl << "Type Weapon ID : ";
					cin >> WeaponID;
					cout << endl;

					try
					{
						sqlite::sqlite db("Game.db"); //Opens the Database

						auto cur = db.get_statement(); //declaring cur as an sql Statement

													   //the Sql statement to un-equip equiped item
						cur->set_sql("UPDATE WeaponInventory SET Location = 'INVENTORY' WHERE Location = 'EQUIPED'");
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

						// the sql statement to equip item by the ID
						curTemp->set_sql("UPDATE WeaponInventory SET Location = 'EQUIPED' WHERE ID = " + to_string(WeaponID));
						curTemp->exec();//Executes the statement

						F_LOAD_WEAPON();//load new stats of the equiped weapon in the game

						//alert user that weapon has been equiped
						SetConsoleTextAttribute(hConsole, LIGHTGREEN);
						cout << WEAPON_NAME << " has been equiped" << endl;
						SetConsoleTextAttribute(hConsole, WHITE);
					}
					catch (sqlite::exception e)      // catch all sql issues
					{
						std::cerr << e.what() << std::endl; //print Errors
					}


					break;
				case 2://if choise was to upgrade equiped weapon
					if (ARMOR_NAME != "Noob Sword")//check to make sure not to ammend starter weapon
					{
						F_UPGRADE_WEAPON();//call upgrade function to enhance weapon
					}
					else
					{
						//allert user he cannot enhance starter weapon
						SetConsoleTextAttribute(hConsole, LIGHTRED);
						cout << "Can not Enhance Noob Sword" << endl;
						SetConsoleTextAttribute(hConsole, WHITE);
					}
					break;
				case 3://if choice was to sell weapon

					//get weapon ID by user
					cout << endl << "Type Weapon ID : ";
					cin >> WeaponID;
					cout << endl;

					F_SELL_WEAPON(WeaponID);//call sell function to sell item
					break;
				}

			}



			break;
		}
	}
}