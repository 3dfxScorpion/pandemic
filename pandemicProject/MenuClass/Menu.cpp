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
    vector<City*> map = m.getWorldMap();
    vector<City*>::iterator cItr = map.begin();  //city iterator

    for ( size_t i = 0; i < 2; i++ ) {           // two loops for two columns
        str[0] << setw(17) << left  << "City:" << setw(7)
               << "Blk:" << setw(7) << "Blu:"  << setw(7)
               << "Red:" << setw(7) << "Yel:";
        if ( i == 0 )
            str[0] << " ";                      // space, the final frontier...
        str[1] << "=============================================";

        for ( size_t j = 2; j < 26; j++ ) {
            City* tmp = *cItr;
            str[j] << setw(17) << left << tmp->getCityName() << " "
                   << setw(6)  << tmp->getInfectedBlack()    << " "
                   << setw(6)  << tmp->getInfectedBlue()     << " "
                   << setw(6)  << tmp->getInfectedRed()      << " "
                   << setw(6)  << tmp->getInfectedYellow()   << " ";
            cItr++;
        }
    }

    for ( size_t i = 0; i < 25; i++ ) {
        out << str[i].str() << "\n";
    }

    return out.str();
}

string Menu::menuHands(vector<Player*> plyrs) {
    size_t playerCount = 1;
    const size_t totalCount = 12;            // number of slots for cards
    ostringstream out;
    ostringstream str[totalCount];
    vector<Player*>::iterator pItr;      // players iterator
    vector<Card*>::iterator   cItr;      // cards iterator
    str[1] << "==========================================================================================";
    // loop for as many times as there are players
    for ( pItr = plyrs.begin(); pItr != plyrs.end(); pItr++ ) {
        str[0] << setw(10) << right << "Player "
               << setw(14) << left << playerCount;
        if ( playerCount < plyrs.size() )
            str[0] << " ";               // space, the final frontier...

        Player* pTmp = *pItr;
        vector<Card*> hand = pTmp->getHand();
        size_t cardCount = hand.size();    // hand size of current players
        size_t cardIndex = 2;              // card index is third line down
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
    ostringstream out;
    ostringstream str[slotCount];
    vector<string>::iterator cItr = commands.begin();      // commands iterator
    // two loops for two columns
    for ( size_t i = 0; i < 2; i++ ) {           // two loops for two columns

        for ( size_t j = 0; j < slotCount; j++ ) {
            if ( cItr == commands.end() ) {
                string tmp = " ";
                str[j] << setw(25) << left << tmp;
                continue;
            }
            else {
                string tmp = *cItr;
                str[j] << "(" << i * slotCount + j << ")" << setw(25) << left << tmp;
                cItr++;
            }
        }
    }
    for ( size_t i = 0; i < slotCount; i++ ) {
        out << str[i].str() << "\n";
    }
    return out.str();
}

void Menu::processMenu() {
    const size_t NUM_COMMANDS = commands.size();
    size_t choice = NUM_COMMANDS - 1;
    PlayerMove* pMove = new PlayerMove();
    vector<Player*>::iterator pItr;
    for ( pItr = players.begin(); pItr != players.end(); pItr++ ) {
        pMove->setCurrentPlayer(*pItr);    // loop through both players
        do {
//            cout << "Select from the following:\n";
//            for ( size_t i = 0; i < NUM_COMMANDS; i++ ) {
//                cout << i << " " << commands[i] << "\n";
//            }

            while( !( cin >> choice ) ) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.  Try again: ";
            }
            cin.ignore(numeric_limits<size_t>::max(), '\n');
            switch (choice) {
              case 0: cout << "do_move_to_city(pMove)\n"; break;
              case 1: cout << "do_charter_flight(pMove)\n"; break;
              case 2: cout << "do_direct_flight(pMove)\n"; break;
              case 3: cout << "do_shuttle_flight(pMove)\n"; break;
              case 4: cout << "do_build_station(pMove)\n"; break;
              case 5: cout << "do_treat_disease(pMove)\n"; break;
              case 6: cout << "do_cure_disease(pMove)\n"; break;
              case 7: cout << "do_share_knowledge(pMove)\n"; break;
              case 8: cout << "player done, next player's turn...\n";
              case 9: cout << "\nGoodbye...\n"; exit(0);
            }
            system("pause");
            showMenu();
        } while (choice != NUM_COMMANDS - 1);
    }
}

void Menu::showMenu() {
    system("cls");
    ostringstream out;
    out << "Welcome to Pandemic\n";
    out << "==========================================================================================\n";
    out << menuCities(map);
    out << "==========================================================================================\n";
    out << menuHands(players);
    out << "==========================================================================================\n";
    out << "Select from the following:\n";
    out << menuCommands(commands);
    cout << out.str();
}
