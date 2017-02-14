void F_TOWN_MENU()
{
	//declare variable
	int choice;
	

	//display menu heading in light cyan colour
	SetConsoleTextAttribute(hConsole, LIGHTCYAN);
	cout << "== MAIN MENU ==" << endl << endl;
	SetConsoleTextAttribute(hConsole, WHITE);

	//display choices
	cout << "0: Exit" << endl;
	cout << "1: Quest" << endl;
	cout << "2: Shop" << endl;
	cout << "3: Hunt" << endl;
	cout << "4: Sit by campfire" << endl;
	cout << "5: Character Stats" << endl;
	cout << "6: Use Potion" << endl;
	cout << "7: Reset [Starts you over from level 1]" << endl;
	cout << "8: Inventory" << endl;
	cout << endl;

	//get players choice
	cout << endl << "Choice : ";
	cin >> choice;
	cout << endl;

	switch (choice)//carry action based on players choice
	{
	case 0://if player chose exit
		system("cls");//clear screen
		Playing = false;//change bool state to false to exit game
		break;
	case 1://if player chose to quest
		break;
	case 3:// if player chose to hunt
		system("cls");//clear screen
		F_HUNT_MENU();//call hunting menu
		break;
	case 4:
		F_CAMPFIRE();//run campfire function
		break;
	case 5:// if player chose to view stats
		system("cls"); //clear screen
		F_LOAD_STATS(); //display stats by calling function
		break;
	case 6://if player chose to use potion
		system("cls"); //clear screen
		if (CURRENT_EFFECT != NO_POTIONS) //check to make sure player can use potion
		{
			F_USE_POTION();//call potion function
		}
		else//alert player he/she cant use potion
		{
			SetConsoleTextAttribute(hConsole, LIGHTRED);
			cout << "You are cursed and can not use potions" << endl << endl;
			SetConsoleTextAttribute(hConsole, WHITE);
		}
		break;
	case 7:// if player chose to reset 
		system("cls");//clear screen
		F_RESET_MENU(); //open reset menu
		break;
	case 8: //if player chose inventory
		system("cls");//clear screen
		F_INVENTORY_MENU(); //open inventory menu
		break;
	case 2:// if player chose shop
		F_SHOP_MENU();//open the shop menu
		break;

	}
}