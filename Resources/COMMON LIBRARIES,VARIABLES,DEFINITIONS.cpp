//Includes Libraries to make this game work
#include "stdafx.h" // Visual studio always need this header
#include <iostream> // To manipulate input output
#include <string> // String manipulation library
#include <Windows.h> // Used to change console colours
#include <cstdlib> // The random Library
#include <ctime> // Imports time library
#include <conio.h> // 
#include "libsqlite.hpp" // The sqlite connection class
#include <stdlib.h> //Used for random numbers
#include <vector> // Vectors are like dynamic arrays
#include <algorithm> // used to shuffle vectors
#include <map>

using namespace std; //Using thr std namespace to avoid adding std:: all the time

//Declaring functions from before to work in the entire project
void F_LOOT_BOX();
void F_HUNT_MENU();

// Defining colours
#define MAGENTA			5
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15

// Defining effetcs
#define NONE		0
#define POISONED	1
#define DAMAGE_INCREASE	2
#define NO_POTIONS 3

// Defining quest modes
bool questing = false;
#define NO_MODE 0
#define KILL_MODE 1
#define COLLECT_MODE 2
int QUEST_OBJECTIVE = 0;
int QUEST_MODE = 0;
int MOB_COUNT = 0;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Gets the colour we choose and changes the text colour

//Character Related
string PLAYER_NAME;
int PLAYER_LEVEL;
int PLAYER_EXP;
int PLAYER_EXP_MAX;
int PLAYER_HP;
int PLAYER_HP_MAX;
int PLAYER_DEFENCE;
int PLAYER_ATTACK_MIN;
int PLAYER_ATTACK_MAX;
int PLAYER_STAMINA;
int PLAYER_STAMINA_MAX;
int PLAYER_GOLD;
int PLAYER_HP_POTIONS;
int PLAYER_LUCK;
int PLAYER_UID;
int PLAYER_ENHANCEMENT_STONES;
int CURRENT_EFFECT;
int QUEST_STAGE;

//Armor stats
string ARMOR_NAME;
int ARMOR_DEFENCE;
int ARMOR_HP;
int ARMOR_ENHANCEMENT_LEVEL;

//Weapon Stats
string WEAPON_NAME;
int WEAPON_ATTACK_MIN;
int WEAPON_ATTACK_MAX;
int WEAPON_ENHANCEMENT_LEVEL;

//Combat Related
int ATTACK_MAXIMUM;
int ATTACK_MINIMUM;
int DEAL_DAMAGE;


//Effects Section
int EFFECT_TYPE;
int EFFECT_DURATION;
int EFFECT_DAMAGE_INCREASE;
int RAND_PERCENTAGE;




//Menu Bools
bool Playing;
bool InCombat;
bool InShop;
bool InDialog;
bool Reseting;
bool ArmorShop;
bool WeaponShop;
bool InInventory;
bool ViewingArmors;
bool ViewingWeapons;
bool StartMenu;
bool InLoot;
bool InInstructionsMenu;
bool InQuest;

//Monster Related
vector<int> MONSTER_LIST;
string MONSTER_NAME;
int MONSTER_HP;
int MONSTER_ATTACK_MIN;
int MONSTER_ATTACK_MAX;
int MONSTER_DEFENCE;
int MONSTER_GOLD_REWARD;
int MONSTER_EXP_REWARD;

//Instruction Menu
int InstructionPage = 0;
