#ifndef DECK_H
#define DECK_H
#include<vector>
#include <fstream>
#include "CityCard.h"
#include "EventCard.h"
#include "EpidemicCard.h"

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

static const size_t CITIES = 48;  // city card total
static const size_t EVENTS = 5;   // event card total
static const size_t EPICS  = 6;   // epidemic card total

class Deck {
  public:
    Deck() {
        buildDeck(deck);
        size = deck.size();
    }
    Deck(string *aDeck) {
    }
    Deck(vector<Card*> _deck) : deck(_deck) {}
    int getSize() const { return size; }
    vector<Card*> getDeck() { return deck; }
    void setDeck(vector<Card*> d) { deck = d; }
    void buildDeck(vector<Card*>&);
    void shuffleDeck(vector<Card*>&);
    void dealCards();
    Card* takeCard();
    void ToString();
	void loadGame(ifstream &);
	void saveGame(ofstream &);
	bool isEventCard(Card*);
	vector<int> findEvents(vector<Card*>, vector<int>&eventIndexes);

  private:
    vector<Card*> deck;
    int size;
};

#endif
