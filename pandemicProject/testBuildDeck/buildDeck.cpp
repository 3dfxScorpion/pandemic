#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<unordered_set>
#include "CityCard.h"
#include "EventCard.h"
#include "EpidemicCard.h"

#define unsigned int uint

using std::cout;
using std::string;
using std::vector;

static const uint CITYEVENT = 53; // city and event total count
static const uint EPICS = 6;      // epidemic card total

int main() {
    srand(time(0));
    uint totCards = CITYEVENT + EPICS;
    string allCards[CITYEVENT] = {
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
    while ( ids.size() < CITYEVENT ) {
        int num = rand() % CITYEVENT;
        ids.insert(num);
    }
/*  create indices for EPIDEMIC cards */
    int epics[EPICS] = {};
    for ( uint i = 0; i < EPICS; i++ ) {
        uint r = EPICS + (CITYEVENT / EPICS * i) + rand() % (CITYEVENT / EPICS);
        epics[i] = r;
    }
/* create Deck */
    uint ep = 0;
    iItr = ids.begin();
    vector<Card*> deck;
    for ( uint n = 0; n < totCards; n++ ) {
        uint id = (n - ep) + ep;
        Card* tmp;
        if ( id == epics[ep] ) {    // EPIDEMIC index found!
            tmp = new EpidemicCard(id, "EPIDEMIC");
            deck.push_back(tmp);    // add EPIDEMIC cards to Deck
            ++ep;
            continue;
        }
        if ( *iItr > 47 )           // EVENT card needed
            tmp = new EventCard(id, allCards[*iItr]);
        else                        // CITY  card needed
            tmp = new CityCard(id, allCards[*iItr]);
        deck.push_back(tmp);
        ++iItr;
    }
    printf("deck size: %i\n", deck.size());
    printf("deck created:\n");
    std::vector<Card*>::iterator cItr;
    for (cItr = deck.begin(); cItr != deck.end(); cItr++) {
        Card* p = *cItr;
        cout << p->ToString() << "\n";
    }
    return 0;
}
