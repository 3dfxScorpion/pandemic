//
// Controller
// Performs the logic driving the game (checks hand counts, calls view and model to change game state, monitors quit conditions etc)

#include "model.h"
#include "view.h"
#include<iostream>
#include<iomanip>
#include<sstream>
#include<limits>
#include<vector>
#include "Map.h"
#include "Deck.h"
#include "Player.h"
#include "PlayerMove.h"

using std::cin;
using std::cout;
using std::setw;
using std::string;
using std::streamsize;
using std::numeric_limits;
using std::ostringstream;


void setupBoard();
void buildResearch(City*);

int main()
{
	

	view view;
	model model;
	
	
	int temp;
	string tempStr;
	City* cityP = 0;			//pointer to a city
	vector<Card*> cardP;		//temporary

	// Print title, get num players
	view.printTitle();			// view handles all input and output
	cin >> temp;				// controller is what reads in values and performs most of the logic
	model.setNumPlayers(temp);	//model stores the game's state

	// Read in player names
	for(int i = 0; i < model.getNumPlayers(); i++)		//controller controls the flow
	{
		view.printNamePrompt(i);						// view prints prompt
		cin.clear();									//clear input buffer
		cin.sync();										//was being weird, but this fixed it
		getline(cin, tempStr, '\n');					//read player name							
		model.players[i].setPlayerName(tempStr);		//model stores data
	}

	//get difficulty
	view.printDiffPrompt();
	cin >> temp;
	cin.clear();
	cin.sync();
	model.setDifficulty(temp);

	// Populate World Map
	if ( model.worldMap.populateMap("Cities.txt") != 0 ) {
        cout << "Please make sure file is located in working directory...\n";    //update later to throw exception
        return 0;
    }
		

	//
	//Begin basic mockup of program flow.  Short descriptions indicate function calls, displaying is omitted.
	//Most set/get methods belong to model or its subclasses, most logic is done by controller
	//Improper method names are probably used, and the rest are made up on the spot
	//This is not guaranteed to be correct right now.  Basically just a way to lay out individual tasks that we can all contribute to.
	

	//Set up the game:
	//	Place research  and players in atlantastation in Atlanta
	//	Assign roles to players
	//	Shuffle deck, distribute epidemic cards evenly (4, 5, or 6 epids for easy med hard)
	//	Deal cards: 2 players-4 cards, 3players-3 cards, 4 players -2 cards
	cityP = model.worldMap.locateCity("Atlanta");//find atlanta
	cout << ".";
	cityP->setResearchStation(true);//set the station
	model.incResSta();//increment ressta count
	for (int i = 0; i < model.getNumPlayers(); i++)  //for all players
	{
		model.players[i].setPlayerRole(model.drawRole());	// assign a random role
		model.players[i].setPlayerLocation(cityP);			//set all player locations to Atlanta
	}

	//draw inital hand:
	// players initially draw (6-numPlayers) cards
	for(int j=0; j < model.getNumPlayers(); j++)
	{
		for(int i=0; i < (6-model.getNumPlayers()); i++)					// inefficiency ignored for the moment
		{
			model.players[j].addCard(model.playerDeck.takeCard());		//draw a card
		}
	}



	//Infect nine cities:
	//  perhaps initialInfect method in model - 3 cities x 3 cubes, 3 cities x 2 cubes, 3 cities x 1 cube
	//  NEEDS: infection deck  
	



	//Main game loop - this way to check game ending conditions is absolutely temporary, as meeting any one of the quit conditions would have no effect
	//	on gameplay until all users finish turns this round.  Maybe throw exceptions?
/* while ( outbreaks<8  &&  allCubes > -1  &&  !deck.empty  &&  !allDiseasesCured)
	
	//Action phase
	for (int i = 0; i<4; i++)
	{
		display all possible move/play actions, let user choose
		ACtions are: Drive/ferry, Direct flight, charter flight, shuttly flight    
		             Build resStation, Treat disease, share knowledge, discover cure
		controller should check the validity of a move (ie: verifying player has enough cards of one color to cure a disease
		  and determining if a new resStation is added or if another is relocated
		doMove() - for all possible moves

		If(player used event card - or other action that isn't limited in this phase)
			doAction
			i--;
	}*/



/*	//Draw cards  -- random listing of required functionality, may not be ideal just brainstorming
	call deck method to draw 2 cards from the deck
	if(first card == epidemic || second card == epidemic)
	   infection rate goes up
	   bottom card drawn from infection deck
	   if(drawnCity has cubes of it's color)
	      make the cube count on that city 3
		  doOutbreak();     // this method should call itself if chain reaction happens I think.
							// see rule book for description of outbreak 
	   if (first card == epidemic && second card == epidemic)
	       give user option to perform event card between epidemics
		   do these steps again: infectionrate goes up, bottom card, add cubes, check for outbreak, shuffle
	   else
	       reshuffle the infection deck discard and place the cards at the top of the deck

	//Infect Cities-
	for(int i = 0; i < infection Rate; i++)
	{
		draw infection card
		if(cubes of cityColor in the city <3)
			Add 1 cube of cityColor color
		else
			outbreak()  
	}
*/
	cin.get();
	return 0;

	
}




void setupBoard()
{
	//Set up the game:
	//	Place research station in Atlanta
	//	Assign roles to players
	//	Shuffle deck, distribute epidemic cards evenly (4, 5, or 6 epids for easy med hard)
	//	Deal cards: 2 players-4 cards, 3players-3 cards, 4 players -2 cards


	return;
}


// Recieves a pointer to a city, builds research station there
// -needs to include process for move a city from one place to another
void buildResearch(City* location)
{
	
}