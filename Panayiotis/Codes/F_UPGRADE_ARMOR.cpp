void F_UPGRADE_ARMOR()
{
	//Initialize variables
	int EnhancementArmorDef;
	int EnhancementArmorHp;

	if (PLAYER_ENHANCEMENT_STONES > 0) // if the player has the right amount of enhancement stones then proceed
	{
		if (ARMOR_ENHANCEMENT_LEVEL < 5) // if armor enhancement level is bellow 5 to the following
		{
			ARMOR_ENHANCEMENT_LEVEL++; // Icrease armor enhancement by 1

			string sqliteFile = "Game.db";
			try
			{
				sqlite::sqlite db(sqliteFile); // Connect to the database

				auto cur = db.get_statement();            // create query
				cur->set_sql("select * from ArmorEnhancement "
					"where Name = '" + ARMOR_NAME + "' AND Enhancement = '" 
					+ to_string(ARMOR_ENHANCEMENT_LEVEL) + "' ");
				cur->prepare();                            // run query
														   

				while (cur->step())// loop over results
				{
					//Add results to appropriate variables
					EnhancementArmorHp = cur->get_int(2);
					EnhancementArmorDef = cur->get_int(3);
				}

			}
			catch (sqlite::exception e)      // catch all sql issues
			{
				std::cerr << e.what() << std::endl; // print errors
			}
			try
			{
				sqlite::sqlite db("Game.db"); //Opens the Database

				auto curTemp = db.get_statement(); //declaring cur as an sql Statement
				curTemp->set_sql("UPDATE ArmorInventory SET Hp = '" + to_string(ARMOR_HP + EnhancementArmorHp) +
					"', Defence = '" + to_string(ARMOR_DEFENCE + EnhancementArmorDef) +
					"', Enhancement = '" + to_string(ARMOR_ENHANCEMENT_LEVEL) +
					"' WHERE Location = 'EQUIPED'");
				
				curTemp->exec();//Executes the statement
				PLAYER_ENHANCEMENT_STONES--; //Decreases EnhancementStones by 1
				F_SAVE(); //Calls the save function to save changes
				F_LOAD_ARMOR(); //Populates new armor results

				// Alert user that the enhancement was successful
				SetConsoleTextAttribute(hConsole, LIGHTGREEN);
				cout << "Enhancement was successful" << endl;
				SetConsoleTextAttribute(hConsole, WHITE);
			}
			catch (sqlite::exception e)      // catch all sql issues
			{
				std::cerr << e.what() << std::endl; //print Errors
			}

		}
		else
		{
			// If armor is at max Enhancement Level alert the user
			SetConsoleTextAttribute(hConsole, LIGHTRED);
			cout << "Armor is at max Enhancement" << endl;
			SetConsoleTextAttribute(hConsole, WHITE);
		}
	}
	else
	{
		// Alert the user if he has no EnhancementStones
		SetConsoleTextAttribute(hConsole, LIGHTRED);
		cout << "You haven't got any EnhancementStones" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	
}