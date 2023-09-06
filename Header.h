#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

// prototype
void openTheGame(vector<string>, int& points, int& gameCount);
void openScoreBoard(fstream& file, string playerName, int pPoints, int pGames);

#ifndef USER_H
#define USER_H
class User {
private:
	string userName = "";
	int totalPoints = 0;
	int gamesPlayed = 0;
public:
	// default constructor
	User();
	// copy constructor
	User(const User&);
	// mutators (setters)
	void setName(string);
	void setTotalPoints(int);
	void setGamesPlayed(int);
	// accessors (getters)
	string getName() const { return userName; }
	int getTotalPoints() const { return totalPoints; }
	int getGamesPlayed() const { return gamesPlayed; }

};
#endif 

