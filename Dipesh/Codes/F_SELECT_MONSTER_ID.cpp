void F_SELECT_MONSTER_ID(int LVL)
{
	int LIST_SIZE;//declare variable
	string sqliteFile = "Game.db"; //state database name
	try
	{
		sqlite::sqlite db(sqliteFile); // Connect to the database

		auto cur = db.get_statement(); // create query to select all monster equal to players level
		cur->set_sql("select * from Monsters "
			"where Level = " + to_string(LVL));
		cur->prepare();                            // run query
												   

		while (cur->step())// loop over results
		{
			if (cur->get_int(2) == LVL) //check to make sure monsters IDs added to vector are equal to players level
			{
				MONSTER_LIST.push_back(cur->get_int(0));// Adds a new element to the end of the vector
				
			}
			
			


		}
	}
	catch (sqlite::exception e)      // catch all sql errors
	{
		std::cerr << e.what() << std::endl; //print sql errors
	}
	srand(time(NULL)); // avoid dublicate results
	LIST_SIZE = MONSTER_LIST.size(); //get the number of elements in the vector
	random_shuffle(MONSTER_LIST.begin(), MONSTER_LIST.end());//randomize vector using the algorythm library
	int RandIndex = MONSTER_LIST[rand() % (LIST_SIZE + 1)]; //select random position of elemnt within vector

	
	F_LOAD_MONSTER(RandIndex);// call funtion and pass selected id to spawn monster into game



}