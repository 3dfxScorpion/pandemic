#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>
#include "Menu.h"

using std::cout;
using std::left;
using std::right;
using std::setw;
using std::ostringstream;

string Menu::menuCities(Map& m) {
    ostringstream out;
    ostringstream str[26];
    vector<City*> map = m.getWorldMap();
    vector<City*>::iterator cItr = map.begin();  //city iterator

    for ( size_t i = 0; i < 2; i++ ) {           // two loops for two columns
        str[0] << setw(17) << left   << "City:" << setw(7)
                        << "Blk:" << setw(7) << "Blu:"   << setw(7)
                        << "Red:" << setw(7) << "Yel:";
        if ( i == 0 )
            str[0] << " ";                      // space, the final frontier...
        str[1] << "=============================================";

        for ( size_t j = 2; j < 26; j++ ) {
            City* tmp = *cItr;
            str[j] << setw(17) << left << tmp->getCityName() << " ";
            str[j] << setw(6)  << tmp->getInfectedBlack()    << " ";
            str[j] << setw(6)  << tmp->getInfectedBlue()     << " ";
            str[j] << setw(6)  << tmp->getInfectedRed()      << " ";
            str[j] << setw(6)  << tmp->getInfectedYellow()   << " ";
            cItr++;
        }
    }

    for ( size_t i = 0; i < 25; i++ ) {
        out << str[i].str() << "\n";
    }

    return out.str();
}

string Menu::menuHands(vector<Player*> plyrs) {
    int playerCount = 1;
    const int totalCount = 12;            // number of slots for cards
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
        int cardCount = hand.size();    // hand size of current players
        int cardIndex = 2;              // card index is third line down
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

