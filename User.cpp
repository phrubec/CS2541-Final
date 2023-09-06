#include "Header.h"
using namespace std;

// default constructor
User::User() : totalPoints(0), gamesPlayed(0) {
	userName = "";
}

// copy constructor
User::User(const User& P) {
	userName = P.userName;
	totalPoints = P.totalPoints;
	gamesPlayed = P.gamesPlayed;
}

// mutator setters
void User::setName(string inpName) {
	userName = inpName;
}
void User::setTotalPoints(int ttlPNTS) {
	totalPoints = ttlPNTS;
}
void User::setGamesPlayed(int gPLYD) {
	gamesPlayed = gPLYD;
}