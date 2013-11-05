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
    Menu m1, m2;
    string filename = "Cities_test.txt";
    string cmds01[] = {
        "Move To City",
        "Charter Flight",
        "Direct Flight",
        "Shuttle Flight",
        "Build Station",
        "Treat Disease",
        "Cure Disease",
        "Share Knowledge",
        "Done with Actions",
        "Exit"
    };
    string cmds02[] = {
        "Sub Menu 01",
        "Sub Menu 02",
        "Sub Menu 03",
        "Sub Menu 04",
        "Sub Menu 05",
        "Sub Menu 06",
        "Exit"
    };
    vector<string> mainCommands ( cmds01, cmds01 + sizeof(cmds01) / sizeof(cmds01[0]) );
    vector<string> moveCommands ( cmds02, cmds02 + sizeof(cmds02) / sizeof(cmds02[0]) );
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
    m1.setMenuCommands(mainCommands);
    m1.showMenu();
    m1.processMenu();
/*
    m2.setMenuMap(theMap);
    m2.setMenuPlayers(thePlayers);
    m2.setMenuCommands(moveCommands);
    m2.showMenu();
*/
//    m2.processMenu();
    return 0;
}
