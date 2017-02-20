void F_LOAD_ARMOR_SHOP()
{
	string sqliteFile = "Game.db";  // State database name
	try
	{
		sqlite::sqlite db(sqliteFile); //Set sql statement

		auto cur = db.get_statement();            // create sql query
		cur->set_sql("select * from Armors "
			"where Level = " + to_string(PLAYER_LEVEL));
		cur->prepare();                            // run sql query
												   

		while (cur->step())// loop over results
		{
			if (cur->get_int(0) != 1) //List all armors exept the one with the ID = 1
			{
				cout << "---------------" << endl << endl;
				cout << "Name : " << cur->get_text(1) << endl;
				cout << "ID: " << cur->get_int(0) << endl;
				cout << "Aditional HP: " << cur->get_int(3) << endl;
				cout << "Aditional Defence: " << cur->get_int(4) << endl;
				cout << "Price: " << cur->get_int(5) << "G" << endl;
			}

		}
	}
	catch (sqlite::exception e)      // catch all errors
	{
		std::cerr << e.what() << std::endl; // print errors
	}
}