using namespace std;

// BEGIN: String Constants for title sequences
string intro = "Welcome to 5e Terminal Sheets!";
string subtitle = "By Kyle George";
string charWiz = "Welcome to the Character Wizard";
string noSaves = "No saved characters found!";

string stepOne = "Step One: Race and Class";
string stepTwo = "Step Two: Ability Scores";
string stepThree = "Step Three: Skills and Feats";
// END

map<string, string> bigToSmall = { // Translates the full text of Ability Options to the abbr text
		{ "Strength", "str" }, { "Dexterity", "dex" },
		{ "Constitution", "con" }, { "Intelligence", "int" },
		{ "Wisdom", "wis" }, { "Charisma", "chr" }
};