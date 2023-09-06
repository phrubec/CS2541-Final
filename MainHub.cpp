#include "Header.h"
using namespace std;

// proto
bool openFileIn(fstream&, string);

int main() {
	// Various Variables Declared
	int menuOption;
	vector<string> wordList;

	
	// opening a file variables
	fstream wordsFile;
	fstream scoreFile;
	string filePath;
	string scorePath;
	string line;

	// pointers
	int* points = new int(0);
	int* gameCounter = new int(0);
	string* inpName = new string();
	

	// check file validity
	cout << "Please open the file of words: ";
	cin >> filePath;

	if (!openFileIn(wordsFile, filePath)) {
		cout << "Error: Cannot open the file." << endl;
		exit(-2);
	}

	cout << "Please open the file for high scores: ";
	cin >> scorePath;
	if (!openFileIn(scoreFile, scorePath)) {
		cout << "Error: Cannot open the file." << endl;
		exit(-2);
	}


	// Put into vector
	while (getline(wordsFile, line)) {
		wordList.push_back(line);
	}

	cin.ignore();
	cout << "Enter Username: ";
	getline(cin, *inpName);
	

	// LOOP AND MENU SELECT
	do {
		cout << string(3, '\n');
		cout << *inpName << "\'s Game Menu" << endl;
		cout << "1. Play The Game" << endl;
		cout << "2. Review High Scores" << endl;
		cout << "3. Quit Game" << endl;
		cin >> menuOption;


		switch (menuOption) {
		case 1: // PLAYING THE GAME
			openTheGame(wordList, *points, *gameCounter);
			
			// show the data
			cout << *inpName << " has played " << *gameCounter << " games with a total score of: " << *points << " points" << endl;
			break;
		case 2: // CREATING THE HIGHSCORES
			openScoreBoard(scoreFile, *inpName, *points, *gameCounter);
			break;
		case 3: // LEAVE
			cout << "Leaving";
			break;
		}

	} while (menuOption != 3);


	// close files & delete memory
	scoreFile.close();
	wordsFile.close();

	delete inpName;
	delete points;
	delete gameCounter;
	return EXIT_SUCCESS;
}

// Function:   openFileIn
// Parameters: fstream and string
// Returns:    boolean
// Descr:      checks to see if you can even open the file
bool openFileIn(fstream& file, string name) {
	bool status;
	file.open(name, ios::in);
	if (file.fail())
		status = false;
	else
		status = true;
	return status;
}
