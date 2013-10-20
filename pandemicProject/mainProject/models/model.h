//
// Class: model
// Stores the game state.
#include "Player.h"


class model
{
public:
	model();
	void setNumPlayers(int);												//sets number of players
	void incOutbreak();														//increments the number of outbreaks occured
	void incCurrentRate();													//increments currentRate index


	void cureDisease(int);													//sets the status of a disease to cured
	void eradicateDisease(int);												//sets the status of a disease to eradicated
	void removeCubes(int color, int count);									//reduces the amount of available color cubes by count (for after cubes have been added elsewhere)

	int getNumPlayers();													//gets number of players
	int getOutbreak();														//gets number of outbreaks occured
	int getCubeCount(int);													//gets the count of a single color of cube
	int getInfRate();														//gets the current infection rate (2,2,2,3,3,4,4)

	
	enum {red, yellow, blue, black};										//enumeration
	enum {uncured, cured, eradicated};

	Player players[4];														//Not necessarily final implementation, here to illustrate functionality

private:
	int numPlayers, currentRate, outbreak;									// currentRate is index into inf level array
	int cubes[4];
	int infRate[7];
	int cureStatus[4];
	//Player players[4];
};