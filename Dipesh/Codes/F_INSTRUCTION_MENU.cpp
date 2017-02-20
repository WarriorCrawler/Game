void F_INSTRUCTION_MENU()
{
	int PageOption;//declaring variable
	InInstructionsMenu = true; //set bool state to true to stay in menu
	while (InInstructionsMenu)//repeat untill user is in menu
	{
		switch (InstructionPage) //get current page
		{
		case 0://load first page
			system("cls");//clear screen
			cout << R"( 
 To choose an option just type the Number before the option and then hit the Enter key
 
 This game is totally option driven which means each time you will have to choose what to do

 Type the number 0 to go to the NEXT Page                                                                           
		)" << endl << endl;
			break;

		case 1://load second page
			system("cls");//clear screen
			cout << R"( 
 REST: When you select this you replenish your stamina to be able to use heavy attacks.
 STORY: Complete all the story modes cause they give you special items and exp!.
 SHOP: You can buy potions and variable other things here.
 INVENTORY: You can equip items sell them and enchant them here.
 ENHANCEMENT: You can enhance your items for better attributes.
 CHARACTER SHEET: You can view related stats to your character here.

                                                                 
		)" << endl << endl;
			break;

		case 2://load 3rd page 
			system("cls");//clear screen
			cout << R"( 
 HUNTING: Here you can fight monster to gain exp gold and loot. There is a change a LootBox will appear.
 LOOT BOX: There is a chance that you will gain buffs and loot, But also you can get cursed
		  Open at your own risk!.
 
 MAX LEVEL: The level cap is 20.
 RESET: here you reset your character and start over from level 1.
 DAMAGE: The more you fight you level up you get gold to buy items and thus deal more damage.

                                                                 
		)" << endl << endl;
			break;
		}

		//display choices
		cout << "0: Next Page" << endl;
		cout << "1: Previous Page" << endl;
		cout << "2: Close Instructions" << endl;
		cout << endl;
		
		//get user choice
		cout << "Choice: ";
		cin >> PageOption;
		cout << endl;

		switch (PageOption)//cary action based on users choice
		{
		case 0://if player chose next page
			if (InstructionPage < 2) //check to see that player isnt on last page
			{
				InstructionPage++; //increase page number by 1
			}
			break;
		case 1:// if player chose previous page
			if (InstructionPage > 0)//check to see that player isnt on first page
			{
				InstructionPage--; //decrease page number by 1
			}
			break;
		case 2://if player chose to exit the menu
			system("cls");//clear screen
			InInstructionsMenu = false; // chase bool state to false to exit the menu
			break;
		}
		
	}

			
}