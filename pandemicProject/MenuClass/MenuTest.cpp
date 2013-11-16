#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>
#include "Card.h"
#include "Deck.h"
#include "City.h"
#include "Map.h"
#include "Menu.h"
#include "Player.h"
#include "PlayerMove.h"

using std::cout;
using std::left;
using std::right;
using std::setw;
using std::ostringstream;
// function declarations to be passed in to Menu
void do_move_to_city(PlayerMove* pm);
void do_charter_flight(PlayerMove* pm);
void do_direct_flight(PlayerMove* pm);
void do_shuttle_flight(PlayerMove* pm);
void do_build_station(PlayerMove* pm);
void do_treat_disease(PlayerMove* pm);
void do_cure_disease(PlayerMove* pm);
void do_share_knowledge(PlayerMove* pm);

int main() {
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
    // array of function pointers
		void(*fns[])(PlayerMove*) = {
        &do_move_to_city,
        &do_charter_flight,
        &do_direct_flight,
        &do_shuttle_flight,
        &do_build_station,
        &do_treat_disease,
        &do_cure_disease,
        &do_share_knowledge
    };
    // vector of function pointers
    typedef void (*menuFunctions)(PlayerMove *);
    vector<menuFunctions> mainFunctions ( fns, fns + sizeof(fns) / sizeof(fns[0]) );
    // map of function pointers
    map<int, void(*)(PlayerMove*)> cmdMap;
    for (size_t i = 0; i < mainFunctions.size(); i++ ) {
        cmdMap[i] = mainFunctions[i];
    }

    Map theMap;
    cout << "Opening " << filename << "\n";
    if ( theMap.populateMap(filename) != 0 ) {
        cout << "Please make sure file is located in working directory...\n";
        return 0;
    }
    City* start[4] = {
        theMap.locateCity("Istanbul"),
		    theMap.locateCity("San Francisco"),
        theMap.locateCity("Hong Kong"),
        theMap.locateCity("Atlanta")
    };
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
    // deal some cards to players
    for ( size_t i = 0; i < 7; i++ ) {
        for ( pItr = thePlayers.begin(); pItr != thePlayers.end(); pItr++ ) {
            Player* tmp = *pItr;
            tmp->addCard(theDeck->takeCard());
        }
    }
    // set player locations
    size_t idx = 0;
		for ( pItr = thePlayers.begin(); pItr != thePlayers.end(); pItr++ ) {
        Player* tmp = *pItr;
        tmp->setPlayerLocation(start[idx++]);
    }
    Menu* m1 = new Menu(theMap, thePlayers, mainCommands, mainFunctions);
    Menu* m2 = new Menu(theMap, thePlayers, moveCommands, mainFunctions);
    m1->processMenu();
//    m2->processMenu();
    return 0;
}
// these functions are accessible snce function pointer passed into Menu Class
void do_move_to_city(PlayerMove* pm) {
    cout << "moving to city...\n";
    cout << menuAdjCities(pm->getCurrentPlayer()->getPlayerLocation()) << "\n";
}

void do_charter_flight(PlayerMove* pm) {
    cout << "charter flight to city...\n";
    cout << menuAdjCities(pm->getCurrentPlayer()->getPlayerLocation()) << "\n";
}

void do_direct_flight(PlayerMove* pm) {
    cout << "direct flight to city...\n";
    cout << menuAdjCities(pm->getCurrentPlayer()->getPlayerLocation()) << "\n";
}

void do_shuttle_flight(PlayerMove* pm) {
    cout << "shuttle flight to city...\n";
    cout << menuAdjCities(pm->getCurrentPlayer()->getPlayerLocation()) << "\n";
}

void do_build_station(PlayerMove* pm) {
    cout << "building station...\n";
}

void do_treat_disease(PlayerMove* pm) {
    cout << "treat disease...\n";
}

void do_cure_disease(PlayerMove* pm) {
    cout << "cure disease...\n";
}

void do_share_knowledge(PlayerMove* pm) {
    cout << "share knowledge, are you crazy???\n";
}

