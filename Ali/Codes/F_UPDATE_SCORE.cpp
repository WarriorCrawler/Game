void F_UPDATE_SCORE(int INCREASE) //Saves any changes to the Score Board in the database
{
	int GetScore;
	string sqliteFile = "Game.db"; //state database name
	try
	{
		sqlite::sqlite db(sqliteFile); //Opens the Database

		auto cur = db.get_statement();            // create query
		cur->set_sql("select * from ScoreBoard "
			"where UID = " + to_string(PLAYER_UID));
		cur->prepare();                            // run query
												   

		while (cur->step())// loop over results
		{

			GetScore = cur->get_int(3); // Add players current score to the GetScore Variable
			
		}
		// Validation check if the score goes bellow 0 to make it 0
		if (GetScore + INCREASE < 0)
		{
			GetScore = 0;
			INCREASE = 0;
		}

		

	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl; //print errors
	}
	try
	{
		sqlite::sqlite db("Game.db"); //Opens the Database

		auto cur = db.get_statement(); //declaring cur as an sql Statement

									   //the Sql statement to update everything
		cur->set_sql("UPDATE ScoreBoard SET Score = '" + to_string(GetScore + INCREASE) +
			"' WHERE UID = " + to_string(PLAYER_UID));
		cur->exec();//Executes the statement

		
		if (INCREASE > 0) // If the score has been increased to Display the changes to the User
		{
			SetConsoleTextAttribute(hConsole, LIGHTGREEN);
			cout << "Your New Score is: " << GetScore + INCREASE << endl << endl;

		}
		else // If the score has dropped to display the following changes to the user
		{
			SetConsoleTextAttribute(hConsole, LIGHTRED);
			if (GetScore == 0) // when the score is now 0 to display this
			{
				cout << "Your Score droped to: 0" << endl << endl;
			}
			else // when the score is above 0 but still droped to display this
			{
				cout << "Your Score droped to: " << GetScore + INCREASE << endl << endl;
			}
			
		}
		SetConsoleTextAttribute(hConsole, WHITE);
		
	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl; //print Errors
	}
}