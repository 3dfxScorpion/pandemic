#include<iostream>
#include<iomanip>
#include<limits>
#include<ostream>
#include<string>
#include "Menu.h"

using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;
using std::max;
using std::numeric_limits;
using std::ostringstream;
using std::streamsize;

string Menu::menuCities(Map& m) {
    ostringstream out;
    ostringstream str[26];
    vector<City*> menuMap = m.getWorldMap();
    vector<City*>::iterator cItr = menuMap.begin();  //city iterator

    for ( size_t i = 0; i < 2; i++ ) {               // two loops for two columns
        str[0] << setw(20) <<  left   << "City:" << setw(8)
               << "Black:" << setw(7) << "Blue:" << setw(6)
               << "Red:"   << setw(7) << "Yellow:";
        if ( i == 0 )
            str[0] << "  ";                          // space, the final frontier...
        str[1] << "==================================================";

        for ( size_t j = 2; j < 26; j++ ) {
            City* tmp = *cItr;
            string cityStr = ( tmp->getResearchStationBool() )  
                ? tmp->getCityName() + "-(R)" 
                : tmp->getCityName(); 
            str[j] << setw(21) << left << cityStr << " "
                   << setw(6)  << tmp->getInfectedBlack()  << " "
                   << setw(6)  << tmp->getInfectedBlue()   << " "
                   << setw(6)  << tmp->getInfectedRed()    << " "
                   << setw(6)  << tmp->getInfectedYellow() << " ";
            cItr++;
        }
    }

    for ( size_t i = 0; i < 25; i++ ) {
        out << str[i].str() << "\n";
    }

    return out.str();
}

string menuAdjCities(City* c) {         // static method for external purposes
    size_t cityID = 1;
    const size_t totalCount = 8;        // number of slots for cards
    ostringstream out;
    ostringstream str[totalCount];
    vector<string> adjList = c->getAdjCity();  // adjList vector;
    vector<string>::iterator cItr;      // city iterator

    str[0] << setw(12) << right << "Adjacent Cities ";
    str[1] << setw(12) << right << "----------------";

    size_t cityCount = adjList.size();  // size of adjacent city vector
    size_t cityIndex = 2;               // city index is third line down
    // first display actual cards in city
    for ( cItr = adjList.begin(); cItr != adjList.end(); cItr++ ) {
        string cTmp = *cItr;
        str[cityIndex++] << "(" << cityID++ << ")"
                         << setw(25) << left << cTmp;
    }
    // display blanks if no more cities to chow
    for ( size_t i = cityIndex; i < totalCount; i++ ) {
        string tmp = " ";
        str[cityIndex++] << setw(25) << left << tmp;
    }

    for ( size_t i = 0; i < totalCount; i++ ) {
        out << str[i].str() << "\n";
    }
    return out.str();
}

string menuStringVector(vector<string> RScities, string label) {         // static method for external purposes
    size_t cityID = 1;
    const size_t totalCount = 8;        // number of slots for cards
    ostringstream out;
    ostringstream str[totalCount];
    
    vector<string>::iterator cItr;      // city iterator
    
    str[0] << setw(12) << right << label;
    str[1] << setw(12) << right << "-----------------";
    
    size_t cityCount = RScities.size();  // size of city vector
    size_t cityIndex = 2;               // city index is third line down
    // first display actual cards in city
    for ( cItr = RScities.begin(); cItr != RScities.end(); cItr++ ) {
        string cTmp = *cItr;
        str[cityIndex++] << "(" << cityID++ << ")"
        << setw(25) << left << cTmp;
    }
    // display blanks if no more cities to chow
    for ( size_t i = cityIndex; i < totalCount; i++ ) {
        string tmp = " ";
        str[cityIndex++] << setw(25) << left << tmp;
    }
    
    for ( size_t i = 0; i < totalCount; i++ ) {
        out << str[i].str() << "\n";
    }
    return out.str();
}


string menuPlayersVector(vector<Player*> players) {         // static method for external purposes
    size_t cityID = 1;
    const size_t totalCount = 5;        // number of slots for cards
    ostringstream out;
    ostringstream str[totalCount];
    
    vector<Player*>::iterator cItr;      // city iterator
    
    str[0] << setw(12) << right << "Players ";
    str[1] << setw(12) << right << "-----------------";
    
    size_t cityCount = players.size();  // size of city vector
    size_t cityIndex = 2;               // city index is third line down
    // first display actual cards in city
    for ( cItr = players.begin(); cItr != players.end(); cItr++ ) {
        Player* cTmp = *cItr;
        str[cityIndex++] << "(" << cityID++ << ")"
            << setw(25) << left << cTmp->getPlayerName();
    }
    // display blanks if no more cities to chow
    for ( size_t i = cityIndex; i < totalCount; i++ ) {
        string tmp = " ";
        str[cityIndex++] << setw(25) << left << tmp;
    }
    
    for ( size_t i = 0; i < totalCount; i++ ) {
        out << str[i].str() << "\n";
    }
    return out.str();
}

