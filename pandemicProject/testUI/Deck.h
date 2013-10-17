#ifndef DECK_H
#define DECK_H
#include<vector>
#include "CityCard.h"
#include "EventCard.h"
#include "EpidemicCard.h"

using std::vector;

static const size_t CITIES = 48;  // city card total
static const size_t EVENTS = 5;   // event card total
static const size_t EPICS  = 6;   // epidemic card total

class Deck {
  public:
    Deck() {
        buildFullDeck(deck);
        size = deck.size();
    }
    int getSize() const { return size; }
    vector<Card*> getDeck() { return deck; }
    void buildFullDeck(vector<Card*>&);
    void shuffleDeck(vector<Card*>&);
    void dealCards();
    Card* takeCard();
    void ToString();
  private:
    vector<Card*> deck;
    int size;
};

#include "Deck.cpp"
#endif
