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
using std::string;
using std::streamsize;
using std::numeric_limits;
using std::ostringstream;

const size_t PLAYERS = 2;

void do_move_to_city(PlayerMove* pm) {
    cout << "moving to city...\n";
}
void do_charter_flight(PlayerMove* pm) {
    cout << "charter flight to city...\n";
}
void do_direct_flight(PlayerMove* pm) {
    cout << "direct flight to city...\n";
    size_t num = 0, pick;
    Player* plyr = pm->getCurrentPlayer();
    vector<Card*> hand = plyr->getHand();
    for ( size_t i = 0; i < hand.size(); i++ )
        cout << hand[i]->ToString() << "\n";
    cout << "Where to? ";
    cin >> pick;
    vector<Card*>::iterator hItr;
    for ( hItr = hand.begin(); hItr != hand.end(); hItr++ ) {
        Card* tmp = *hItr;
        if ( pick == tmp->getID() ) {
            cout << num << " - Flying to " << tmp->getCardName() << "\n";
            plyr->removeCard(num);
        }
        ++num;
    }
}
void do_shuttle_flight(PlayerMove* pm) {
    cout << "shuttle flight to city...\n";
}
void do_build_station(PlayerMove* pm) {
    cout << "building station...\n";
}
void do_treat_disease(PlayerMove* pm) {
    cout << "treating disease...\n";
}
void do_cure_disease(PlayerMove* pm) {
    cout << "curing disease...\n";
}
void do_share_knowledge(PlayerMove* pm) {
    cout << "sharing knowledge...\n";
}

string do_main_screen(Map* m, Deck* d, vector<Player*> list) {
    system("cls");
    ostringstream out;
    out << "\n-- Welcome to Pandemic --\n";
    out << "\n" << m->infectedList() << "\n";
    out << "-----------------------------------------------------------------------------\n";
    return out.str();
}

string do_show_hands(vector<Player*> list) {
    ostringstream hands;
    ostringstream out[10];
    vector<Player*>::iterator pItr;    // players iterator
    vector<Card*>::iterator cItr;    // cards iterator
    for ( pItr = list.begin(); pItr != list.end(); pItr++ ) {
        size_t i = 0;
        Player* pTmp = *pItr;
        vector<Card*> hand = pTmp->getHand();
        for ( cItr = hand.begin(); cItr != hand.end(); cItr++ ) {
            Card* cTmp = *cItr;
            out[i++] << setw(24) << std::left << cTmp->ToString();
        }
    }
    for ( int i = 0; i < 10; i++ ) {
        hands << out[i].str() << "\n";
    }
    return hands.str();
}
void process_commands(Map* map, Deck* deck, vector<Player*> players) {
    string commands[] = {
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
    const int NUM_COMMANDS = sizeof(commands) / sizeof(commands[0]);
    int choice = NUM_COMMANDS - 1;
    PlayerMove* pMove = new PlayerMove();
    vector<Player*>::iterator pItr;
    for ( pItr = players.begin(); pItr != players.end(); pItr++ ) {
        pMove->setCurrentPlayer(*pItr);    // loop through both players
        do {
            cout << do_main_screen(map, deck, players);
    		    cout << do_show_hands(players);
    				cout << "Select from the following:\n";
            for (int i = 0; i < NUM_COMMANDS; i++) {
                cout << i << " " << commands[i] << "\n";
            }

            while( !( cin >> choice ) ) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.  Try again: ";
            }
            cin.ignore(numeric_limits<int>::max(), '\n');
            switch (choice) {
              case 0: do_move_to_city(pMove); break;
              case 1: do_charter_flight(pMove); break;
              case 2: do_direct_flight(pMove); break;
              case 3: do_shuttle_flight(pMove); break;
              case 4: do_build_station(pMove); break;
              case 5: do_treat_disease(pMove); break;
              case 6: do_cure_disease(pMove); break;
              case 7: do_share_knowledge(pMove); break;
              case 8: cout << "player done, next player's turn...\n";
              case 9: cout << "\nGoodbye...\n"; exit(0);
            }
            system("pause");
        } while (choice != NUM_COMMANDS - 1);
    }
}

int main() {
    bool DONE = false;
    static size_t whoTurn = 2;
    Map* theMap = new Map();
    if ( theMap->populateMap("Cities_test.txt") != 0 ) {
        cout << "Please make sure file is located in working directory...\n";
        return 0;
    }
    cout << theMap->infectedList() << "\n";
    Deck* theDeck = new Deck();
    PlayerMove* pMove = new PlayerMove();
    Player* p1 = new Player("plyr01", "programmer");
    Player* p2 = new Player("plyr02", "professor");
    vector<Player*> thePlayers;
    thePlayers.push_back(p1);
    thePlayers.push_back(p2);
    vector<Player*>::iterator pItr;
    for ( size_t i = 0; i < 4; i++ ) {
        for ( pItr = thePlayers.begin(); pItr != thePlayers.end(); pItr++ ) {
            Player* tmp = *pItr;
            tmp->addCard(theDeck->takeCard());
        }
    }
    pMove->setCurrentPlayer(p1);
    process_commands(theMap, theDeck, thePlayers);
}
