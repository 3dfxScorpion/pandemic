#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>
#include "Card.h"
#include "Deck.h"
#include "Map.h"
#include "Menu.h"
#include "Player.h"
#include "PlayerMove.h"

using std::cout;
using std::left;
using std::right;
using std::setw;
using std::ostringstream;

int main() {
    Menu m1;
    string filename = "Cities_test.txt";
    Map theMap;
    cout << "Opening " << filename << "\n";
    if ( theMap.populateMap(filename) != 0 ) {
        cout << "Please make sure file is located in working directory...\n";
        return 0;
    }
    Player* p1 = new Player("plyr01", "programmer");
    Player* p2 = new Player("plyr02", "professor");
    Player* p3 = new Player("plyr03", "gardener");
    Player* p4 = new Player("plyr04", "archetect");
    vector<Player*> thePlayers;
    thePlayers.push_back(p1);
    thePlayers.push_back(p2);
    thePlayers.push_back(p3);
    thePlayers.push_back(p4);
    vector<Player*>::iterator pItr;
    Deck* theDeck = new Deck();
    for ( size_t i = 0; i < 10; i++ ) {
        for ( pItr = thePlayers.begin(); pItr != thePlayers.end(); pItr++ ) {
            Player* tmp = *pItr;
            tmp->addCard(theDeck->takeCard());
        }
    }
    m1.setMenuMap(theMap);
    m1.setMenuPlayers(thePlayers);
    string theCities = m1.menuCities(theMap);
    string theHands  = m1.menuHands(thePlayers);
    cout << "Welcome to Pandemic\n"
         << "==========================================================================================\n"
         << theCities
         << "==========================================================================================\n"
         << theHands
         << "==========================================================================================\n";
    return 0;
}
