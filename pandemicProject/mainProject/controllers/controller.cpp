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
	ICard* iCardP = 0;			//pointer to an iCard

	
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

	model.prepareGame();															//assigns roles, draws initial player hands based on player count
	model.initialInfect();															//perform the initial infection of nine cities
		

	//
	//Begin basic mockup of program flow.  Short descriptions indicate function calls, displaying is omitted.
	//Most set/get methods belong to model or its subclasses, most logic is done by controller
	//Improper method names are probably used, and the rest are made up on the spot
	//This is not guaranteed to be correct right now.  Basically just a way to lay out individual tasks that we can all contribute to.
	while(true){//infinite for now
		for (int i=0; i<model.getNumPlayers(); i++)			//each players turn
		{
			for(int j = 0; j<4; j++){
				view.displayPlayerInfo(model.players[i].getPlayerName(), model.players[i].getPlayerRole(), model.players[i].getPlayerLocStr());
				view.printMenu();
				cin >> temp;

				if(temp==1){//player move code goes here**********************
					cityP = model.worldMap.locateCity(model.players[i].getPlayerLocStr());//store pointer to current location
					view.printAdj(cityP->getAdjCity());//print the list of adj cities
				}
				else{				
					view.printInfectedCities(model.worldMap.infectedList());//print inf cities list
					view.printCubeCount(model.getCubeCount(red), model.getCubeCount(yellow), model.getCubeCount(blue), model.getCubeCount(black)); //holy crap
					j--;													//don't consume a move
				}
			}

			for(int i=0; i<2; i++){
				//infect cities
				iCardP = model.infectedDeck.takeCard();//draw a card
			
				view.printInfConfirmation(iCardP->getName());//print confirmation of it
				model.infectCity(model.worldMap.locateCity(iCardP->getName()),iCardP->getColor(), 1);//infect the city
			}

			view.printInfectedCities(model.worldMap.infectedList());//print inf cities list after update
			view.printCubeCount(model.getCubeCount(red), model.getCubeCount(yellow), model.getCubeCount(blue), model.getCubeCount(black)); //holy crap
			
			if(model.outOfCubes()){ 
				view.printNoCubes();     //game over when no cubes remain
				cin.clear();
				cin.sync();
				cin.get();
				return 1;
			}
		}
	}


	
	

	

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






