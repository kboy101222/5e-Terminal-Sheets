using namespace std;

//| Racial Sizing Chart |		Racial Map Layout:
//|---|-----------------|		- Speed
//| # | Size		    |		- Size (Refer to Racial Sizing Chart)
//|---|-----------------|		- Ability Scores
//| 0 | Miniscule	    |
//| 1 | Tiny			|
//| 2 | Small		    |
//| 3 | Medium		    |
//| 4 | Large		    |
//| 5 | Huge			|
//| 6 | Gargantuan	    |
//| 7 | Collosal		|
//|___|_________________|

map <string, map<string, int>> raceList {
		{ "Dragonborn", {
				{ "speed", 30 },
				{ "size", 3 },

				{ "str", 2 },
				{ "chr", 1 }
		} },

		{ "Elf", {
				{ "speed", 30 },
				{ "size", 3 },

				{ "dex", 2 },

				{ "perception", 1 }
		} },

		{ "High Elf", {
				{ "speed", 30 },
				{ "size", 3 },

				{ "dex", 2 },
				{ "int", 1 }
		} }
};

map <string, map<string, string>> featList{
		{ "Dragonborn", {
				{ "Draconic Ancestry", "You have draconic ancestry. Choose one type of dragon from the Draconic Ancestry table. Your breath weapon and damage resistance are determined by the dragon type, as shown in the table." },
				{ "Breath Weapon", "You have draconic ancestry. Choose one type of dragon from the Draconic Ancestry table. Your breath weapon and damage resistance are determined by the dragon type, as shown in the table.\nWhen you use your breath weapon, each creature in the area of the exhalation must make a saving throw, the type of which is determined by your draconic ancestry. The DC for this saving throw equals 8 + your Constitution modifier + your proficiency bonus. A creature takes 2d6 damage on a failed save, and half as much damage on a successful one. The damage increases to 3d6 at 6th level, 4d6 at 11th level, and 5d6 at 16th level.\nAfter you use your breath weapon, you can’t use it again until you complete a short or long rest." },
				{ "Resistance", "You have resistance to the damage type associated with your draconic ancestry." },
				{ "Languages", "Draconic" }
		} },

		{ "Elf", {
				{ "Darkvision", "Accustomed to twilit forests and the night sky, you have superior vision in dark and dim conditions. You can see in dim light within 60 feet of you as if it were bright light, and in darkness as if it were dim light. You can’t discern color in darkness, only shades of gray." },
				{ "Keen Senses",  "You have proficiency in the Perception skill."},
				{ "Fey Ancestry", "You have advantage on saving throws against being charmed, and magic can’t put you to sleep." },
				{ "Trance", "Elves don’t need to sleep. Instead, they meditate deeply, remaining semiconscious, for 4 hours a day. (The Common word for such meditation is “trance.”) While meditating, you can dream after a fashion; such dreams are actually mental exercises that have become reflexive through years of practice. After resting in this way, you gain the same benefit that a human does from 8 hours of sleep" },
				{ "Languages", "Elvish" }
		} },

		{ "High Elf", {
				{ "longsword", "proficient" },
				{ "shortsword", "proficient" },
				{ "shortbow", "proficient" },
				{ "longbow", "proficient" }
		} }
};

vector<string> racialList;