#include "Header.h"
using namespace std;

// proto
void displayTheBody(int);


void openTheGame(vector<string> list, int& points, int& gameCount) {
	const int MAXSIZE = 10; // no word is longer than 10 letters, can be changed if wordFile is edited
	const int LIMIT = 8; // attempts
	char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	int sizeOfList = list.size();
	int wordSize;
	int randNum;
	int guesses = 0;

	char playerGuess;

	bool correctGuess = false;
	bool gameOver = false;

	//RNG
	unsigned int seed = static_cast<unsigned int>(time(0));
	srand(seed);
	randNum = rand() % (sizeOfList - 1 + 1) + 1;

	// CLEAR SCREEN
	cout << string(50, '\n');

	// insert letters from word from vector to array
	char wordToGuess[MAXSIZE + 1];
	strcpy_s(wordToGuess, list[randNum].c_str());
	wordSize = strlen(wordToGuess);



	// populate the displayWord & check if it's correct
	char displayWord[MAXSIZE + 1];
	for (int i = 0; i < wordSize; i++)
		displayWord[i] = '_';

	// actually playing the game
	do {
		// display the display
		for (int i = 0; i < wordSize; i++) {
			cout << displayWord[i] << ' ';
		}
		cout << '\n';

		displayTheBody(guesses);

		// Display the alphabet
		cout << "Guesses Available:" << endl;
		for (int i = 0; i < 26; i++) {
			cout << alphabet[i] << ' ';
		}
		cout << endl << endl;

		// Player input
		cout << "Enter Your Guess: ";
		cin >> playerGuess;
		playerGuess = (char)toupper(playerGuess);


		// VALIDATE GUESS
		while (!isalpha(playerGuess)) {
			cout << "Please enter a letter, like the ones in the alphabet" << endl;
			cout << "Enter Your Guess: ";
			cin >> playerGuess;
			playerGuess = (char)toupper(playerGuess);
		}

		// check guess
		for (int i = 0; i < wordSize; i++) {
			if (playerGuess == wordToGuess[i]) {
				displayWord[i] = playerGuess;
				correctGuess = true;
			}
		}

		// add the guess if it was a wrong guess
		if (correctGuess == false)
			guesses++;
		correctGuess = false;

		// remove display option
		for (int i = 0; i < 26; i++) {
			if (playerGuess == alphabet[i])
				alphabet[i] = '_';
		}

		// check if game is over
		for (int i = 0; i < wordSize; i++) {
			if (displayWord[i] != '_' || guesses > LIMIT)
				gameOver = true;
			else {
				gameOver = false;
				break;
			}
		}

		// clear screen
		cout << string(50, '\n');

	} while (gameOver == false);

	// Reveal answer
	cout << "The word was ";
	for (int i = 0; i < wordSize; i++)
		cout << wordToGuess[i];
	cout << endl << endl;

	// Show your work
	displayTheBody(guesses);
	if (guesses <= LIMIT) {
		cout << "YOU'RE WINNER" << endl;
		points++;
		cout << "+1 Point" << endl;
	}
	else {
		cout << "You most likely lost" << endl;
		cout << "No Points Added" << endl;
	}
	// Before you leave, count the game
	gameCount++;
}


// Function:   displayTheBody
// Parameters: integer
// Returns:    nothing
// Descr:      based on the amount of guesses, the hanged man body limbs will appear
void displayTheBody(int guess) {
	if (guess == 0) {
		cout << " " << endl;
		cout << " " << endl;
		cout << " " << endl;
	}
	if (guess == 1) {
		cout << "   0" << endl;
		cout << " " << endl;
		cout << " " << endl;
	}
	if (guess == 2) {
		cout << "   0" << endl;
		cout << "   | " << endl;
		cout << " " << endl;
	}
	if (guess == 3) {
		cout << "   0" << endl;
		cout << "  /| " << endl;
		cout << " " << endl;
	}
	if (guess == 4) {
		cout << "   0" << endl;
		cout << "  /|\\" << endl;
		cout << "  " << endl;
	}
	if (guess == 5) {
		cout << "   0" << endl;
		cout << "  /|\\" << endl;
		cout << "  / " << endl;
	}
	if (guess == 6) {
		cout << "   0" << endl;
		cout << "  /|\\" << endl;
		cout << "  / \\" << endl;
	}
	if (guess == 7) {
		cout << "   0" << endl;
		cout << "  /|\\" << endl;
		cout << " _/ \\" << endl;
	}
	if (guess == 8) {
		cout << "   0" << endl;
		cout << "  /|\\" << endl;
		cout << " _/ \\_" << endl;
		cout << "\n*LAST CHANCE*" << endl;
	}
	if (guess == 9) {
		cout << "   X" << endl;
		cout << "  /|\\" << endl;
		cout << " _/ \\_" << endl;
	}
	cout << endl;
}