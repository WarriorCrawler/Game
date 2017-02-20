void F_LOAD_ARMOR()
{
	string sqliteFile = "Game.db"; 
	try
	{
		sqlite::sqlite db(sqliteFile); //Connect to the Database

		auto cur = db.get_statement();            // create query
		cur->set_sql("select * from ArmorInventory "
			"where Location = 'EQUIPED' ");
		cur->prepare();                            // run query
												   

		while (cur->step())// loop over results
		{
			//Add results to appropriate Variable
			ARMOR_NAME = cur->get_text(1);
			ARMOR_DEFENCE = cur->get_int(4);
			ARMOR_HP = cur->get_int(3);
			ARMOR_ENHANCEMENT_LEVEL = cur->get_int(7);



		}

	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl; // print errors
	}
}