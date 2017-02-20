void F_SELL_ARMOR(int ID)
{

	//Declare Variables
	string ArmorName;
	string Status;
	int SoldPrice;

	string sqliteFile = "Game.db"; //Set database name
	try
	{
		sqlite::sqlite db(sqliteFile); //Declare Sql Statement

		auto cur = db.get_statement();            // create query
		cur->set_sql("select * from ArmorInventory "
			"where ID = " + to_string(ID));
		cur->prepare();                            // run query
												   //cur->bind(1, selector);

		while (cur->step())// loop over results
		{
			//save results to variables
			ArmorName = cur->get_text(1);
			SoldPrice = cur->get_int(5);
			Status = cur->get_text(6);


		}
	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl; //display errrors
	}
	
	if (Status != "EQUIPED") //Check to make sure user does not sell equiped armor
	{
		try
		{
			sqlite::sqlite db("Game.db"); //Opens the Database

			auto cur = db.get_statement(); //declaring cur as an sql Statement

										   //the Sql statement to update everything
			cur->set_sql("delete from ArmorInventory "
				"where ID = " + to_string(ID));
			cur->exec();//Executes the statement
		}
		catch (sqlite::exception e)      // catch all sql issues
		{
			std::cerr << e.what() << std::endl; //print Errors
		}

		PLAYER_GOLD += SoldPrice; //Add the gold to the player after selling armor

		//Display message to tell user he has sold the armor
		SetConsoleTextAttribute(hConsole, LIGHTGREEN);
		cout << "Sold " << ArmorName << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
		F_SAVE(); //Call Save Function to save changes to the Database
	}
	else
	{
		//Alert User that he cannot sell an equiped armor
		SetConsoleTextAttribute(hConsole, LIGHTRED);
		cout << "You can not sell equiped item " << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
	}

		
	

}