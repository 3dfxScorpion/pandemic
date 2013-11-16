//
// Controller
// calls view and model to change game state, monitors quit conditions etc)


#include "Controller.h"
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
	int tmp = 1;
	Controller controller;
	while(controller.run())
	{
															
	}


	
	return 0;

	
}






