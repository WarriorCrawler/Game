void F_LOAD_WEAPON_INV()
{
	string sqliteFile = "Game.db"; //Set Database name
	try
	{
		sqlite::sqlite db(sqliteFile); //Set sql statement

		auto cur = db.get_statement();            // create query
		cur->set_sql("select * from WeaponInventory");
		cur->prepare();                            // run query

		while (cur->step())// loop over results
		{
			//Display all weapons and their attributes
			cout << "---------------" << endl << endl;
			cout << "Name : " << cur->get_text(1) << endl;
			cout << "ID: " << cur->get_int(0) << endl;
			cout << "Level: " << cur->get_int(2) << endl;
			cout << "Aditional AttackMin: " << cur->get_int(3) << endl;
			cout << "Aditional AttackMax: " << cur->get_int(4) << endl;
			cout << "Sale Price: " << cur->get_int(5) << "G" << endl;
			cout << "Enhancement: +" << cur->get_text(7) << endl;
			cout << "Location: " << cur->get_text(6) << endl;
		}

	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl; //Display error
	}
}