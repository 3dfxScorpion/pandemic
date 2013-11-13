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

		while(tmp)
		{
		
			controller.run();		

			cout << "Would you like to try again?\n1. Yes\n2. No\n:";
			cin >> tmp;
			cin.ignore();
		}	

	cin.get();
	return 0;

	
}






