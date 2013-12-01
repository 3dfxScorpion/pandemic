#ifndef IDECK
#define IDECK

#include <string>
#include <vector>
#include "ICard.h"
#include "dataManip.h"

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

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
    void removeLastAdded(){discard.pop_back();}
    void shuffleDiscard();
    void loadGame(ifstream &);
    void saveGame(ofstream &);
    
private:
        vector<ICard*> deck;
        vector<ICard*> discard;
        int size;
};

#endif