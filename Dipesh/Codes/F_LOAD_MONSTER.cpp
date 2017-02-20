void F_LOAD_MONSTER(int INDEX)
{
	string sqliteFile = "Game.db"; //state database name
	try
	{
		sqlite::sqlite db(sqliteFile);//connect to database

		auto cur = db.get_statement();            // create query to select monster by ID
		cur->set_sql("select * from Monsters "
			"where ID = " + to_string(INDEX));
		cur->prepare();                            // run query
												   

		while (cur->step())// loop over results
		{
			//save monster attributes to the bellow variables
			MONSTER_NAME = cur->get_text(1);
			MONSTER_HP = cur->get_int(3);
			MONSTER_ATTACK_MIN = cur->get_int(4);
			MONSTER_ATTACK_MAX = cur->get_int(5);
			MONSTER_DEFENCE = cur->get_int(6);
			MONSTER_GOLD_REWARD = cur->get_int(7);
			MONSTER_EXP_REWARD = cur->get_int(8);


		}
		InDialog = true;//set bool statement to true to stay in combat menu



	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl; // Print Errors
	}



}