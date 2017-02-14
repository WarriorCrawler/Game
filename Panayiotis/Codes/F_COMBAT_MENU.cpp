void F_COMBAT_MENU()
{
	
	while (InCombat) //run while this menu is active
	{

		int CombatChoice; // declare variable

		//display heading in light cyan
		SetConsoleTextAttribute(hConsole, LIGHTCYAN);
		cout << "== COMBAT ==" << endl << endl<<endl;
		SetConsoleTextAttribute(hConsole, WHITE);

		//display monster, players hp
		cout << "The " << MONSTER_NAME << " Has HP: " << MONSTER_HP << " left" << endl << endl;
		cout <<"Your Hp is : " << PLAYER_HP << "/" << PLAYER_HP_MAX + ARMOR_HP << endl << endl;
		
		//display options
		cout << "0: Normal Attack" << endl;

		//display how many times he can use heavy attack by adding the stamina to the choice
		cout << "1: Heavy Attack [" + to_string(PLAYER_STAMINA) + " Times Left]" << endl;

		//display how many potions the player has left by adding the hp potions ammount to the choice
		cout << "2: Use Hp Potion [" + to_string(PLAYER_HP_POTIONS) + " Left]" << endl;
		cout << endl;

		//get players choice
		cout << endl << "Choice : ";
		cin >> CombatChoice;
		cout << endl;

		switch (CombatChoice)//do the corresponding action based on players choice
		{
		case 0:// if choise was normal attack

			//calculate total attack min by adding all the variables
			ATTACK_MINIMUM = PLAYER_ATTACK_MIN + WEAPON_ATTACK_MIN + EFFECT_DAMAGE_INCREASE;

			//calculate total attack max by adding all the variables
			ATTACK_MAXIMUM = PLAYER_ATTACK_MAX + WEAPON_ATTACK_MAX + EFFECT_DAMAGE_INCREASE +1;

			system("cls");//clear screan
			srand(time(NULL)); //avoid duplicated results

			//generate random damage between attack min , max and subtract monster's defence
			DEAL_DAMAGE = ((rand() % (ATTACK_MAXIMUM - ATTACK_MINIMUM)) + ATTACK_MINIMUM) - MONSTER_DEFENCE;
			
			F_DAMAGE_CONTROL(); // call function to deal the damage calculated
			
			break;
		case 1: //if choice was heavy attack 
			system("cls"); //clear sceen
			if (PLAYER_STAMINA > 0) //check player has enough stamina
			{

				//calculate total attack max by adding all the variables
				ATTACK_MAXIMUM = PLAYER_ATTACK_MAX + WEAPON_ATTACK_MAX + EFFECT_DAMAGE_INCREASE + 1;

				//add 40% to attack maximum
				DEAL_DAMAGE = (((ATTACK_MAXIMUM) +
					((ATTACK_MAXIMUM) * 40 / 100)) - MONSTER_DEFENCE);
				PLAYER_STAMINA--; //reduce stamina by 1 

				F_DAMAGE_CONTROL();  // call function to deal the damage calculated

			}
			break;
		case 2:// if choice was to use potion
			system("cls"); //clear screen
			if (CURRENT_EFFECT != NO_POTIONS) //check to make sure player can use potions
			{
				F_USE_POTION(); //call potion function
			}
			else//if player is cursed then alert him/her that he/she cannot use potions
			{
				SetConsoleTextAttribute(hConsole, LIGHTRED);
				cout << "You are cursed and cannot use potions" << endl << endl;
				SetConsoleTextAttribute(hConsole, WHITE);
			}
			
			break;


		}
	}
}