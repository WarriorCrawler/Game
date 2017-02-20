void F_LOAD_SCORES()
{
	string sqliteFile = "Game.db";//Set database name
	try
	{
		sqlite::sqlite db(sqliteFile);//connect to database

		auto cur = db.get_statement();            // create query
		cur->set_sql("select * from ScoreBoard");
		cur->prepare();                            // run query
												   //cur->bind(1, selector);

		while (cur->step())// loop over results
		{
			//Display all results
			cout << "ID: " << cur->get_text(0);
			cout << "  Name: " << cur->get_text(2);
			cout << "  Score: " << cur->get_int(3) << endl;
		}
		cout << endl << "------------------------------------------------------------------------" << endl;
	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl; //Display errors
	}
}