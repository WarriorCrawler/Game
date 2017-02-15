void F_CAMPFIRE()
{
	system("cls");//clear screen 
	if (PLAYER_STAMINA == PLAYER_STAMINA_MAX) // if player's stamina is full alert him/her
	{
		SetConsoleTextAttribute(hConsole, LIGHTRED);
		cout << "You are rested" << endl << endl;
		SetConsoleTextAttribute(hConsole, WHITE);
	}
	else
	{
		//repeat untill players stamina is less than the max stamina
		//allowed
		while (PLAYER_STAMINA < PLAYER_STAMINA_MAX)
		{
			system("cls");//clear screen

						  //alert player how much time is left
			SetConsoleTextAttribute(hConsole, LIGHTCYAN);
			cout << "Time remaing to fully rest: " << PLAYER_STAMINA_MAX - PLAYER_STAMINA << endl;
			SetConsoleTextAttribute(hConsole, WHITE);

			PLAYER_STAMINA++; //increase player stamina by 1
			Sleep(1000); //delay for 1 second 
		}
		system("cls"); //clear screen
		F_SAVE(); //call save function to save stamina value to database

				  //alert user that his stamina is full 
		SetConsoleTextAttribute(hConsole, LIGHTGREEN);
		cout << "You are fully rested now" << endl << endl;
		SetConsoleTextAttribute(hConsole, WHITE);

	}
}