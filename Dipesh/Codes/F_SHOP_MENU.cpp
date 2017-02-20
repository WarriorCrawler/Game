void F_SHOP_MENU()
{
	int Shopchoice;//declare variable
	system("cls"); //clear screen


	//set bools initial state
	InShop = true;
	ArmorShop = false;
	WeaponShop = false;
	while (InShop && !ArmorShop && !WeaponShop) //repeat while in shop menu
	{

		//display heading in light cyan colour
		SetConsoleTextAttribute(hConsole, LIGHTCYAN);
		cout << "== SHOP ==" << endl << endl;
		SetConsoleTextAttribute(hConsole, WHITE);

		//list options
		cout << "0: Exit Shop" << endl;
		cout << "1: Hp Potion [50 G]" << endl;
		cout << "2: Increase Luck [1000 G]" << endl;
		cout << "3: Buy Armors" << endl;
		cout << "4: Buy Weapons" << endl;
		cout << endl;

		//get players choice
		cout << endl << "Choice : ";
		cin >> Shopchoice;
		cout << endl;

		switch (Shopchoice)//carry action on players choise
		{
		case 0://if player chose to exit the shop
			system("cls"); //clear screen 
			InShop = false; //set bool state to false to exit menu
			break;
		case 1://if player chose to buy potion
			system("cls");//clear screen
			if (PLAYER_GOLD >= 50) //check to make sure player has enough gold
			{
				PLAYER_GOLD -= 50; //reduse players gold by 50
				PLAYER_HP_POTIONS++; //increase potion ammount by 1
				F_SAVE(); //call save function to save potion ammoun to database

						  //alert player that he/she bought potion
				SetConsoleTextAttribute(hConsole, LIGHTGREEN);
				cout << "You Bought 1 Hp Potion" << endl << endl;
				SetConsoleTextAttribute(hConsole, WHITE);

			}
			else
			{
				//alet player that the gold is not enough
				SetConsoleTextAttribute(hConsole, LIGHTRED);
				cout << "You havent got enough Gold" << endl << endl;
				SetConsoleTextAttribute(hConsole, WHITE);
			}

			break;
		case 2: // if player chose to increase luck 
			system("cls"); //clear screen
			if (PLAYER_LUCK < 80) //check to see if players luck is bellow 80
			{
				if (PLAYER_GOLD >= 1000) //check to see if player has enough gold
				{
					PLAYER_GOLD -= 1000; //decrease players gold by 1000
					PLAYER_LUCK += 5; //increase players luck by 5
					F_SAVE(); //call save function to save gold,luck to database

							  //alert player that he/she increased the luck of the character
					SetConsoleTextAttribute(hConsole, LIGHTGREEN);
					cout << "You Increased ur Luck" << endl << endl;
					SetConsoleTextAttribute(hConsole, WHITE);

				}
				else
				{
					//alert player that he/she hasnt got enough gold
					SetConsoleTextAttribute(hConsole, LIGHTRED);
					cout << "You havent got enough Gold" << endl << endl;
					SetConsoleTextAttribute(hConsole, WHITE);
				}
			}
			else
			{
				//alert player that the luck is maxed out
				SetConsoleTextAttribute(hConsole, LIGHTRED);
				cout << "Your Luck is maxed out" << endl << endl;
				SetConsoleTextAttribute(hConsole, WHITE);
			}

			break;
		case 3://if player chose to buy armors
			system("cls"); //clear screen 
			ArmorShop = true; //set bool state to true to stay in menu

							  //declare variables
			int ArmorShopChoice;
			int ArmorIDBuy;

			F_LOAD_ARMOR_SHOP();//call function to list all armors equal to players level

			while (ArmorShop)//repeat while player is in menu
			{
				//display choices
				cout << endl;
				cout << "0: Exit Armor Shop" << endl;
				cout << "1: Buy Armor" << endl;
				cout << endl;

				//get players choice
				cout << endl << "Choice: ";
				cin >> ArmorShopChoice;
				cout << endl;

				switch (ArmorShopChoice) //carry action based on players choice
				{
				case 0:
					system("cls");//clear screen
					ArmorShop = false; //exit armor shop
					break;
				case 1://if player chose to buy armor

					   //get armor ID by player
					cout << endl << "Type Armor ID : ";
					cin >> ArmorIDBuy;
					cout << endl;

					//call armor purchase function to purcase the armor with the ID supplied by player
					F_ARMOR_PURCHASE(ArmorIDBuy);
					break;
				}

			}
			break;
		case 4://if player chose to buy a weapons
			system("cls"); //clear screen
			WeaponShop = true;//set bool state to true to stay in menu

							  //declare variables
			int WeaponShopChoice;
			int WeaponIDBuy;

			F_LOAD_WEAPON_SHOP();//call function to list all weapons equal to players level

			while (WeaponShop) //repeat while player is in menu
			{
				//display choices
				cout << endl;
				cout << "0: Exit Weapon Shop" << endl;
				cout << "1: Buy Weapon" << endl;
				cout << endl;

				//get choice by player
				cout << endl << "Choice: ";
				cin >> WeaponShopChoice;
				cout << endl;

				switch (WeaponShopChoice)//carry action based on players choice
				{
				case 0://if player chose to exit the weapon menu
					system("cls"); //clear screen
					WeaponShop = false; //exit weapon shop
					break;
				case 1://if player chose to buy weapon

					   //get weapon ID by user
					cout << endl << "Type Weapon ID : ";
					cin >> WeaponIDBuy;
					cout << endl;

					//call weapon purchase function to purcase the weapon with the ID supplied by player
					F_WEAPON_PURCHASE(WeaponIDBuy);
					break;
				}

			}
			break;


		}

	}
}