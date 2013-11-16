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

	while(tmp)
	{
		try
		{			
			Controller controller;								// I don't really like this inside of a loop. Temp for now until I decide the best way to 
																// handle exceptions while allowing user to restart
			controller.run();
		}	
		catch(PandemicException const& e)
		{
			cerr << "\nException caught: " << e.what() << "\n" << endl;
		}
	
		cout << "Play again? [1 for yes, - for no]: ";
		cin >> tmp;
	}


	
	return 0;

	
}






