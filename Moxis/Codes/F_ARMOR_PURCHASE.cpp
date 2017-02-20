void F_ARMOR_PURCHASE(int ID)
{
	//Declare Variables
	string ArmorName;
	int ArmorLevel;
	int ArmorHp;
	int ArmorDefence;
	int ArmorPrice;

	string sqliteFile = "Game.db";//Set database name
	try
	{
		sqlite::sqlite db(sqliteFile);//connect to database

		auto cur = db.get_statement();            // create query
		cur->set_sql("select * from Armors "
			"where ID = " + to_string(ID));
		cur->prepare();                            // run query
												   //cur->bind(1, selector);

		while (cur->step())// loop over results
		{
			//Save results to variables
			ArmorName = cur->get_text(1);
			ArmorLevel = cur->get_int(2);
			ArmorHp = cur->get_int(3);
			ArmorDefence = cur->get_int(4);
			ArmorPrice = cur->get_int(5);
			

		}
	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl; //Display error
	}
	if (PLAYER_GOLD >= ArmorPrice) //Check to make sure the player has the required gold
	{
		PLAYER_GOLD -= ArmorPrice; //Decrease the players gold with the ammount that the armor costs

		try
		{
			sqlite::sqlite db("Game.db"); //Set Database Name

			auto cur = db.get_statement(); //declaring cur as an sql Statement

										   //An Insert statement to insert the item bought to the inventory
			cur->set_sql("INSERT INTO ArmorInventory(Name, Level, Hp, Defence, Price) VALUES( '" 
				+ ArmorName + "', '" + 
				to_string(ArmorLevel) +"', '" +
				to_string(ArmorHp) +"', '" + 
				to_string(ArmorDefence) +"', '" +
				to_string(ArmorPrice/2) + "');");
			cur->exec();//Executes the statement
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			std::cerr << e.what() << std::endl; //Display Errors
		}

		//Alert user that he has bought the armor
		SetConsoleTextAttribute(hConsole, LIGHTGREEN);
		cout << "bought " << ArmorName << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	else
	{
		//Alert user that he does not have the required gold to buy the item
		SetConsoleTextAttribute(hConsole, LIGHTRED);
		cout << "Not Enought Gold" << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	F_SAVE(); //Call the Save Function to save changes to the Database
}