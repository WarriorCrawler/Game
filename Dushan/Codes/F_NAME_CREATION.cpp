void F_NAME_CREATION()
{
	srand(time(NULL)); //avoids dublicate values
	PLAYER_UID = rand() % 9999999 + 1; //generate random UID for new player

	//display output message that he/she must name his/her character
	cout << "Enter a character name you want" << endl << "then hit ENTER" << endl;
	cout << "Name : ";

	//get name from player
	cin >> PLAYER_NAME;
	PLAYER_HP += ARMOR_HP; //add armor hp to players hp

	try
	{
		sqlite::sqlite db("Game.db"); //Opens the Database

		auto cur = db.get_statement(); //declaring cur as an sql Statement

									   //the Sql statement to set new UID to player
		cur->set_sql("INSERT INTO ScoreBoard(UID, Name) VALUES( '"
			+ to_string(PLAYER_UID) + "', '" +
			PLAYER_NAME + "');");
		cur->exec();//Executes the statement
	}
	catch (sqlite::exception e)      // catch all sql errors
	{
		std::cerr << e.what() << std::endl; //print Errors
	}

	F_SAVE(); //call save function to update UID,NAME and HP
}