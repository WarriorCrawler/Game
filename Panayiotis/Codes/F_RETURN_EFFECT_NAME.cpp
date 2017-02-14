string F_RETURN_EFFECT_NAME(int EFF_NUM)
{
	// Create map that links the Effect Number with its name
	map<int, string> EFFECT_MAP = {
		{ 0, "NONE" },
		{ 1, "POISONED" },
		{ 2, "DAMAGE INCREASE" },
		{ 3, "NO POTIONS" }
	};

	return EFFECT_MAP[EFF_NUM]; //return the name of the effect Number
}