#ifndef IDECK
#define IDECK

#include <string>
#include <vector>
#include "ICard.h"
using namespace std;

static const size_t ICARDS = 48;


class IDeck
{
public:
    IDeck(){
        buildDeck(deck);
        size = deck.size();};
    void buildDeck(vector<ICard*>&);
    ICard* takeCard();
    ICard* takeBottomCard();
    void removeFirstDrawn(){discard.erase(discard.end()-1);}
    void shuffleDiscard();
    void loadGame(ifstream &);
    void saveGame(ofstream &);
    

private:
        vector<ICard*> deck;
        vector<ICard*> discard;
        int size;
};

#endif