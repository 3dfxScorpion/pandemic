#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<vector>
#include<unordered_set>
#include"Deck.h"

using std::cout;
using std::string;
using std::vector;

void Deck::buildFullDeck(vector<Card*>& tmpDeck) {
    srand(time(0));
    const size_t ceCards  = ( CITIES + EVENTS );
    const size_t totCards = ( ceCards + EPICS );
    string allCards[ceCards] = {
        "San Francisco", "Chicago", "Atlanta", "Montreal", "New York",
        "Washington", "London", "Madrid", "Paris", "Essen", "Milan",
        "St. Petersburg", "Los Angeles", "Mexico City", "Miami", "Bogota",
        "Lima", "Santiago", "Sao Paulo", "Buenos Aires", "Lagos", "Kinshasa",
        "Khartoum", "Johannesburg", "Algiers", "Cairo", "Istanbul", "Moscow",
        "Tehran", "Baghdad", "Riyadh", "Karachi", "Mumbai", "Delhi", "Kolkata",
        "Chennai", "Bangkok", "Jakarta", "Beijing", "Shanghai", "Hong Kong",
        "Ho Chi Minh City", "Seoul", "Taipei", "Manila", "Sydney", "Tokyo", "Osaka",
        "One Quiet Night", "Airlift", "Forecast",
        "Government Grant", "Resilient Population"
    };
/* generate unordered set of random indices for cards id's */
    std::unordered_set<int> ids;
    std::unordered_set<int>::iterator iItr;
    while ( ids.size() < ceCards ) {
        int num = rand() % ceCards;
        ids.insert(num);
    }
/*  create indices for EPIDEMIC cards */
    int epics[EPICS] = {};
    for ( size_t i = 0; i < EPICS; i++ ) {
        size_t r = EPICS + ( ceCards / EPICS * i ) +
                 rand() % ( ceCards / EPICS );
        epics[i] = r;
    }
/* create Deck */
    size_t ep = 0;
    iItr = ids.begin();
    for ( size_t n = 0; n < totCards; n++ ) {
        int id = (n - ep) + ep;
        Card* tmp;
        if ( id == epics[ep] ) {       // EPIDEMIC index found!
            tmp = new EpidemicCard(id, "EPIDEMIC");
            tmpDeck.push_back(tmp);    // add EPIDEMIC cards to Deck
            ++ep;
            continue;
        }
        if ( *iItr >= CITIES )         // EVENTS card needed
            tmp = new EventCard(id, allCards[*iItr]);
        else                           // CITY  card needed
            tmp = new CityCard(id, allCards[*iItr]);
        tmpDeck.push_back(tmp);
        ++iItr;
    }
}
/* generate unordered set of random indices for cards id's */
void Deck::shuffleDeck(vector<Card*>& oldDeck) {
    size_t n = oldDeck.size();
    size_t eCount = 0;
    Card* tmpArray[n];
    std::vector<Card*>::iterator odItr = oldDeck.begin();;
    for ( size_t i = 0; i < eCount; i++ ) {
        tmpArray[i] = *odItr++;
    }
    /* generate random indices for cards id's */
    std::unordered_set<int> ids;
    std::unordered_set<int>::iterator iItr;
    while ( ids.size() < n ) {
        int num = rand() % n;
        ids.insert(num);
    }
}
void Deck::dealCards() {
}
Card* Deck::takeCard() {
    if ( deck.empty() ) {
        cout << "deck empty\n";
        return NULL;
    }
    Card* tmp;
    tmp = deck.front();
    deck.erase(deck.begin());
    size--;
    return tmp;
}
void Deck::ToString() {
    size_t n = 0;
    std::vector<Card*>::iterator cItr;
    for (cItr = deck.begin(); cItr != deck.end(); cItr++) {
        n++;
        Card* p = *cItr;
        cout << std::setw(25) << std::left;
        cout << p->ToString();
        if ( n % 4 == 0 )
            cout << "\n";
    }
}
