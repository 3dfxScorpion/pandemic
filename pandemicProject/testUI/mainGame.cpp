#include<iostream>
#include<vector>
#include "Deck.h"
#include "Player.h"

using std::cout;

int main() {
    Deck* theDeck = new Deck();
    theDeck->ToString();
    Player* p1 = new Player("plyr01", "programmer");
    Player* p2 = new Player("plyr02", "professor");
    vector<Player*> players;
    players.push_back(p1);
    players.push_back(p2);
    vector<Player*>::iterator pItr;
    for ( size_t i = 0; i < 2; i++ ) {
        for ( pItr = players.begin(); pItr != players.end(); pItr++ ) {
            p1->addCard(theDeck->takeCard());
            p2->addCard(theDeck->takeCard());
        }
    }
    theDeck->ToString();
}
