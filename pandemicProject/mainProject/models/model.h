//
// Class: model
// Stores the game state.
//#include "Player.h"
#include<iostream>
#include<iomanip>
#include<sstream>
#include<limits>
#include<vector>
#include "Map.h"
#include "Deck.h"
#include "Player.h"
#include "PlayerMove.h"
#include "IDeck.h"



enum {badCities};
enum {red, yellow, blue, black};										//enumeration
enum {uncured, cured, eradicated};

class model
{
public:
	model();
	void setNumPlayers(int num){numPlayers = num;};									//sets number of players
	void setDifficulty(int diff){difficulty = diff;};								//sets difficulty
	void incOutbreak(){outbreak++;};												//increments the number of outbreaks occured
	void incCurrentRate();															//increments currentRate index
	
	void prepareGame();																//draws initial hands, assigns roles
	void initialInfect();
	void incResSta(){resSta++;};													//increments number of research stations in play
	void decResSta(){resSta--;};											
	void cureDisease(int);															//sets the status of a disease to cured
	void eradicateDisease(int);														//sets the status of a disease to eradicated
	void removeCubes(int color, int count){cubes[color] = cubes[color] - count;};	//reduces the amount of available color cubes by count (for after cubes have been added elsewhere)
	void infectCity(City*, int, int);												//adds cubes of specified color to city, removes cubes from board

	int outOfCubes(){return (cubes[red] < 0 || cubes[yellow] < 0 || cubes[blue] < 0 || cubes[black]<0);};//returns 1 if we ran out of a color
	int getNumPlayers(){return numPlayers;};										//gets number of players
	int getDifficulty(){return difficulty;};										//get difficulty
	int getOutbreak(){return outbreak;};											//gets number of outbreaks occured
	int getCubeCount(int disease){return(cubes[disease]);};							//gets the count of a single color of cube
	int getInfRate(){return( infRate[currentRate] );};								//gets the current infection rate (2,2,2,3,3,4,4)
	int getResSta() {return resSta;};												//gets current Research Station count
	string drawRole();																//returns a random role card, removes it from the role deck

	
		

	Player players[4];																//Not necessarily final implementation, here to illustrate functionality
	Map worldMap;																	//The map, bitch!
	Deck playerDeck;																//Player deck
	IDeck infectedDeck;																//Infected Deck
private:
	vector<string> rolesDeck;
	int numPlayers, currentRate, outbreak, resSta, difficulty;						// currentRate is index into inf level array
	int cubes[4];
	int infRate[7];
	int cureStatus[4];
	
	
	
};