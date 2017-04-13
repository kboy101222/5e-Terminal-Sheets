using namespace std;

int getSmallest(vector<int> diceList);
int rollStat(int diceNum, int diceSize, bool dropLowest);

int rollStat(int diceNum, int diceSize, bool dropLowest){ // Takes a number of dice and the # of sides and returns an int containing the total
	int total = 0;
	bool elimedSmall = false;
	vector<int> diceList;
	vector<int>::iterator index;

	for (int i = 0; i < diceNum; i++){

		int roll = rand() % diceSize + 1;

		diceList.push_back(roll);
	}

	int smallest = diceList[getSmallest(diceList)];

	for (int i = 0; i < diceList.size(); i++){

		//cout << diceList[i] << " ";

		if (diceList[i] == smallest && elimedSmall == false && dropLowest == true){
			//cout << "[DROPPED]" << endl;
			diceList[i] = 0;
			elimedSmall = true;
		}
		else {
			total += diceList[i];
			//cout << "[ADDED]" << endl;
		}
	}

	//cout << "Total: " << total << endl;
	return total;
}

int getSmallest(vector<int> diceList){ // Gets the smallest dice roll from a vector of INTs
	int smallest = -1;
	int smallestIndex;

	for (int i = 0; i < diceList.size(); i++){
		if (smallest == -1){
			smallest = diceList[i];
			smallestIndex = i;
		}
		else {
			if (diceList[i] < smallest){
				smallest = diceList[i];
				smallestIndex = i;
			}
		}
	}

	return smallestIndex;
}