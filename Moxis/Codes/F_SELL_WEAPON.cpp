void F_SELL_WEAPON(int ID)
{
	//Declare variables
	string WeaponName;
	string Status;
	int SoldPrice;

	string sqliteFile = "Game.db";//Set Database name
	try
	{
		sqlite::sqlite db(sqliteFile);//connect to database

		auto cur = db.get_statement();            // create query
		cur->set_sql("select * from WeaponInventory "
			"where ID = " + to_string(ID));
		cur->prepare();                            // run query
												   //cur->bind(1, selector);

		while (cur->step())// loop over results
		{
			//Save results to variables
			WeaponName = cur->get_text(1);
			SoldPrice = cur->get_int(5);
			Status = cur->get_text(6);


		}
	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl; //Display errors
	}

	if (Status != "EQUIPED") // Check to make sure user does not sell equiped weapon
	{
		try
		{
			sqlite::sqlite db("Game.db"); //Opens the Database

			auto cur = db.get_statement(); //declaring cur as an sql Statement

										   //the Sql statement to update everything
			cur->set_sql("delete from WeaponInventory "
				"where ID = " + to_string(ID));
			cur->exec();//Executes the statement
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			std::cerr << e.what() << std::endl; //print Errors
		}

		PLAYER_GOLD += SoldPrice; //Give gold to player from selling the weapon

		//Alert player that he has sold the weapon
		SetConsoleTextAttribute(hConsole, LIGHTGREEN);
		cout << "Sold " << WeaponName << endl;
		SetConsoleTextAttribute(hConsole, WHITE);

		F_SAVE();// Call save Function to save changes
	}
	else
	{
		// Alert user he cannot sell an equiped weapon
		SetConsoleTextAttribute(hConsole, LIGHTRED);
		cout << "You can not sell equiped item " << endl;
		SetConsoleTextAttribute(hConsole, LIGHTGREEN);
	}




}