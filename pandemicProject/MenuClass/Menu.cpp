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

void sayString(string s) {                           // testing function pointers
    cout << "You entered: " << s << "\n";
}

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
    vector<string> adjList;
    adjList = c->getAdjCity();          // adjList vector
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
        str[0] << setw(12) << right << "Player "
               << setw(12) << left << playerCount;
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
    string cubes[cubeCount] = { "Black", "Blue", "Red", "Yellow" };
    for ( size_t j = 0; j < cubeCount; j++ ) {
        str[j] << setw(25) << left << cubes[j]; 
    }
    for ( size_t j = 0; j < cubeCount; j++ ) {
        str[j] << setw(25) << left << j; 
    }
    for ( size_t i = 0; i < slotCount; i++ ) {
        out << str[i].str() << "\n";
    }
    return out.str();
}

void Menu::processMenu() {
    void (*say)(string);   // testing function pointers
    say = &sayString;      // testing function pointers
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

            showMenu();
            while( !( cin >> choice ) ) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.  Try again: ";
            }
            cin.ignore(numeric_limits<size_t>::max(), '\n');
            if ( choice < mappedFuncs.size() )
                mappedFuncs[choice](pMove);
            switch (choice) {
              case 0: say(mappedCmds[choice]); break;  // cout << "do_move_to_city(pMove); break;
              case 1: say(mappedCmds[choice]); break;  // cout << "do_charter_flight(pMove)\n"; break;
              case 2: say(mappedCmds[choice]); break;  // cout << "do_direct_flight(pMove)\n"; break;
              case 3: say(mappedCmds[choice]); break;  // cout << "do_shuttle_flight(pMove)\n"; break;
              case 4: say(mappedCmds[choice]); break;  // cout << "do_build_station(pMove)\n"; break;
              case 5: say(mappedCmds[choice]); break;  // cout << "do_treat_disease(pMove)\n"; break;
              case 6: say(mappedCmds[choice]); break;  // cout << "do_cure_disease(pMove)\n"; break;
              case 7: say(mappedCmds[choice]); break;  // cout << "do_share_knowledge(pMove)\n"; break;
              case 8: say(mappedCmds[choice]); break;  // cout << "player done, next player's turn...\n"; break;
              case 9: cout << "\nGoodbye...\n"; exit(0);
            }
            system("pause");
        } while (choice != NUM_COMMANDS - 1);
    }
}

void Menu::showMenu() {
    system("cls");
    ostringstream out;
    out << "====================================================================================================\n";
    out << menuCities(menuMap);
    out << "====================================================================================================\n";
    out << menuHands(players);
    out << "====================================================================================================\n";
    out << setw(50) << left << "Select from the following:" << "Cubes Remaining:\n";
    out << menuCommands(commands);
    cout << out.str();
}
