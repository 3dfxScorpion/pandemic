//
// Class: model
// Stores the game state.
//#include "Player.h"
#ifndef MODEL_H
#define MODEL_H
#include<iostream>
#include<iomanip>
#include<sstream>
#include<limits>
#include<vector>
#include "Map.h"
#include "view.h"
#include "Deck.h"
#include "Player.h"
#include "PlayerMove.h"


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
	
	void incResSta(){resSta++;};													//increments number of research stations in play
	void decResSta(){resSta--;};											
	void cureDisease(int);															//sets the status of a disease to cured
	void eradicateDisease(int);														//sets the status of a disease to eradicated
	void removeCubes(int color, int count){cubes[color] = cubes[color] - count;};	//reduces the amount of available color cubes by count (for after cubes have been added elsewhere)

	int getNumPlayers(){return numPlayers;};										//gets number of players
	int getDifficulty(){return difficulty;};										//get difficulty
	int getOutbreak(){return outbreak;};											//gets number of outbreaks occured
	int getCubeCount(int disease){return(cubes[disease]);};							//gets the count of a single color of cube
	int getInfRate(){return( infRate[currentRate] );};								//gets the current infection rate (2,2,2,3,3,4,4)
	int getResSta() {return resSta;};												//gets current Research Station count
	string drawRole();																//returns a random role card, removes it from the role deck
    view viewer();
		

	Player players[4];																//Not necessarily final implementation, here to illustrate functionality
	Map worldMap;																	//The map, bitch!
	Deck playerDeck;																//Player deck
    
    void CPgetEventCard(Deck*);
    void DmovePlayerToPlayerCity(Player*);
    void DmovePlayerAsYourself(Player*);
    void MtreatDisease(string);
    void MautoCure();
    void OEbuildResearchStation(Player *);
    void OEmove(City*);
    bool QSautoContain();
    void RgiveCityCard(Player*);
    void Scure(string);
private:
	vector<string> rolesDeck;
	int numPlayers, currentRate, outbreak, resSta, difficulty;						// currentRate is index into inf level array
	int cubes[4];
	int infRate[7];
	int cureStatus[4];
    
	PlayerMove mover;
	//vector<string> rolesDeck;												//pseudo deck of role cards

	
};


#endif
