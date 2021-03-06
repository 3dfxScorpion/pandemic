//
// Class: model
// Stores the game state.
//#include "Player.h"
#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <vector>
#include <string>
#include "Map.h"
#include "Deck.h"
#include "Player.h"
#include "PlayerMove.h"
#include "IDeck.h"
#include "PandemicException.h"
#include "dataManip.h"

using std::getline;

enum {badCities};                                                        //odd
enum {red, yellow, blue, black};                                        //cube colors
enum {uncured, cured, eradicated};

class Model
{
public:
    Model();
    void checkMedicSpecial();
    string colorToString(int);
    bool QSautoContain(ICard*);
	bool QSautoContain(City* cityP);
    void treatDisease(int col);
	bool canTreatDisease(int col);
	void setDoInfect(){doInfect = 1;}
	void unsetDoInfect(){doInfect = 0;}
	int getDoInfect(){return doInfect;}
    void setNumPlayers(int num) {
        numPlayers = num;
    }
    void setDifficulty(int diff) {
        difficulty = diff;
    }
    void incrementOutbreak() {
        outbreak++;

        if(outbreak==8)
        {
            throw PandemicException("Too many outbreaks! A worldwide panic has occurred!");
        }
    }
    void addCubes(int color,int count){
        cubes[color] += count;  }
    void incrementCurrentRate();
    void prepareGame();                                                                //draws initial hands, assigns roles
    void initialInfect();
    void incResSta() {
        resSta++;
    }
	void decResSta() {
		resSta--;
	}
    void cureDisease(int);                                                            //sets the status of a disease to cured
    bool allCured();
    void eradicateDisease(int);                                                        //sets the status of a disease to eradicated
    void removeCubes(int color, int count) {
        cubes[color] = cubes[color] - count;
    }    //reduces the amount of available color cubes by count (for after cubes have been added elsewhere)
    void infectCity(City*, int, int);                                                //adds cubes of specified color to city, removes cubes from board
    int getNumPlayers() {
        return numPlayers;
    }
    int getDifficulty() {
        return difficulty;
    }
    int getOutbreak() {
        return outbreak;
    }
    int getCubeCount(int disease) {
        return(cubes[disease]);
    }                                    //gets the count of a single color of cube
    int getInfRate() {
        return( infRate[currentRate] );
    }                                    //gets the current infection rate (2,2,2,3,3,4,4)
    int getResSta() {
        return resSta;
    }                                                //gets current Research Station count
    int getCureStatus(int i){
        return cureStatus[i];
    }
	void setCureStatus(int i, int status) {
		cureStatus[i] = status;
	}
    void setOutbreak(int outBreak) {
        outbreak = outBreak;
    }
    void setInfection(int infection) {
        currentRate = infection;
    }
    void setCubeCount(int disease, int number) {
        cubes[disease] = number;
    }
    bool canCureDisease(int);
    int getCardIndex(string, Player*);//Takes the player and the name of a card and returns the hand index.
    vector<Player*> getSharablePlayers(string);
    void doCureDisease(int);
    bool canBuildResearchStation();
    void buildResearchStation();
	void buildResearchStation(City*);
	void removeResearchStation(City*);
    bool canCharterFlight();
    void charterFlight(string);
    bool canGetKnowledge();
    bool canGiveKnowledge();
    void giveCard(Player* p,string s);//Current player gives parameter p the card name that matches parameter s
    void getCard(Player* p,string s);//Current player gets a card from parameter p that matches parameter s
    vector<string> getReasearchStationCities();//returns vector containing all of the cities with research stations
    string drawRole();                    //returns a random role card, removes it from the role deck
    void savegame(string filename);
    void loadgame(string filename);
    void buildMap(){worldMap.populateMap("Cities.txt");}                //populate the map}}
	void setResSta(int num) {resSta = num;}
    void doOutbreak(City*, int, vector<string>&);                       //does outbreak
    bool alreadyOutbreak(string, vector<string>);                       //checks a vector for presence of a string
	int getCurrentPlayerIndex() { return currentPlayerIndex; }
	int getMovesUsed() { return movesUsed; }
	void setCurrentPlayerIndex(int index) { currentPlayerIndex = index; }
	void setMovesUsed(int moves) { movesUsed = moves; }
    void decMovesUsed(){movesUsed--;}
    void incMovesUsed(){movesUsed++;}
	void incCurrentPlayerIndex(){currentPlayerIndex++;}

    vector<Player*> players;											
    Map worldMap;														//The map, bitch!
    Deck playerDeck;													//Player deck
    IDeck infectedDeck;													//Infected Deck
    PlayerMove mover;
private:
    vector<string> rolesDeck;
    int numPlayers, currentRate, outbreak, resSta, difficulty;                        // currentRate is index into inf level array
    int cubes[4];
    int infRate[7];
    int cureStatus[4];
	int doInfect;
	int currentPlayerIndex;
	int movesUsed;
};
#endif
