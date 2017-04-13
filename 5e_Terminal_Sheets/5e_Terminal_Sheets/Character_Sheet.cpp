// Standard Libraries

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <conio.h>
#include <map>
#include <time.h>

// Custom Libraries and Variable Lists

#include "raceAbilities.h"
#include "terminalFuncttions.h"
#include "diceFunctions.h"
#include "globalVariables.h"

using namespace std;

int main(){

	// BEGIN: Menus for character loading and creation

	vector<string> OpenMenu; // Save or Load characters
	OpenMenu.push_back("New");
	OpenMenu.push_back("Load");

	vector<string> statAssign; // Full names for base Abilities
	statAssign.push_back("Strength");
	statAssign.push_back("Dexterity");
	statAssign.push_back("Constitution");
	statAssign.push_back("Intelligence");
	statAssign.push_back("Wisdom");
	statAssign.push_back("Charisma");

	vector<string> yesNo; // Generic Yes/No Menu Options
	yesNo.push_back("Yes");
	yesNo.push_back("No");

	// END

	string cLine;

	//BEGIN: Getting save names and # of saves and initializing a menu
	const string saveFile = "saved_characters.txt"; // constant location of the save file list

	int saveSize = getLines(saveFile); // # of lines in the save list
	ifstream LoadFile; // Filestream for character save names
	vector<string> CharMenu; // Menu List for character save names
	
	if (saveSize > 0){
		LoadFile.open(saveFile);

		for (int i = 0; i < saveSize; i++) {
			getline(LoadFile, cLine);
			CharMenu.push_back(cLine);
		}

		LoadFile.close();
	}
	else {
		OpenMenu.pop_back();
	}
	// END
	
	// BEGIN: Misc. Variable assignments and declarations
	int selection; // generic variable for use on menus

	vector<int> diceRolls; // stores the dice rolls for Abilities
	vector<string> diceStrings; // holds the dice rolls as a string for display

	bool rerollLow = false; // wether or not to reroll when the roll is < a certain number
	int rerollThresh = 10; // the reroll minimum. If the roll is < this value and rerollLow = true, the dice is rerolled until it get at or above this amount

	string charName; // pre-declaring the storage variable for the character name

	srand(time(NULL)); // initializes the random number generator
	//END

	// BEGIN: Base player stats (for point buy)
	map<string, int> baseAbils = {
			{ "str" , 8 }, { "dex" , 8 },
			{ "con" , 8 }, { "int" , 8 },
			{ "wis" , 8 }, { "chr" , 8 }
	};
	// END

	// BEGIN: Initial Title Sequence
	cout << setw(getCenterSize(intro)) << intro << endl;
	cout << setw(getCenterSize(subtitle)) << subtitle << endl << endl;

	if (saveSize < 1){ // Prints if "New" is the only option for characters
		cout << setw(getCenterSize(noSaves)) << noSaves << endl;
	}
	// END
	selection = choiceIn(OpenMenu, "center");

	if (OpenMenu[selection] == "Load"){ // Operations for loading a character
		selection = choiceIn(CharMenu, "center");
		clearLine(' ');
		cout << "Loading Character '" << CharMenu[selection] << "'" << endl;
	}
	else { // Operations for creating a character
		system("cls");

		cout << setw(getCenterSize(charWiz)) << charWiz << endl;
		cout << setw(getCenterSize(stepOne)) << stepOne << endl << endl;

		for (map<string, map<string,int>>::iterator i = raceList.begin(); i != raceList.end(); i++ ){
			racialList.push_back(i->first);
		}

		cout << "Please select a race to view: " << endl;
		selection = choiceIn(racialList);

		string raceName = racialList[selection];
		
		for (map<string, int>::iterator i = raceList[racialList[selection]].begin(); i != raceList[racialList[selection]].end(); i++){
			cout << i->first << " : +" << i->second << endl;
		}

		cout << "Do you want to be a " << raceName << "?" << endl;
		selection = choiceIn(yesNo);

		while (yesNo[selection] != "Yes"){
			system("cls");

			cout << setw(getCenterSize(charWiz)) << charWiz << endl;
			cout << setw(getCenterSize(stepOne)) << stepOne << endl << endl;

			cout << "Please select a race to view: " << endl;
			selection = choiceIn(racialList);
			raceName = racialList[selection];

			for (map<string, int>::iterator i = raceList[racialList[selection]].begin(); i != raceList[racialList[selection]].end(); i++){
				cout << i->first << " : +" << i->second << endl;
			}

			cout << "Do you want to be a " << raceName << "?" << endl;
			selection = choiceIn(yesNo);
		}

		system("pause");
		system("cls");

		cout << setw(getCenterSize(stepTwo)) << stepTwo << endl << endl;

		cout << "Reroll Low Numbers?" << endl;
		selection = choiceIn(yesNo);
		if (yesNo[selection] == "Yes"){
			rerollLow = true;

			cout << "\nWhat is the minimum you want to reroll on: ";
			cin >> rerollThresh;
		}

		cout << "Rolling 4d6, dropping the lowest dice" << endl;

		for (int i = 1; i <= 6; i++){
			int roll = rollStat(4, 6, true);

			if (rerollLow == true && roll <= rerollThresh){ // rerolls low stats
				while (roll <= rerollThresh)
				{
					//cout << "Since " << roll << " is < " << rerollThresh << ", rerolling!" << endl;
					roll = rollStat(4, 6, true);
				}
			}

			diceRolls.push_back(roll);
		}

		cout << "Rolls: ";

		for (int i = 0; i < diceRolls.size(); i++){
			cout << "[ " << diceRolls[i] << " ] ";
		}

		newLine(2);
		cout << "Please Assign each Ability a value:" << endl;

		for (int i = 0; i < statAssign.size(); i++){ // Converts all the INTs form diceRolls to STRINGs in diceStrings
			diceStrings.push_back(to_string(diceRolls[i]));
		}

		for (int i = 0; i < statAssign.size(); i++){
			cout << statAssign[i] << ": " << endl;
			selection = choiceIn(diceStrings);
			cout << endl;

			vector<string>::iterator index = (diceStrings.begin() + selection);
			diceStrings.erase(index); // Removed used options


			string shortened = bigToSmall[statAssign[i]];
			baseAbils[shortened] = diceRolls[selection];
		}
	}

	system("pause");
}