string menuCardsVector(vector<Card*> cards, string label) {         // static method for external purposes
    size_t cityID = 1;
    const size_t totalCount = 8;        // number of slots for cards
    ostringstream out;
    ostringstream str[totalCount];
    
    vector<Card*>::iterator cItr;      // city iterator
    
    str[0] << setw(12) << right << label;
    str[1] << setw(12) << right << "-----------------";
    
    size_t cityCount = cards.size();  // size of city vector
    size_t cityIndex = 2;               // city index is third line down
    // first display actual cards in city
    for ( cItr = cards.begin(); cItr != cards.end(); cItr++ ) {
        Card* cTmp = *cItr;
        str[cityIndex++] << "(" << cityID++ << ")"
        << setw(25) << left << cTmp->getCardName();
    }
    // display blanks if no more cities to chow
    for ( size_t i = cityIndex; i < totalCount; i++ ) {
        string tmp = " ";
        str[cityIndex++] << setw(25) << left << tmp;
    }
    
    for ( size_t i = 0; i < totalCount; i++ ) {
        out << str[i].str() << "\n";
    }
    return out.str();
}


string Menu::menuHands(vector<Player*> plyrs) {
    size_t playerCount = 1;
    const size_t totalCount = 13;        // number of slots for cards
    ostringstream out;
    ostringstream str[totalCount];
    vector<Player*>::iterator pItr;      // players iterator
    vector<Card*>::iterator   cItr;      // cards iterator
    str[2] << "----------------------------------------------------------------------------------------------------";
    // loop for as many times as there are players
    for ( pItr = plyrs.begin(); pItr != plyrs.end(); pItr++ ) {
        Player* pTmp = *pItr;
        str[0] << setw(12) << right << pTmp->getPlayerName()
               << setw(12) << left << " ";
        str[1] << " in " << setw(20) << left << pTmp->getPlayerLocStr();

        if ( playerCount < plyrs.size() )
            str[0] << " ";               // space, the final frontier...
            str[1] << " ";               // space, the final frontier...

        vector<Card*> hand = pTmp->getHand();
        size_t cardCount = hand.size();  // hand size of current players
        size_t cardIndex = 3;            // card index is third line down
        // first display actual cards in hand
        for ( cItr = hand.begin(); cItr != hand.end(); cItr++ ) {
            Card* cTmp = *cItr;
            string tmp = cTmp->ToString();
            str[cardIndex++] << setw(25) << left << tmp;
        }
        // display blanks if no more cards to chow
        for ( size_t i = cardIndex; i < totalCount; i++ ) {
            string tmp = " ";
            str[cardIndex++] << setw(25) << left << tmp;
        }

        playerCount++;    // player 1, player 2, etc...
    }
    for ( size_t i = 0; i < totalCount; i++ ) {
        out << str[i].str() << "\n";
    }
    return out.str();
}

string Menu::menuCommands(vector<string> commands) {
    const size_t totalCount = 10;
    const size_t slotCount = 5;  // number of slots for commands
    const size_t cubeCount = 4;  // number of slots for cubes
    ostringstream out;
    ostringstream str[slotCount];
    vector<string>::iterator cItr = commands.begin();      // commands iterator
    // two loops for two columns
    for ( size_t i = 0; i < 2; i++ ) {           // two loops for two columns

        for ( size_t j = 0; j < slotCount; j++ ) {
            if ( cItr == commands.end() ) {
                string tmp = " ";
                str[j] << setw(30) << left << tmp;
                continue;
            }
            else {
                string tmp = *cItr;
                str[j] << "(" << i * slotCount + j << ")" << setw(27) << left << tmp;
                cItr++;
            }
        }
    }
    string cubes[cubeCount] = { "black", "blue", "red", "yellow" };
    for ( size_t j = 0; j < cubeCount; j++ ) {
        str[j] << setw(8) << left << cubes[j]; 
    }
    for ( size_t j = 0; j < cubeCount; j++ ) {
        str[j] << setw(2) << left << mappedCubes[cubes[j]]; 
    }
    for ( size_t i = 0; i < slotCount; i++ ) {
        out << str[i].str() << "\n";
    }
    return out.str();
}

void Menu::showMenu(Player* p) {
    system("cls");
    ostringstream out;
    out << "====================================================================================================\n";
    out << menuCities(menuMap);
    out << "====================================================================================================\n";
    out << menuHands(players);
    out << "====================================================================================================\n";
    out << setw(12) << right << p->getPlayerName() << setw(45) << left << " select from the following (10 to Exit):" << "Cubes Remaining:\n";
    out << menuCommands(commands);
    cout << out.str();
}

//prints the hand passed to it -- using this in case of hand overflow
void Menu::discardMenu(vector<Card*>hand)
{
	int num;
	ostringstream out;
    out << "====================================================================================================\n";
	out << "You're holding too many cards.  Select one to discard or play (if event card chosen):\n";
	out << "----------------------------------------------------------------------------------------------------\n";

	num = hand.size();
	for(int i=0; i<num; i++)
	{
		out << "(" << i << ")" << hand[i]->getCardName() << "\n";
	}


	cout << out.str();
}

//Gives user options to play an event card between two consecutive epidemics
void Menu::doubleEpEventMenu(vector<Card*>hand, vector<int>index)
{
	int num;
	int i=0;
	ostringstream out;
    out << "====================================================================================================\n";
	out << "You've drawn two Epidemics! Choose an event card to play from below:\n";
	out << "----------------------------------------------------------------------------------------------------\n";

	num = index.size();
	for(i; i<num; i++)	//for each index representing an event card
	{
		out << "(" << i << ")" << hand[index[i]]->getCardName() << "\n";
	}

	out << "(" << i << ")No thanks\n";									//option to do nothing
	cout << out.str();
}