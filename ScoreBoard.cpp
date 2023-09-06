#include "Header.h"
using namespace std;

void displayUserData(User user) {
	cout << setw(20) << right << user.getName()
		<< setw(15) << right << user.getTotalPoints()
		<< setw(15) << right << user.getGamesPlayed() << endl;
}

void openScoreBoard(fstream& file, string playerName, int pPoints, int pGames) {
	string name, strPts, strGames, line, scorePath;
	int pts, games, index = 0, target = 0, saveNum;

	// Array of objects
	// 10 are high score players
	// 1 is the current player
	// 1 is for temporary storage when sorting
	// 1 is for display purposes only (copy of the current player)
	User P[13];

	// header
	cout << string(5, '\n');
	cout << "Here are the Top 10 Players" << endl << endl;
	cout << setw(20) << right << "USERNAME"
		<< setw(15) << right << "TOTAL POINTS"
		<< setw(15) << right << "GAMES PLAYED" << endl;
	cout << setw(20) << right << "========"
		<< setw(15) << right << "============"
		<< setw(15) << right << "===========" << endl;


	// filling in the attributes for the top ten users
	for (int i = 0; i < 10; i++) {
		// reset the file
		file.clear();
		file.seekg(0, ios::beg);
		while (getline(file, line)) {
			if (index == target) {
				stringstream ss(line);
				getline(ss, name, '#');
				P[i].setName(name);

				getline(ss, strPts, '#');
				pts = stoi(strPts);
				P[i].setTotalPoints(pts);
				getline(ss, strGames, '#');
				games = stoi(strGames);
				P[i].setGamesPlayed(games);
			}
			index++;
		}
		index = 0;
		target++;
	}

	P[10].setName(playerName);
	P[10].setTotalPoints(pPoints);
	P[10].setGamesPlayed(pGames);

	P[12] = P[10]; // P[12] is for display purposes only, a copy of the player's attributes
	

	// sorting algorithm variables
	int maxElement = 0;
	index = 0;
	for (maxElement = 10; maxElement > 0; maxElement--) {
		for (index = 0; index < maxElement; index++) {
			if (P[index].getTotalPoints() < P[index + 1].getTotalPoints()) {
				P[11] = P[index];
				P[index] = P[index + 1];
				P[index + 1] = P[11];
			}
		}
	}


	//Displaying Top 5 and current player
	for (int i = 0; i < 10; i++)
		displayUserData(P[i]);

	cout << string(3, '\n') << "Current Player:" << endl << endl;
	displayUserData(P[12]);

	cout << endl;
	cout << "Would you like to save the high score list? (1 - YES) (2 - NO): ";
	cin >> saveNum;
	// check validity
	while (saveNum != 1 && saveNum != 2) {
		if (saveNum != 1 && saveNum != 2) {
			cout << "I get you. You must have mistyped. Happens. Try again." << endl;
			cout << "Would you like to save the high score list? (1 - YES) (2 - NO): ";
			cin >> saveNum;
		}
	}
	// saving the high score list
	if (saveNum == 1) {
		cout << "Enter Path and .txt name for Updated High Score List: ";
		cin >> scorePath;
		ofstream newFile;
		newFile.open(scorePath, ios::app);
		for (int i = 0; i < 10; i++) {
			newFile << P[i].getName() << '#' << P[i].getTotalPoints() << '#' << P[i].getGamesPlayed() << '\n';
		}
		cout << "File Saved..." << endl;
		newFile.close();
	}
	else
		cout << "No Save." << endl;
}