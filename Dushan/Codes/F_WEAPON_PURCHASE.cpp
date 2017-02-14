void F_WEAPON_PURCHASE(int ID)
{

	//Declare Variables
	string WeaponName;
	int WeaponLevel;
	int WeaponAttackMin;
	int WeaponAttackMax;
	int WeaponPrice;

	string sqliteFile = "Game.db"; //Set Database name
	try
	{
		sqlite::sqlite db(sqliteFile); //Set sql statement

		auto cur = db.get_statement();            // create query
		cur->set_sql("select * from Weapons "
			"where ID = " + to_string(ID));
		cur->prepare();                            // run query

		while (cur->step())// loop over results
		{

			//Save results to the variables
			WeaponName = cur->get_text(1);
			WeaponLevel = cur->get_int(2);
			WeaponAttackMin = cur->get_int(3);
			WeaponAttackMax = cur->get_int(4);
			WeaponPrice = cur->get_int(5);


		}
	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl;//Display Errors
	}
	if (PLAYER_GOLD >= WeaponPrice) //Check to make asure that player has enough gold to buy item
	{
		PLAYER_GOLD -= WeaponPrice; //Decrease players gold with the ammount the armor costs

		try
		{
			sqlite::sqlite db("Game.db"); //Opens the Database

			auto cur = db.get_statement(); //declaring cur as an sql Statement

										   //An Insert statement to insert the item to the inventory
			cur->set_sql("INSERT INTO WeaponInventory(Name, Level, AttackMin, AttackMax, Price) VALUES( '"
				+ WeaponName + "', '" +
				to_string(WeaponLevel) + "', '" +
				to_string(WeaponAttackMin) + "', '" +
				to_string(WeaponAttackMin) + "', '" +
				to_string(WeaponPrice / 2) + "');");
			cur->exec();//Executes the statement
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			std::cerr << e.what() << std::endl; //Display Errors
		}

		//Alert user that he bought the weapon
		SetConsoleTextAttribute(hConsole, LIGHTGREEN);
		cout << "Bought " << WeaponName << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	else
	{
		//Alert user he does not have the required gold to buy the item
		SetConsoleTextAttribute(hConsole, LIGHTRED);
		cout << "Not Enought Gold" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	F_SAVE(); //Call the save function to save changes to database
}