void F_LOAD_STATS()
{
	//display stats to player with corresponding headings
	SetConsoleTextAttribute(hConsole, LIGHTCYAN);
	cout << "= Character Sheet =" << endl << endl;
	SetConsoleTextAttribute(hConsole, WHITE);
	cout << "= Name: " << PLAYER_NAME << endl;
	cout << "= Level: " << PLAYER_LEVEL << endl;
	cout << "= Exp: " << PLAYER_EXP << "/" << PLAYER_EXP_MAX << endl;
	cout << endl;
	cout << "= HP: " << PLAYER_HP << "/" << PLAYER_HP_MAX + ARMOR_HP << endl;
	cout << "= Stamina: " << PLAYER_STAMINA << "/" << PLAYER_STAMINA_MAX << endl;
	cout << "= Damage: " << PLAYER_ATTACK_MIN + WEAPON_ATTACK_MIN << " - " << PLAYER_ATTACK_MAX + WEAPON_ATTACK_MAX << endl;
	cout << "= Defence: " << PLAYER_DEFENCE + ARMOR_DEFENCE << endl;
	cout << "= Effect: " << F_RETURN_EFFECT_NAME(CURRENT_EFFECT) << endl;
	cout << endl;
	cout << "= Gold: " << PLAYER_GOLD << endl;
	cout << "= Hp potions: " << PLAYER_HP_POTIONS << endl; 
	cout << "= EnhancementStones: " << PLAYER_ENHANCEMENT_STONES << endl;
	cout << "= Luck: " << PLAYER_LUCK << "%" << endl;
	cout << endl;
}