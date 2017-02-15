void F_SAVE() //Saves any changes to the database
{
	try
	{
		sqlite::sqlite db("Game.db"); //Opens the Database

		auto cur = db.get_statement(); //declaring cur as an sql Statement

									   //the Sql statement to update everything
		cur->set_sql("UPDATE Character SET Level = '" + to_string(PLAYER_LEVEL) +
			"', Name = '" + PLAYER_NAME +
			"', Level = '" + to_string(PLAYER_LEVEL) +
			"', Hp = '" + to_string(PLAYER_HP) +
			"', HpMax = '" + to_string(PLAYER_HP_MAX) +
			"', Exp = '" + to_string(PLAYER_EXP) +
			"', ExpMax = '" + to_string(PLAYER_EXP_MAX) +
			"', Defence = '" + to_string(PLAYER_DEFENCE) +
			"', AttackMin = '" + to_string(PLAYER_ATTACK_MIN) +
			"', AttackMax = '" + to_string(PLAYER_ATTACK_MAX) +
			"', Stamina = '" + to_string(PLAYER_STAMINA) +
			"', StaminaMax = '" + to_string(PLAYER_STAMINA_MAX) +
			"', Gold = '" + to_string(PLAYER_GOLD) +
			"', HpPotion = '" + to_string(PLAYER_HP_POTIONS) +
			"', Luck = '" + to_string(PLAYER_LUCK) +
			"', UID = '" + to_string(PLAYER_UID) +
			"', EnhancementStones = '" + to_string(PLAYER_ENHANCEMENT_STONES) +
			"', QuestStage = '" + to_string(QUEST_STAGE) +
			"' WHERE ID = 1");
		cur->exec();//Executes the statement
	}
	catch (sqlite::exception e)      // catch all sql issues
	{
		std::cerr << e.what() << std::endl; //print Errors
	}
}