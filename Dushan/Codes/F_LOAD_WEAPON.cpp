void F_LOAD_WEAPON()
{
	string sqliteFile = "Game.db";
	try
	{
		sqlite::sqlite db(sqliteFile); // Connect to the database

		auto cur = db.get_statement();            // create query
		cur->set_sql("select * from WeaponInventory "
			"where Location = 'EQUIPED' ");
		cur->prepare();                            // run query
												   

		while (cur->step())// loop over results
		{
			//Add results to the approprioate  Variables
			WEAPON_NAME = cur->get_text(1);
			WEAPON_ATTACK_MIN = cur->get_int(4);
			WEAPON_ATTACK_MAX = cur->get_int(3);
			WEAPON_ENHANCEMENT_LEVEL = cur->get_int(7);



		}

	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl; // print errors
	}
}