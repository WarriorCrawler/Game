void F_LOAD_WEAPON_SHOP()
{
	string sqliteFile = "Game.db"; //State database name
	try
	{
		sqlite::sqlite db(sqliteFile); // set sql statement

		auto cur = db.get_statement();            // create sql query
		cur->set_sql("select * from Weapons "
			"where Level = " + to_string(PLAYER_LEVEL));
		cur->prepare();                            // run sql query


		while (cur->step())// loop over results
		{
			if (cur->get_int(0) != 1) //List all weapons exept the one with the ID = 1
			{
				cout << "---------------" << endl << endl;
				cout << "Name : " << cur->get_text(1) << endl;
				cout << "ID: " << cur->get_int(0) << endl;
				cout << "Aditional AttackMin: " << cur->get_int(3) << endl;
				cout << "Aditional AttackMax: " << cur->get_int(4) << endl;
				cout << "Price: " << cur->get_int(5) << "G" << endl;
			}

		}
	}
	catch (sqlite::exception e)      // catch all sql errors
	{
		std::cerr << e.what() << std::endl; //print sql errors
	}
}